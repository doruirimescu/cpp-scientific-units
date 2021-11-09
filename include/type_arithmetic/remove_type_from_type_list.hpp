#pragma once

template <typename ToRemove, typename FirstArg, typename... RestOfArgs>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<FirstArg, RestOfArgs...>& list_to_remove_from)
{
    const auto selected_list =
        std::conditional_t<std::is_same<FirstArg, ToRemove>::value, TypeList<>, TypeList<FirstArg>>{};
    auto returned = removeTypeFromTypeList<ToRemove>(TypeList<RestOfArgs...>{});
    return selected_list + returned;
}

template <typename ToRemove, typename FirstArg>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<FirstArg>& fa)
{
    const auto selected_list =
        std::conditional_t<std::is_same<FirstArg, ToRemove>::value, const TypeList<>, const TypeList<FirstArg>>{};
    return selected_list;
}

template<typename ToRemove>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<>&)
{
    return TypeList<>{};
}
