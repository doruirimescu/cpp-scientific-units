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
 * @file   unit.hpp
 * @author Doru Irimescu
 *
 */

#pragma once
#include <unit/id.hpp>
#include <math.h>
//Unit takes a prefix and an id
template<int Prefix, typename ScalingToStandard, Q_ID ID>
struct Unit
{
    static constexpr double value = pow(10, Prefix) * ScalingToStandard::value;
    static constexpr int id = ID;
};

//operator * for scalar
template<int Prefix1, int Prefix2, typename ScalingToStandard>
constexpr Unit<Prefix1 + Prefix2, ScalingToStandard, SCALAR>
operator*(const Unit<Prefix1, ScalingToStandard, SCALAR>&, const Unit<Prefix2, ScalingToStandard, SCALAR>&)
{
    return Unit<Prefix1 + Prefix2, ScalingToStandard, SCALAR>{};
}

//operator / for scalar
template<int Prefix1, int Prefix2, typename ScalingToStandard>
constexpr Unit<Prefix1 - Prefix2, ScalingToStandard, SCALAR>
operator/(const Unit<Prefix1, ScalingToStandard, SCALAR>&, const Unit<Prefix2, ScalingToStandard, SCALAR>&)
{
    return Unit<Prefix1 - Prefix2, ScalingToStandard, SCALAR>{};
}


template<typename...T>
struct IsUnit
{
    static constexpr bool value = false;
};
template<int Prefix, typename ScalingToStandard, Q_ID ID>
struct IsUnit<Unit<Prefix, ScalingToStandard, ID>>
{
    static constexpr bool value = true;
};
