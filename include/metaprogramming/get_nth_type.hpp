#pragma once

/**
 * @brief  Gets the nth type of any variadic template
 *
 * @tparam N : Nth type to get
 * @tparam V : The variadic template
 */

template <int N, typename... Args>
struct getNthType;

template <int N, template <class...> typename V, typename FirstArg, typename... RestArgs>
struct getNthType<N, V<FirstArg, RestArgs...>>
{
    typedef V<RestArgs...> rest_args;
    typedef typename getNthType<N - 1, rest_args >::result result;
};

template <template <class...> typename V, typename FirstArg, typename... RestArgs>
struct getNthType<1, V<FirstArg, RestArgs...>>
{
    typedef FirstArg result;
};

template <int N, template <class...> typename V>
struct getNthType<N, V<>>
{
    typedef V<> result;
};

template <int N, typename V>
using getNthType_t = typename getNthType<N, V>::result;
