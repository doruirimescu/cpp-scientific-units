#pragma once

#include <unit/unit.hpp>
#include <prefix.hpp>
#include <unit/id.hpp>
#include <quantity.hpp>
namespace q_scalar
{
struct scalar_t
{
    static constexpr double value = 1.0;
};

using unit_Y = Unit<prefix::yotta, scalar_t, SCALAR>;
using unit_Z = Unit<prefix::zetta, scalar_t, SCALAR>;
using unit_E = Unit<prefix::exa, scalar_t, SCALAR>;
using unit_P = Unit<prefix::peta, scalar_t, SCALAR>;
using unit_T = Unit<prefix::tera, scalar_t, SCALAR>;
using unit_G = Unit<prefix::giga, scalar_t, SCALAR>;
using unit_M = Unit<prefix::mega, scalar_t, SCALAR>;
using unit_k = Unit<prefix::kilo, scalar_t, SCALAR>;
using unit_h = Unit<prefix::hecto, scalar_t, SCALAR>;
using unit_da = Unit<prefix::deca, scalar_t, SCALAR>;
using unit_none = Unit<prefix::none, scalar_t, SCALAR>;
using unit_d = Unit<prefix::deci, scalar_t, SCALAR>;
using unit_c = Unit<prefix::centi, scalar_t, SCALAR>;
using unit_m = Unit<prefix::milli, scalar_t, SCALAR>;
using unit_u = Unit<prefix::micro, scalar_t, SCALAR>;
using unit_n = Unit<prefix::nano, scalar_t, SCALAR>;
using unit_p = Unit<prefix::pico, scalar_t, SCALAR>;
using unit_f = Unit<prefix::femto, scalar_t, SCALAR>;
using unit_a = Unit<prefix::atto, scalar_t, SCALAR>;
using unit_z = Unit<prefix::zepto, scalar_t, SCALAR>;
using unit_y = Unit<prefix::yocto, scalar_t, SCALAR>;

using q_yotta =     Quantity<TypeList<q_scalar::unit_Y>, TypeList<q_scalar::unit_none>>;
using q_zetta =     Quantity<TypeList<q_scalar::unit_Z>, TypeList<q_scalar::unit_none>>;
using q_exa =       Quantity<TypeList<q_scalar::unit_E>, TypeList<q_scalar::unit_none>>;
using q_peta =      Quantity<TypeList<q_scalar::unit_P>, TypeList<q_scalar::unit_none>>;
using q_tera =      Quantity<TypeList<q_scalar::unit_T>, TypeList<q_scalar::unit_none>>;
using q_giga =      Quantity<TypeList<q_scalar::unit_G>, TypeList<q_scalar::unit_none>>;
using q_mega =      Quantity<TypeList<q_scalar::unit_M>, TypeList<q_scalar::unit_none>>;
using q_kilo =      Quantity<TypeList<q_scalar::unit_k>, TypeList<q_scalar::unit_none>>;
using q_hecto =     Quantity<TypeList<q_scalar::unit_h>, TypeList<q_scalar::unit_none>>;
using q_none =      Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>>;
using q_deca =      Quantity<TypeList<q_scalar::unit_da>, TypeList<q_scalar::unit_none>>;
using q_deci =      Quantity<TypeList<q_scalar::unit_d>, TypeList<q_scalar::unit_none>>;
using q_centi =     Quantity<TypeList<q_scalar::unit_c>, TypeList<q_scalar::unit_none>>;
using q_milli =     Quantity<TypeList<q_scalar::unit_m>, TypeList<q_scalar::unit_none>>;
using q_micro =     Quantity<TypeList<q_scalar::unit_u>, TypeList<q_scalar::unit_none>>;
using q_nano =      Quantity<TypeList<q_scalar::unit_n>, TypeList<q_scalar::unit_none>>;
using q_pico =      Quantity<TypeList<q_scalar::unit_p>, TypeList<q_scalar::unit_none>>;
using q_femto =     Quantity<TypeList<q_scalar::unit_f>, TypeList<q_scalar::unit_none>>;
using q_atto =      Quantity<TypeList<q_scalar::unit_a>, TypeList<q_scalar::unit_none>>;
using q_zepto =     Quantity<TypeList<q_scalar::unit_z>, TypeList<q_scalar::unit_none>>;
using q_yocto =     Quantity<TypeList<q_scalar::unit_y>, TypeList<q_scalar::unit_none>>;

};  // namespace q_scalar

constexpr q_scalar::q_none operator"" _q_none(long double v)
{
    return q_scalar::q_none(v);
}

constexpr q_scalar::q_kilo operator"" _q_kilo(long double v)
{
    return q_scalar::q_kilo(v);
}
constexpr q_scalar::q_mega operator"" _q_mega(long double v)
{
    return q_scalar::q_mega(v);
}
constexpr q_scalar::q_giga operator"" _q_giga(long double v)
{
    return q_scalar::q_giga(v);
}
constexpr q_scalar::q_tera operator"" _q_tera(long double v)
{
    return q_scalar::q_tera(v);
}
constexpr q_scalar::q_peta operator"" _q_peta(long double v)
{
    return q_scalar::q_peta(v);
}
constexpr q_scalar::q_exa operator"" _q_exa(long double v)
{
    return q_scalar::q_exa(v);
}
constexpr q_scalar::q_zetta operator"" _q_zetta(long double v)
{
    return q_scalar::q_zetta(v);
}
constexpr q_scalar::q_yotta operator"" _q_yotta(long double v)
{
    return q_scalar::q_yotta(v);
}
constexpr q_scalar::q_hecto operator"" _q_hecto(long double v)
{
    return q_scalar::q_hecto(v);
}
constexpr q_scalar::q_deca operator"" _q_deca(long double v)
{
    return q_scalar::q_deca(v);
}
constexpr q_scalar::q_deci operator"" _q_deci(long double v)
{
    return q_scalar::q_deci(v);
}
constexpr q_scalar::q_centi operator"" _q_centi(long double v)
{
    return q_scalar::q_centi(v);
}
constexpr q_scalar::q_milli operator"" _q_milli(long double v)
{
    return q_scalar::q_milli(v);
}
constexpr q_scalar::q_micro operator"" _q_micro(long double v)
{
    return q_scalar::q_micro(v);
}
constexpr q_scalar::q_nano operator"" _q_nano(long double v)
{
    return q_scalar::q_nano(v);
}
constexpr q_scalar::q_pico operator"" _q_pico(long double v)
{
    return q_scalar::q_pico(v);
}
constexpr q_scalar::q_femto operator"" _q_femto(long double v)
{
    return q_scalar::q_femto(v);
}
constexpr q_scalar::q_atto operator"" _q_atto(long double v)
{
    return q_scalar::q_atto(v);
}
constexpr q_scalar::q_zepto operator"" _q_zepto(long double v)
{
    return q_scalar::q_zepto(v);
}
