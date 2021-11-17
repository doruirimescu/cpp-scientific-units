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
 * @file   mass.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <id.hpp>
#include <unit.hpp>

namespace q_mass
{
struct gram
{
    static constexpr double value = 1.0;
};

using Mg = Unit<prefix::mega, gram, MASS>;

using hg = Unit<prefix::hecto, gram, MASS>;
using dag = Unit<prefix::deca, gram, MASS>;
using g = Unit<prefix::none, gram, MASS>;
using kg = Unit<prefix::kilo, gram, MASS>;
using dg = Unit<prefix::deci, gram, MASS>;
using cg = Unit<prefix::centi, gram, MASS>;
using mg = Unit<prefix::milli, gram, MASS>;
using ug = Unit<prefix::micro, gram, MASS>;
using ng = Unit<prefix::nano, gram, MASS>;
using pg = Unit<prefix::pico, gram, MASS>;
using fg = Unit<prefix::femto, gram, MASS>;
using ag = Unit<prefix::atto, gram, MASS>;
using zg = Unit<prefix::zepto, gram, MASS>;
using yg = Unit<prefix::yocto, gram, MASS>;

}  // namespace q_mass

// Mass types

using q_kg =    Quantity<TypeList<q_mass::kg>, TypeList<>>;
using q_hg =    Quantity<TypeList<q_mass::hg>, TypeList<>>;
using q_dag =   Quantity<TypeList<q_mass::dag>,TypeList<>>;
using q_g =     Quantity<TypeList<q_mass::g>,  TypeList<>>;
using q_dg =    Quantity<TypeList<q_mass::dg>, TypeList<>>;
using q_cg =    Quantity<TypeList<q_mass::cg>, TypeList<>>;
using q_mg =    Quantity<TypeList<q_mass::mg>, TypeList<>>;

// Mass user-defined literals
constexpr q_g operator"" _q_g(long double v)
{
    return q_g{static_cast<double>(v)};
}
constexpr q_kg operator"" _q_kg(long double v)
{
    return q_kg{static_cast<double>(v)};
}
constexpr q_mg operator"" _q_mg(long double v)
{
    return q_mg{static_cast<double>(v)};
}
