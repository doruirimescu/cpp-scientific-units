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
 * copies or substantial portions of the Software.
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
#include <remove_nth_occurrence_of_type_from_list.hpp>
#include <remove_type_list_from_type_list.hpp>
#include <remove_type_from_type_list.hpp>
#include <is_type_in_type_list.hpp>
#include <are_type_lists_containing_the_same_types.hpp>
#include <calculate_type_list_intersection.hpp>
#include <calculate_type_by_id.hpp>
#include <metaprogramming.hpp>

template <typename... ThisArgs>
struct TypeList
{
    /**
     * @brief Returns a new TypeList containing the types of the current TypeList and the types of the given TypeList.
     *
     */
    template <typename... OtherArgs>
    constexpr TypeList<ThisArgs..., OtherArgs...> operator+(const TypeList<OtherArgs...>& other) const
    {
        return TypeList<ThisArgs..., OtherArgs...>{};
    }

    /**
     * @brief  Removes from the current type list the types of the given type list, one by one,
     * first occurrence.
     *
     */
    template <typename... OtherArgs>
    constexpr decltype(auto) operator-(const TypeList<OtherArgs...>& other) const
    {
        return removeTypeListFromTypeList(*this, other);
    }

    /**
     * @brief Removes the intersection with other from current type list. Same as subtraction
     *
     */
    template <typename... OtherArgs>
    constexpr decltype(auto) operator/(const TypeList<OtherArgs...>& other) const
    {
        return *this - this->calculateIntersection(other);
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
            return areTypeListsContainingSameTypes(*this, other) and areTypeListsContainingSameTypes(other, *this);
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
        return isTypeInTypeList<T>(*this);
    }
    constexpr bool hasType() const
    {
        return (*this) == TypeList<>{};
    }

    constexpr std::size_t getSize() const
    {
        return sizeof...(ThisArgs);
    }

    template <typename... OtherArgs>
    constexpr decltype(auto) calculateIntersection(const TypeList<OtherArgs...>& other) const
    {
        return calculateTypeListIntersection(*this, other);
    }

    template <typename T>
    constexpr decltype(auto) removeType() const
    {
        return removeTypeFromTypeList<T>(*this);
    }
    constexpr decltype(auto) removeType() const
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


//! This works only for types which have a static int id and a double value
template <typename...LeftArgs, typename...RightArgs>
constexpr double qConvertLists(const TypeList<LeftArgs...>& left, const TypeList<RightArgs...>& right)
{
    static_assert(left.getSize() == right.getSize(), "Conversion cannot be performed, sizes do not match");
    return convertLists(left, right);
}

template <typename LeftArg, typename... LeftArgs, typename RightArg, typename... RightArgs>
constexpr double convertLists(const TypeList<LeftArg, LeftArgs...>& left, const TypeList<RightArg, RightArgs...>& right)
{
    static_assert(LeftArg::id, "Type LeftArg does not have an id");
    auto type = right.template getTypeById<LeftArg::id>();
    using returned_type = decltype(type);

    //If the returned_type is different than TypeList<>, it will assert as true and continue
    static_assert(std::is_same<returned_type, TypeList<>>::value == false, "Conversion cannot be performed");

    const auto right_with_type_removed = removeNthOccurenceOfTypeFromTypeList<1, returned_type>(right);

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

//TODO: find a way to return a type from a function
//Start with a struct using the type of some argument
