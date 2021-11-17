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
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <id.hpp>
#include <unit.hpp>

namespace q_length
{

struct meter
{
    static constexpr double value = 1.0;
};

struct inch
{
    static constexpr double value = 0.0254;
};

struct scalar
{
    static constexpr double value = 1.0;
};

using Ym =  Unit<prefix::yotta, meter, LENGTH>;
using Zm =  Unit<prefix::zetta, meter, LENGTH>;
using Em =  Unit<prefix::exa, meter, LENGTH>;
using Pm =  Unit<prefix::peta, meter, LENGTH>;
using Tm =  Unit<prefix::tera, meter, LENGTH>;
using Gm =  Unit<prefix::giga, meter, LENGTH>;
using Mm =  Unit<prefix::mega, meter, LENGTH>;
using km =  Unit<prefix::kilo, meter, LENGTH>;
using hm =  Unit<prefix::hecto, meter, LENGTH>;
using dam = Unit<prefix::deca, meter, LENGTH>;
using m =   Unit<prefix::none, meter, LENGTH>;
using dm =  Unit<prefix::deci, meter, LENGTH>;
using cm =  Unit<prefix::centi, meter, LENGTH>;
using mm =  Unit<prefix::milli, meter, LENGTH>;
using um =  Unit<prefix::micro, meter, LENGTH>;
using nm =  Unit<prefix::nano, meter, LENGTH>;
using pm =  Unit<prefix::pico, meter, LENGTH>;
using fm =  Unit<prefix::femto, meter, LENGTH>;
using am =  Unit<prefix::atto, meter, LENGTH>;
using zm =  Unit<prefix::zepto, meter, LENGTH>;
using ym =  Unit<prefix::yocto, meter, LENGTH>;

using in = Unit<prefix::none, inch, LENGTH>;
using mil = Unit<prefix::milli, inch, LENGTH>;

}  // namespace q_length

// Length types
using q_Ym =    Quantity<Numerator<q_length::Ym>, Denominator<>>;
using q_Zm =    Quantity<Numerator<q_length::Zm>, Denominator<>>;
using q_Em =    Quantity<Numerator<q_length::Em>, Denominator<>>;
using q_Pm =    Quantity<Numerator<q_length::Pm>, Denominator<>>;
using q_Tm =    Quantity<Numerator<q_length::Tm>, Denominator<>>;
using q_Gm =    Quantity<Numerator<q_length::Gm>, Denominator<>>;
using q_Mm =    Quantity<Numerator<q_length::Mm>, Denominator<>>;
using q_km =    Quantity<Numerator<q_length::km>, Denominator<>>;
using q_dam =   Quantity<Numerator<q_length::dam>, Denominator<>>;
using q_m =     Quantity<Numerator<q_length::m>,  Denominator<>>;
using q_dm =    Quantity<Numerator<q_length::dm>, Denominator<>>;
using q_cm =    Quantity<Numerator<q_length::cm>, Denominator<>>;
using q_mm =    Quantity<Numerator<q_length::mm>, Denominator<>>;
using q_um =    Quantity<Numerator<q_length::um>, Denominator<>>;
using q_nm =    Quantity<Numerator<q_length::nm>, Denominator<>>;
using q_pm =    Quantity<Numerator<q_length::pm>, Denominator<>>;
using q_fm =    Quantity<Numerator<q_length::fm>, Denominator<>>;
using q_am =    Quantity<Numerator<q_length::am>, Denominator<>>;
using q_zm =    Quantity<Numerator<q_length::zm>, Denominator<>>;
using q_ym =    Quantity<Numerator<q_length::ym>, Denominator<>>;
using q_in =    Quantity<Numerator<q_length::in>, Denominator<>>;
using q_mil =   Quantity<Numerator<q_length::mil>,Denominator<>>;

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
