#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <id.hpp>
#include <conversion.hpp>

namespace q_mass
{
struct mass
{
    static constexpr int id = MASS;
};
struct g : public prefix::none, public mass
{
};

struct kg : public prefix::kilo, public mass
{
};

struct mg : public prefix::milli, public mass
{
};
}  // namespace q_mass

// Mass types
using q_g = Quantity<TypeList<q_mass::g>, TypeList<>>;
using q_kg = Quantity<TypeList<q_mass::kg>, TypeList<>>;
using q_mg = Quantity<TypeList<q_mass::mg>, TypeList<>>;

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

// Mass conversions
template <typename ToType, typename FromType>
constexpr Quantity<TypeList<ToType>, TypeList<>> to_q_mass(const Quantity<TypeList<FromType>, TypeList<>>& from)
{
    return conversion::to_q_<ToType>(from);
}
