#pragma once
#include "remove_nth_occurrence_of_type_from_list.hpp"

template <typename... LeftArgs, typename RightFirst, typename... RightArgs>
constexpr decltype(auto) removeTypeListFromTypeList(const TypeList<LeftArgs...>& left_list,
                                                    const TypeList<RightFirst, RightArgs...>& right_list)
{
    const auto new_left = removeNthOccurenceOfTypeFromTypeList<1>(RightFirst{}, left_list);
    return removeTypeListFromTypeList(new_left, TypeList<RightArgs...>{});
}

template <typename... LeftArgs, typename RightFirst>
constexpr decltype(auto) removeTypeListFromTypeList(const TypeList<LeftArgs...>& left_list,
                                                    const TypeList<RightFirst>& right_list)
{
    return removeNthOccurenceOfTypeFromTypeList<1>(RightFirst{}, left_list);
}

template<typename...T>
constexpr decltype(auto) removeTypeListFromTypeList(const TypeList<T...>& left_list,
                                                    const TypeList<>& right_list)
{
    return left_list;
}

template<typename T>
constexpr decltype(auto) removeTypeListFromTypeList(const TypeList<>& left_list,
                                                    const TypeList<T>& right_list)
{
    return left_list;
}

constexpr decltype(auto) removeTypeListFromTypeList(const TypeList<>& left_list,
                                                    const TypeList<>& right_list)
{
    return left_list;
}
