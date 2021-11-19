/**
 *
 * Copyright (c) 2021 Doru Irimescu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file   remove_types.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <metaprogramming/remove_nth_occurrence_of_type.hpp>

template<typename...Args>
struct RemoveTypes
{
};

/**
 * @brief Removes the WhatToRemove types from the WhereToRemove
 *
 * @tparam WhatToRemove : Variadic with types which should be removed
 * @tparam WhereToRemove : Variadic with types from which the WhatToRemove should be removed
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
using removeTypes_t = typename RemoveTypes<ToRemove, WhereToRemove>::result;
