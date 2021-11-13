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
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file   variadic.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file contains THE variadic template class. It makes it possible to
 * write types such as Variadic<> or Variadic<int, float, double> while
 * making it easy to access the contained types by simply using
 * Variadic<int, float, double>::first_type
 * Variadic<int, float, double>::rest_type::first_type, etc
 */

#pragma once

template <typename... T>
struct Variadic;

namespace split
{  //Hide this beautiful helper, which allows us to conveniently
// access the types of any variadic struct
template <typename First, typename... Rest>
struct Split
{
    typedef First first_type;
    typedef Variadic<Rest...> rest_type;
};
}  // namespace split
template <typename... T>
struct Variadic : public split::Split<T...>
{
    constexpr static bool is_variadic = true;
    constexpr static unsigned int argument_count = sizeof...(T);
};

template <>
struct Variadic<>
{
    constexpr static bool is_variadic = true;
    constexpr static unsigned int argument_count = 0;
    typedef Variadic<> first_type;
    typedef Variadic<> rest_type;
};

/**
 * @brief  Gets the nth type of the variadic template
 *
 * @tparam N : Nth type to get
 * @tparam V : The variadic template
 */
template <int N, typename V>
struct getNthType
{
    static_assert(V::is_variadic == true, "V is not variadic");
    typedef typename getNthType<N-1, typename V::rest_type>::result result;
};

template<typename V>
struct getNthType<1, V>
{
    static_assert(V::is_variadic == true, "V is not variadic");
    typedef typename V::first_type result;
};

typedef Variadic<> EMPTY_VARIADIC;
