#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>

namespace q_mass
{
struct g : public prefix::none
{
    static constexpr double mass = value;
};

struct kg : public prefix::kilo
{
    static constexpr double mass = value;
};

struct mg : public prefix::milli
{
    static constexpr double mass = value;
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
template <typename Mass>
constexpr q_g to_q_g(const Quantity<TypeList<Mass>, TypeList<>>& v)
{
    return q_g{Mass::mass * v.value};
}

template <typename Mass>
constexpr q_mg to_q_mg(const Quantity<TypeList<Mass>, TypeList<>>& v)
{
    const q_g gram_unit = to_q_g(v);
    return q_mg{gram_unit.value * 1000.0};
}

template <typename Mass>
constexpr q_kg to_q_kg(const Quantity<TypeList<Mass>, TypeList<>>& v)
{
    const double gram_unit = Mass::mass;
    return q_kg{v.value * gram_unit / q_mass::kg::mass};
}
