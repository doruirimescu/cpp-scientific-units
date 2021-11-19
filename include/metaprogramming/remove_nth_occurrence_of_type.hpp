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
 * @file   remove_nth_occurrence_of_type.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <metaprogramming/combine_variadics.hpp>
#include <type_traits>
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
