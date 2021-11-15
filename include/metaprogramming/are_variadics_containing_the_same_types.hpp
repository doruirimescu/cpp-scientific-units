#pragma once
#include <metaprogramming/is_type_in_variadic.hpp>

template <typename... T>
struct AreVariadicsContainingTheSameTypes;

template <template <class...> class Variadic, typename... LeftArgs, typename RightArg, typename... RightArgs>
struct AreVariadicsContainingTheSameTypes<Variadic<LeftArgs...>, Variadic<RightArg, RightArgs...>>
{
    static constexpr bool is_right_arg_in_left_list = IsTypeInVariadic<RightArg, Variadic<LeftArgs...>>::value;

    static constexpr bool value = is_right_arg_in_left_list ? AreVariadicsContainingTheSameTypes<Variadic<LeftArgs...>, Variadic<RightArgs...> >::value : false;
};

template <template <class...> class Variadic, typename RightArg, typename... LeftArgs>
struct AreVariadicsContainingTheSameTypes<Variadic<LeftArgs...>, Variadic<RightArg>>
{
    static constexpr bool value = IsTypeInVariadic<RightArg, Variadic<LeftArgs...>>::value;
};

template <template <class...> class Variadic, typename... LeftArgs>
struct AreVariadicsContainingTheSameTypes<Variadic<LeftArgs...>, Variadic<>>
{
    static constexpr bool value = false;
};
