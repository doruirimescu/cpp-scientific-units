#pragma once
#include <metaprogramming/combine_variadics.hpp>
template <int N, typename... Args>
struct RemoveNthOccurrenceOfType;

/**
 * @brief  Removes the nth occurrence of a type from any variadic template.
 *
 * @tparam N : Nth occurrence to remove
 * @tparam ToRemove : Type to remove
 * @tparam V : Type of variadic template
 * @tparam FirstArg :
 * @tparam RestArgs :
 */
template <int N, typename ToRemove, template <class...> typename V, typename FirstArg, typename... RestArgs>
struct RemoveNthOccurrenceOfType<N, ToRemove, V<FirstArg, RestArgs...>>
{
    typedef V<FirstArg> first_type;
    typedef V<RestArgs...> rest_type;

    static constexpr bool should_remove_first_arg = std::is_same<ToRemove, FirstArg>::value;
    static constexpr int n_updated = should_remove_first_arg ? N - 1 : N;

    typedef typename RemoveNthOccurrenceOfType<n_updated, ToRemove, rest_type>::type removed;

    typedef combineVariadics_t<first_type, removed> combined;

    typedef typename std::conditional_t<should_remove_first_arg && N == 1, rest_type, combined> type;
};

template <int N, typename ToRemove, template <class...> typename V>
struct RemoveNthOccurrenceOfType<N, ToRemove, V<>>
{
    typedef V<> type;
};

template <int N, typename ToRemove, typename V>
using removeNthOccurrenceOfType_t = typename RemoveNthOccurrenceOfType<N, ToRemove, V>::type;
