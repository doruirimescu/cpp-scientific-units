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

template<typename T>
using skipFirstType_t = typename SkipFirstType<T>::type;
