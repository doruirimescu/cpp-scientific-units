#pragma once

#include <unit.hpp>
#include <prefix.hpp>
#include <id.hpp>
namespace q_scalar
{
struct scalar
{
    static constexpr double value = 1.0;
};

using Y = Unit<prefix::yotta, scalar, SCALAR>;
using Z = Unit<prefix::zetta, scalar, SCALAR>;
using E = Unit<prefix::exa, scalar, SCALAR>;
using P = Unit<prefix::peta, scalar, SCALAR>;
using T = Unit<prefix::tera, scalar, SCALAR>;
using G = Unit<prefix::giga, scalar, SCALAR>;
using M = Unit<prefix::mega, scalar, SCALAR>;
using k = Unit<prefix::kilo, scalar, SCALAR>;
using none = Unit<prefix::none, scalar, SCALAR>;
using d = Unit<prefix::deci, scalar, SCALAR>;
using c = Unit<prefix::centi, scalar, SCALAR>;
using m = Unit<prefix::milli, scalar, SCALAR>;
using u = Unit<prefix::micro, scalar, SCALAR>;
using n = Unit<prefix::nano, scalar, SCALAR>;
using p = Unit<prefix::pico, scalar, SCALAR>;
using f = Unit<prefix::femto, scalar, SCALAR>;
using a = Unit<prefix::atto, scalar, SCALAR>;
using z = Unit<prefix::zepto, scalar, SCALAR>;
using y = Unit<prefix::yocto, scalar, SCALAR>;

};  // namespace q_scalar
