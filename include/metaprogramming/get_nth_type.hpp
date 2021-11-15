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
 * @file   get_nth_type.hpp
 * @author Doru Irimescu
 *
 */
#pragma once

/**
 * @brief  Gets the nth type of any variadic template
 *
 * @tparam N : Nth type to get
 * @tparam Variadic : The variadic template
 */

template <int N, typename... Args>
struct getNthType;

template <int N, template <class...> typename Variadic, typename FirstArg, typename... RestArgs>
struct getNthType<N, Variadic<FirstArg, RestArgs...>>
{
    typedef Variadic<RestArgs...> rest_args;
    typedef typename getNthType<N - 1, rest_args >::result result;
};

template <template <class...> typename Variadic, typename FirstArg, typename... RestArgs>
struct getNthType<1, Variadic<FirstArg, RestArgs...>>
{
    typedef FirstArg result;
};

template <int N, template <class...> typename Variadic>
struct getNthType<N, Variadic<>>
{
    typedef Variadic<> result;
};

template <int N, typename Variadic>
using getNthType_t = typename getNthType<N, Variadic>::result;
