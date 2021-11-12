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
 * @file   force.hpp
 * @author Doru Irimescu
 * @date   09-11-2021
 *
 */

#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>

namespace q_force
{
struct N : public prefix::none
{
};
}  // namespace q_force

// Force types
using q_N = Quantity<TypeList<q_mass::kg, q_length::m>, TypeList<q_time::s, q_time::s>>;

// Force user-defined literals
constexpr q_N operator"" _q_N(long double v)
{
    return q_N{static_cast<double>(v)};
}

// Force conversions
template <typename Mass, typename Length, typename Time1, typename Time2>
constexpr q_N to_q_N(const Quantity<TypeList<Mass, Length>, TypeList<Time1, Time2>>& v)
{
    const double mass_kg = to_q_mass<q_mass::kg>(Quantity<TypeList<Mass>, TypeList<>>{1}).value;
    const double length_m = static_cast<q_m>(Quantity<TypeList<Length>, TypeList<>>{1}).value;
    const double time2_s = static_cast<q_s>(Quantity<TypeList<Time1>, TypeList<>>{1}).value;
    const double time1_s = static_cast<q_s>(Quantity<TypeList<Time2>, TypeList<>>{1}).value;

    return q_N{v.value * mass_kg * length_m / (time1_s * time2_s)};
}
