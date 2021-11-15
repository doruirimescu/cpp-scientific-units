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
 * @file   combine_variadics.hpp
 * @author Doru Irimescu
 *
 */
#pragma once

template <typename... Args>
struct combineVariadics;

template <template <class...> typename Variadic, typename... Args1, typename... Args2>
struct combineVariadics<Variadic<Args1...>, Variadic<Args2...>>
{
    typedef Variadic<Args1..., Args2...> type;
};

template <template <class...> typename Variadic, typename... Args1, typename... Args2>
struct combineVariadics<const Variadic<Args1...>, const Variadic<Args2...>>
{
    typedef const Variadic<Args1..., Args2...> type;
};

template <typename V1, typename V2>
using combineVariadics_t = typename combineVariadics<V1, V2>::type;
