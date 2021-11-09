#pragma once

template <typename... LeftArgs, typename RightArg, typename... RightArgs>
constexpr decltype(auto) calculateTypeListIntersection(const TypeList<LeftArgs...>& left_list,
                                                       const TypeList<RightArg, RightArgs...>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    const auto selected_list = std::conditional_t<is_first_arg_type_in_t2, TypeList<RightArg>, TypeList<>>{};
    const auto returned = calculateTypeListIntersection(left_list, TypeList<RightArgs...>{});
    return selected_list + returned;
}

template <typename... LeftArgs, typename RightArg>
constexpr decltype(auto) calculateTypeListIntersection(const TypeList<LeftArgs...>& left_list,
                                                       const TypeList<RightArg>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    const auto selected_list = std::conditional_t<is_first_arg_type_in_t2, TypeList<RightArg>, TypeList<>>{};
    return selected_list;
}
