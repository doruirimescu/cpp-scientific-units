#pragma once

//Forward declarations.
template <typename... ThisArgs>
struct TypeList;

template <int id, typename RightArg, typename... RightArgs>
constexpr decltype(auto) calculateTypeById(const TypeList<RightArg, RightArgs...>& list)
{
    static_assert(RightArg::id, "Type RightArg does not have an id");
    const auto selected_list =
        std::conditional_t<RightArg::id == id, RightArg, decltype(calculateTypeById<id>(TypeList<RightArgs...>{}))>{};
    return selected_list;
}

template <int id, typename RightArg>
constexpr decltype(auto) calculateTypeById(const TypeList<RightArg>& list)
{
    static_assert(RightArg::id, "Type RightArg does not have an id");
    auto selected_list = std::conditional_t<RightArg::id == id, RightArg, TypeList<>>{};
    return selected_list;
}
