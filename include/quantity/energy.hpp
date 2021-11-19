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
 * @file   energy.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <force.hpp>

using q_J =  decltype(1.0_q_N * 1.0_q_m);
using q_kJ = decltype(1.0_q_kilo * 1.0_q_N * 1.0_q_m);
using q_MJ = decltype(1.0_q_mega * 1.0_q_N * 1.0_q_m);
using q_GJ = decltype(1.0_q_giga * 1.0_q_N * 1.0_q_m);

constexpr q_J operator"" _q_J(long double v)
{
    return q_J{static_cast<double>(v)};
}

constexpr q_kJ operator"" _q_kJ(long double v)
{
    return q_kJ{static_cast<double>(v)};
}

constexpr q_MJ operator"" _q_MJ(long double v)
{
    return q_MJ{static_cast<double>(v)};
}

constexpr q_GJ operator"" _q_GJ(long double v)
{
    return q_GJ{static_cast<double>(v)};
}
