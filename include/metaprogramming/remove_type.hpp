#pragma once
#include <metaprogramming/combine_variadics.hpp>
template <typename... Args>
struct RemoveType;

template <typename V1, typename V2>
using removeType_t = typename RemoveType<V1, V2>::type;

template <typename ToRemove, template <class...> typename V, typename FirstArg, typename... RestArgs>
struct RemoveType<ToRemove, V<FirstArg, RestArgs...>>
{
    typedef V<FirstArg> first_type;
    typedef V<RestArgs...> rest_type;

    static constexpr bool are_same = std::is_same<ToRemove, FirstArg>::value;
    typedef removeType_t<ToRemove, rest_type> removed;
    typedef combineVariadics_t<first_type, removed> combined;
    typedef std::conditional_t<are_same, removed, combined> type;
};

template <typename ToRemove, template <class...> typename V>
struct RemoveType<ToRemove, V<>>
{
    typedef V<> type;
};
