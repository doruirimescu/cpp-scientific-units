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
 * @file   remove_type.hpp
 * @author Doru Irimescu
 *
 */

#pragma once
#include <metaprogramming/combine_variadics.hpp>
template <typename... Args>
struct RemoveType;

template <typename V1, typename V2>
using removeType_t = typename RemoveType<V1, V2>::type;

/**
 * @brief  Removes all the occurrences of ToRemove type from a variadic template
 *
 * @tparam ToRemove : Type to remove
 * @tparam WhereToRemove : Variadic with types from which the WhatToRemove should be removed
 */
template <typename ToRemove, template <class...> typename WhereToRemove, typename FirstArg, typename... RestArgs>
struct RemoveType<ToRemove, WhereToRemove<FirstArg, RestArgs...>>
{
    typedef WhereToRemove<FirstArg> first_type;
    typedef WhereToRemove<RestArgs...> rest_types;

    static constexpr bool are_same = std::is_same<ToRemove, FirstArg>::value;
    typedef removeType_t<ToRemove, rest_types> removed;
    typedef combineVariadics_t<first_type, removed> combined;
    typedef std::conditional_t<are_same, removed, combined> type;
};

template <typename ToRemove, template <class...> typename WhereToRemove>
struct RemoveType<ToRemove, WhereToRemove<>>
{
    typedef WhereToRemove<> type;
};
