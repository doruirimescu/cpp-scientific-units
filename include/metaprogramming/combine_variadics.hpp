#pragma once

template <typename... Args>
struct combineVariadics;

template <template <class...> typename Container, typename... Args1, typename... Args2>
struct combineVariadics<Container<Args1...>, Container<Args2...>>
{
    typedef Container<Args1..., Args2...> type;
};

template <template <class...> typename Container, typename... Args1, typename... Args2>
struct combineVariadics<const Container<Args1...>, const Container<Args2...>>
{
    typedef const Container<Args1..., Args2...> type;
};

template <typename V1, typename V2>
using combineVariadics_t = typename combineVariadics<V1, V2>::type;
