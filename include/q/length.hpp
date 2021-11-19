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
 * @file   length.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <quantity/quantity.hpp>
#include <type_list/type_list.hpp>
#include <unit/prefix.hpp>
#include <unit/id.hpp>
#include <unit/unit.hpp>
#include <q/scalar.hpp>
namespace q_length
{

struct meter_t
{
    static constexpr double value = 1.0;
};

struct inch_t
{
    static constexpr double value = 0.0254;
};

using unit_m = Unit<prefix::none, meter_t, LENGTH>;
using unit_in = Unit<prefix::none, inch_t, LENGTH>;
using unit_mil = Unit<prefix::milli, inch_t, LENGTH>;

}  // namespace q_length

// Length types
using q_Ym  =    Quantity<Numerator<q_scalar::unit_Y, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Zm  =    Quantity<Numerator<q_scalar::unit_Z, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Em  =    Quantity<Numerator<q_scalar::unit_E, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Pm  =    Quantity<Numerator<q_scalar::unit_P, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Tm  =    Quantity<Numerator<q_scalar::unit_T, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Gm  =    Quantity<Numerator<q_scalar::unit_G, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_Mm  =    Quantity<Numerator<q_scalar::unit_M, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_km  =    Quantity<Numerator<q_scalar::unit_k, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_dam =    Quantity<Numerator<q_scalar::unit_da, q_length::unit_m>,    Denominator<q_scalar::unit_none>>;
using q_hm  =    Quantity<Numerator<q_scalar::unit_h, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_m   =    Quantity<Numerator<q_scalar::unit_none, q_length::unit_m>,  Denominator<q_scalar::unit_none>>;
using q_dm  =    Quantity<Numerator<q_scalar::unit_d, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_cm  =    Quantity<Numerator<q_scalar::unit_c, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_mm  =    Quantity<Numerator<q_scalar::unit_m, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_um  =    Quantity<Numerator<q_scalar::unit_u, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_nm  =    Quantity<Numerator<q_scalar::unit_n, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_pm  =    Quantity<Numerator<q_scalar::unit_p, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_fm  =    Quantity<Numerator<q_scalar::unit_f, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_am  =    Quantity<Numerator<q_scalar::unit_a, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_zm  =    Quantity<Numerator<q_scalar::unit_z, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;
using q_ym  =    Quantity<Numerator<q_scalar::unit_y, q_length::unit_m>,     Denominator<q_scalar::unit_none>>;

using q_in =    Quantity<Numerator<q_scalar::unit_none, q_length::unit_in>, Denominator<q_scalar::unit_none>>;
using q_mil =   Quantity<Numerator<q_scalar::unit_none, q_length::unit_mil>,TypeList<q_scalar::unit_none>>;

// Length user-defined literals
constexpr q_Ym operator"" _q_Ym(long double v)
{
    return q_Ym{static_cast<double>(v)};
}
constexpr q_Zm operator"" _q_Zm(long double v)
{
    return q_Zm{static_cast<double>(v)};
}
constexpr q_Em operator"" _q_Em(long double v)
{
    return q_Em{static_cast<double>(v)};
}
constexpr q_Pm operator"" _q_Pm(long double v)
{
    return q_Pm{static_cast<double>(v)};
}
constexpr q_Tm operator"" _q_Tm(long double v)
{
    return q_Tm{static_cast<double>(v)};
}
constexpr q_Gm operator"" _q_Gm(long double v)
{
    return q_Gm{static_cast<double>(v)};
}
constexpr q_Mm operator"" _q_Mm(long double v)
{
    return q_Mm{static_cast<double>(v)};
}
constexpr q_hm operator"" _q_hm(long double v)
{
    return q_hm{static_cast<double>(v)};
}
constexpr q_km operator"" _q_km(long double v)
{
    return q_km{static_cast<double>(v)};
}
constexpr q_dam operator"" _q_dam(long double v)
{
    return q_dam{static_cast<double>(v)};
}
constexpr q_m operator"" _q_m(long double v)
{
    return q_m{static_cast<double>(v)};
}
constexpr q_dm operator"" _q_dm(long double v)
{
    return q_dm{static_cast<double>(v)};
}
constexpr q_cm operator"" _q_cm(long double v)
{
    return q_cm{static_cast<double>(v)};
}
constexpr q_mm operator"" _q_mm(long double v)
{
    return q_mm{static_cast<double>(v)};
}
constexpr q_um operator"" _q_um(long double v)
{
    return q_um{static_cast<double>(v)};
}
constexpr q_nm operator"" _q_nm(long double v)
{
    return q_nm{static_cast<double>(v)};
}
constexpr q_pm operator"" _q_pm(long double v)
{
    return q_pm{static_cast<double>(v)};
}
constexpr q_fm operator"" _q_fm(long double v)
{
    return q_fm{static_cast<double>(v)};
}
constexpr q_am operator"" _q_am(long double v)
{
    return q_am{static_cast<double>(v)};
}
constexpr q_zm operator"" _q_zm(long double v)
{
    return q_zm{static_cast<double>(v)};
}
constexpr q_ym operator"" _q_ym(long double v)
{
    return q_ym{static_cast<double>(v)};
}

constexpr q_in operator"" _q_in(long double v)
{
    return q_in{static_cast<double>(v)};
}

constexpr q_mil operator"" _q_mil(long double v)
{
    return q_mil{static_cast<double>(v)};
}
