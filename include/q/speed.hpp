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
 * @file   speed.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <quantity/quantity.hpp>
#include <type_list/type_list.hpp>
#include <unit/prefix.hpp>
#include <q/time.hpp>
#include <q/length.hpp>
#include <q/scalar.hpp>

using q_mps = decltype(1.0_q_m / 1.0_q_s);
using q_kmph = decltype(1.0_q_km / 1.0_q_hour);

constexpr q_mps operator"" _q_mps(long double v)
{
    return q_mps{static_cast<double>(v)};
}
constexpr q_kmph operator"" _q_kmph(long double v)
{
    return q_kmph{static_cast<double>(v)};
}
