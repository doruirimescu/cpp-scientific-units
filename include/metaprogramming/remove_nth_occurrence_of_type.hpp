#pragma once
#include <metaprogramming/combine_variadics.hpp>
template <int N, typename... Args>
struct RemoveNthOccurrenceOfType;

/**
 * @brief  Removes the nth occurrence of a type from any variadic template.
 *
 * @tparam N : Nth occurrence to remove
 * @tparam ToRemove : Type to remove
 * @tparam Variadic : Type of variadic template
 * @tparam FirstArg :
 * @tparam RestArgs :
 */
template <int N, typename ToRemove, template <class...> typename Variadic, typename FirstArg, typename... RestArgs>
struct RemoveNthOccurrenceOfType<N, ToRemove, Variadic<FirstArg, RestArgs...>>
{
    typedef Variadic<FirstArg> first_type;
    typedef Variadic<RestArgs...> rest_types;

    static constexpr bool should_remove_first_arg = std::is_same<ToRemove, FirstArg>::value;
    static constexpr int n_updated = should_remove_first_arg ? N - 1 : N;

    typedef typename RemoveNthOccurrenceOfType<n_updated, ToRemove, rest_types>::type removed;

    typedef combineVariadics_t<first_type, removed> combined;

    typedef typename std::conditional_t<should_remove_first_arg && N == 1, rest_types, combined> type;
};

template <int N, typename ToRemove, template <class...> typename Variadic>
struct RemoveNthOccurrenceOfType<N, ToRemove, Variadic<>>
{
    typedef Variadic<> type;
};

template <int N, typename ToRemove, typename Variadic>
using removeNthOccurrenceOfType_t = typename RemoveNthOccurrenceOfType<N, ToRemove, Variadic>::type;
