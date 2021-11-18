#pragma once

template<typename...T>
struct SkipFirstType;

template<template<class...> typename Variadic, typename First, typename...Rest>
struct SkipFirstType<Variadic<First, Rest...>>
{
    typedef Variadic<Rest...> type;
};

template<template<class...> typename Variadic>
struct SkipFirstType<Variadic<>>
{
    typedef Variadic<> type;
};

/*************************************************/
template<typename...T>
struct GetFirstType;

template<template<class...> typename Variadic, typename First, typename...Rest>
struct GetFirstType<Variadic<First, Rest...>>
{
    typedef Variadic<First> type;
};

template<template<class...> typename Variadic>
struct GetFirstType<Variadic<>>
{
    typedef Variadic<> type;
};

template<typename T>
using getFirstType_t = typename GetFirstType<T>::type;
template<typename T>
using skipFirstType_t = typename SkipFirstType<T>::type;
