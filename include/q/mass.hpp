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
#include <quantity/quantity.hpp>
#include <type_list/type_list.hpp>
#include <unit/prefix.hpp>
#include <unit/id.hpp>
#include <unit/unit.hpp>
#include <q/scalar.hpp>
namespace q_mass
{
struct gram_t
{
    static constexpr double value = 1.0;
};
using g = Unit<prefix::none, gram_t, MASS>;

}  // namespace q_mass

// Mass types

using q_kg =    Quantity<TypeList<q_scalar::unit_k, q_mass::g>,  TypeList<q_scalar::unit_none>>;
using q_hg =    Quantity<TypeList<q_scalar::unit_h, q_mass::g>, TypeList<q_scalar::unit_none>>;
using q_dag =   Quantity<TypeList<q_scalar::unit_da, q_mass::g>,TypeList<q_scalar::unit_none>>;
using q_g =     Quantity<TypeList<q_scalar::unit_none, q_mass::g>,  TypeList<q_scalar::unit_none>>;
using q_dg =    Quantity<TypeList<q_scalar::unit_d, q_mass::g>, TypeList<q_scalar::unit_none>>;
using q_cg =    Quantity<TypeList<q_scalar::unit_c, q_mass::g>, TypeList<q_scalar::unit_none>>;
using q_mg =    Quantity<TypeList<q_scalar::unit_m, q_mass::g>, TypeList<q_scalar::unit_none>>;

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
