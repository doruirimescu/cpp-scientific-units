#pragma once
#include <remove_nth_occurrence_of_type_from_list.hpp>
#include <remove_type_list_from_type_list.hpp>
#include <remove_type_from_type_list.hpp>
#include <is_type_in_type_list.hpp>
#include <are_type_lists_containing_the_same_types.hpp>
#include <calculate_type_list_intersection.hpp>
template <typename... ThisArgs>
struct TypeList
{
    template <typename... OtherArgs>
    constexpr TypeList<ThisArgs..., OtherArgs...> operator+(const TypeList<OtherArgs...>& other) const
    {
        return TypeList<ThisArgs..., OtherArgs...>{};
    }

    template <typename... OtherArgs>
    constexpr decltype(auto) operator-(const TypeList<OtherArgs...>& other) const
    {
        return removeTypeListFromTypeList(*this, other);
    }

    template <typename... OtherArgs>
    constexpr decltype(auto) operator/(const TypeList<OtherArgs...>& other) const
    {
        return *this - this->calculateIntersection(other);
    }

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
};

#define TYPELIST(...) TypeList<__VA_ARGS__>{}
