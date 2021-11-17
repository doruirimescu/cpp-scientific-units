#pragma once

#include <unit.hpp>
#include <prefix.hpp>

namespace q_scalar
{
struct scalar
{
    static constexpr double value = 1.0;
};
using ks = Unit<prefix::kilo, scalar, SCALAR>;
using Ms = Unit<prefix::mega, scalar, SCALAR>;
using Gs = Unit<prefix::giga, scalar, SCALAR>;
using Ts = Unit<prefix::tera, scalar, SCALAR>;
using Ps = Unit<prefix::peta, scalar, SCALAR>;
using Es = Unit<prefix::exa, scalar, SCALAR>;
using Zs = Unit<prefix::zetta, scalar, SCALAR>;
using Ys = Unit<prefix::yotta, scalar, SCALAR>;

using s = Unit<prefix::none, scalar, SCALAR>;
};  // namespace scalar
