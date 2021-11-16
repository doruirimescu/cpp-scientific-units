#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>
#include <unit.hpp>

using q_J = Quantity<TypeList<q_mass::kg, q_length::m, q_length::m>, TypeList<q_time::s, q_time::s>>;

using q_kJ = Quantity<TypeList<q_mass::Mg, q_length::m, q_length::m>, TypeList<q_time::s, q_time::s>>;

using q_MJ = Quantity<TypeList<q_mass::Mg, q_length::km, q_length::m>, TypeList<q_time::s, q_time::s>>;


// Force user-defined literals
constexpr q_J operator"" _q_J(long double v)
{
    return q_J{static_cast<double>(v)};
}

constexpr q_kJ operator"" _q_kJ(long double v)
{
    return q_kJ{static_cast<double>(v)};
}

constexpr q_MJ operator"" _q_MJ(long double v)
{
    return q_MJ{static_cast<double>(v)};
}
