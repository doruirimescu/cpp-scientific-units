#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <orderable.hpp>

namespace q_mass
{
struct g : public Orderable<double>
{
    explicit constexpr g()
        : Orderable<double>(none_value)
    {
    }
};

struct kg : public prefix::kilo
{
};

struct mg : public Orderable<double>
{
    explicit constexpr mg()
        : Orderable<double>(milli_value)
    {
    }
};
}

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
template <typename T>
constexpr q_g to_q_g(const Quantity<TypeList<T>, TypeList<>>& v)
{
    const T mass_unit;
    return q_g{v.value * mass_unit.value};
}

template <typename T>
constexpr q_mg to_q_mg(const Quantity<TypeList<T>, TypeList<>>& v)
{
    const q_g gram_unit = to_q_g(v);
    return q_mg{gram_unit.value * 1000.0};
}
