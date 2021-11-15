#pragma once
#include <remove_nth_occurrence_of_type.hpp>

template<typename...Args>
struct RemoveTypes
{
};

/**
 * @brief Removes the WhatToRemove types from the WhereToRemove
 *
 * @tparam WhatToRemove : Types which should be removed
 * @tparam WhereToRemove : Types from which the WhatToRemove should be removed
 * @tparam FirstArg :
 * @tparam Args :
 */
template<template<class...> typename WhatToRemove, typename WhereToRemove, typename FirstArg, typename...Args>
struct RemoveTypes<WhatToRemove<FirstArg, Args...>, WhereToRemove>
{
    typedef removeNthOccurrenceOfType_t<1, FirstArg, WhereToRemove> removed;
    typedef typename RemoveTypes<WhatToRemove<Args...>, removed>::result result;
};

template<template<class...> typename WhatToRemove, typename WhereToRemove>
struct RemoveTypes<WhatToRemove<>, WhereToRemove>
{
    typedef WhereToRemove result;
};

template <typename ToRemove, typename WhereToRemove>
using RemoveTypes_t = typename RemoveTypes<ToRemove, WhereToRemove>::result;
