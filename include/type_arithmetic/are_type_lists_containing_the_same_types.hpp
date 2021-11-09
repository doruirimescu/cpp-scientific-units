#pragma once

template <typename... LeftArgs>
constexpr bool areTypeListsContainingSameTypes(const TypeList<LeftArgs...>& left_list,
                                               const TypeList<>& right_list)
{
    return false;
}

template <typename... LeftArgs, typename RightArg, typename... RightArgs>
constexpr bool areTypeListsContainingSameTypes(const TypeList<LeftArgs...>& left_list,
                                               const TypeList<RightArg, RightArgs...>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    if (!is_first_arg_type_in_t2)
    {
        return false;
    }
    const bool returned = areTypeListsContainingSameTypes(left_list, TypeList<RightArgs...>{});
    return returned;
}

template <typename... LeftArgs, typename RightArg>
constexpr bool areTypeListsContainingSameTypes(const TypeList<LeftArgs...>& left_list,
                                               const TypeList<RightArg>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    return is_first_arg_type_in_t2;
}
