/**
 *
 * Copyright (c) 2021 Doru Irimescu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file   type_list.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file defines a TypeList.
 */

#pragma once
#include <remove_nth_occurrence_of_type.hpp>
#include <calculate_type_list_intersection.hpp>
#include <calculate_type_by_id.hpp>
#include <metaprogramming/remove_types.hpp>
#include <metaprogramming/remove_type.hpp>
#include <metaprogramming/is_type_in_variadic.hpp>
#include <metaprogramming/are_variadics_containing_the_same_types.hpp>
#include <metaprogramming/skip_first_type.hpp>
#include <type_traits>
template <typename... ThisArgs>
struct TypeList
{
    constexpr static unsigned int argument_count = sizeof...(ThisArgs);

    /**
     * @brief Returns a new TypeList containing the types of the current TypeList and the types of the given TypeList.
     *
     */
    template <typename... OtherArgs>
    constexpr TypeList<ThisArgs..., OtherArgs...> operator+(const TypeList<OtherArgs...>& other) const
    {
        return TypeList<ThisArgs..., OtherArgs...>{};
    }

    constexpr decltype(auto) skipFirstType() const
    {
        return skipFirstType_t<TypeList<ThisArgs...>>{};
    }

    constexpr decltype(auto) getFirstType() const
    {
        return getFirstType_t<TypeList<ThisArgs...>>{};
    }

    /**
     * @brief  Removes from the current type list the types of the given type list, one by one,
     * first occurrence.
     *
     */
    template <typename... OtherArgs>
    constexpr decltype(auto) operator-(const TypeList<OtherArgs...>& other) const
    {
        return removeTypes_t<TypeList<OtherArgs...>, TypeList<ThisArgs...>>{};
    }

    /**
     * @brief Removes the intersection with other from current type list. Same as subtraction
     *
     */
    template <typename... OtherArgs>
    constexpr decltype(auto) operator/(const TypeList<OtherArgs...>& other) const
    {
        return removeTypes_t<TypeList<OtherArgs...>, TypeList<ThisArgs...>>{};
    }

    /**
     * @brief  Order does not matter for equality
     *
     */
    template <typename... OtherArgs>
    constexpr bool operator==(const TypeList<OtherArgs...>& other) const
    {
        const bool are_sizes_equal = this->getSize() == other.getSize();
        if ((are_sizes_equal and getSize() == 0))
        {
            return true;
        }
        if (!are_sizes_equal)
        {
            return false;
        }
        else
        {
            const bool is_this_in_other = AreVariadicsContainingTheSameTypes<TypeList<ThisArgs...>, TypeList<OtherArgs...>>::value;
            const bool is_other_in_this = AreVariadicsContainingTheSameTypes<TypeList<OtherArgs...>, TypeList<ThisArgs...>>::value;
            return is_this_in_other and is_other_in_this;
        }
    }

    template <typename... OtherArgs>
    constexpr bool operator!=(const TypeList<OtherArgs...>& other) const
    {
        return not(*this == other);
    }

    template <typename T>
    constexpr bool hasType() const
    {
        return IsTypeInVariadic<T, TypeList<ThisArgs...>>::value;
    }
    constexpr bool hasType() const
    {
        return (*this) == TypeList<>{};
    }

    constexpr std::size_t getSize() const
    {
        return this->argument_count;
    }

    template <typename... OtherArgs>
    constexpr decltype(auto) calculateIntersection(const TypeList<OtherArgs...>& other) const
    {
        return calculateTypeListIntersection(*this, other);
    }

    template <typename T>
    constexpr decltype(auto) RemoveType() const
    {
        return removeType_t<T, TypeList<ThisArgs...>>{};
    }
    constexpr decltype(auto) RemoveType() const
    {
        return (*this);
    }

    template <int id>
    constexpr decltype(auto) getTypeById() const
    {
        return calculateTypeById<id>(*this);
    }
};

//! TYPELIST(T1) is same as TypeList<T1>{}, but is more readable. Using both here for testing.
#define TYPELIST(...)                                                                                                  \
    TypeList<__VA_ARGS__>                                                                                              \
    {                                                                                                                  \
    }
template <typename... ThisArgs>
struct Numerator: TypeList<ThisArgs...>
{
};

template <typename... ThisArgs>
struct Denominator: TypeList<ThisArgs...>
{
};

//! This works only for types which have a static int id and a double value
template <typename...LeftArgs, typename...RightArgs>
constexpr double qConvertLists(const TypeList<LeftArgs...>& left, const TypeList<RightArgs...>& right)
{
    static_assert(left.getSize() == right.getSize(), "Conversion cannot be performed, sizes do not match");
    return convertLists(left, right);
}

template <typename LeftArg, typename... LeftArgs, typename... RightArgs>
constexpr double convertLists(const TypeList<LeftArg, LeftArgs...>& left, const TypeList<RightArgs...>& right)
{
    static_assert(LeftArg::id, "Type LeftArg does not have an id");
    auto type = right.template getTypeById<LeftArg::id>();
    using returned_type = decltype(type);

    //If the returned_type is different than TypeList<>, it will assert as true and continue
    static_assert(std::is_same<returned_type, TypeList<>>::value == false, "Conversion cannot be performed");

    const removeNthOccurrenceOfType_t<1, returned_type, TypeList<RightArgs...>> right_with_type_removed{};

    const double converted_value = LeftArg::value / returned_type::value;

    return converted_value * convertLists(TypeList<LeftArgs...>{}, right_with_type_removed);
}

template <typename... LeftArgs>
constexpr double convertLists(const TypeList<LeftArgs...>& left, const TypeList<>& right)
{
    return 1.0;
}
template <typename... RightArgs>
constexpr double convertLists(const TypeList<>& left, const TypeList<RightArgs...>& right)
{
    return 1.0;
}

constexpr double convertLists(const TypeList<>& left, const TypeList<>& right)
{
    return 1.0;
}
