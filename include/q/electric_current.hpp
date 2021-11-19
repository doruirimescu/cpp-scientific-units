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
 * @file   electric_current.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <quantity/quantity.hpp>
#include <unit/unit.hpp>
#include <q/scalar.hpp>
#include <type_list/type_list.hpp>

namespace q_electric_current
{
    struct ampere_t
    {
        static constexpr double value = 1.0;
    };

    using kA = Unit<prefix::kilo, ampere_t, ELECTRIC_CURRENT>;
    using A = Unit<prefix::none, ampere_t, ELECTRIC_CURRENT>;
    using mA = Unit<prefix::milli, ampere_t, ELECTRIC_CURRENT>;
    using uA = Unit<prefix::micro, ampere_t, ELECTRIC_CURRENT>;
    using nA = Unit<prefix::nano, ampere_t, ELECTRIC_CURRENT>;
    using pA = Unit<prefix::pico, ampere_t, ELECTRIC_CURRENT>;

}

using q_A = Quantity<Numerator<q_scalar::unit_none, q_electric_current::A>, Denominator<q_scalar::unit_none>>;
using q_kA = Quantity<Numerator<q_scalar::unit_k, q_electric_current::A>, Denominator<q_scalar::unit_none>>;
using q_mA = Quantity<Numerator<q_scalar::unit_m, q_electric_current::A>, Denominator<q_scalar::unit_none>>;
using q_uA = Quantity<Numerator<q_scalar::unit_u, q_electric_current::A>, Denominator<q_scalar::unit_none>>;
using q_nA = Quantity<Numerator<q_scalar::unit_n, q_electric_current::A>, Denominator<q_scalar::unit_none>>;
using q_pA = Quantity<Numerator<q_scalar::unit_p, q_electric_current::A>, Denominator<q_scalar::unit_none>>;

constexpr q_A operator"" _q_A(long double v)
{
    return q_A(static_cast<double>(v));
}

constexpr q_kA operator"" _q_kA(long double v)
{
    return q_kA(static_cast<double>(v));
}

constexpr q_mA operator"" _q_mA(long double v)
{
    return q_mA(static_cast<double>(v));
}

constexpr q_uA operator"" _q_uA(long double v)
{
    return q_uA(static_cast<double>(v));
}

constexpr q_nA operator"" _q_nA(long double v)
{
    return q_nA(static_cast<double>(v));
}

constexpr q_pA operator"" _q_pA(long double v)
{
    return q_pA(static_cast<double>(v));
}
