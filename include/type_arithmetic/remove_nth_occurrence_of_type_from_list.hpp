#pragma once
template <typename... ThisArgs>
struct TypeList;

template <int N, typename ToRemove, typename FirstArg, typename... Args>
constexpr decltype(auto) removeNthOccurenceOfTypeFromTypeList(
    const ToRemove& type_to_remove, const TypeList<FirstArg, Args...>& tuple_to_remove_from)
{
    const auto selected_list = std::conditional_t < std::is_same<FirstArg, ToRemove>::value && N == 1, const TypeList<>,
               const TypeList<FirstArg> > {};
    const auto n_update = std::is_same<FirstArg, ToRemove>::value ? N - 1 : N;
    const auto returned = removeNthOccurenceOfTypeFromTypeList<n_update>(type_to_remove, TypeList<Args...>{});
    return selected_list + returned;
}

template <int N, typename ToRemove, typename FirstArg>
constexpr decltype(auto) removeNthOccurenceOfTypeFromTypeList(const ToRemove& type_to_remove,
                                                                                     const TypeList<FirstArg>& fa)
{
    const auto selected_list = std::conditional_t < std::is_same<FirstArg, ToRemove>::value && N == 1, const TypeList<>,
               const TypeList<FirstArg> > {};
    return selected_list;
}
