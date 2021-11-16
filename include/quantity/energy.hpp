#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>
#include <unit.hpp>

using q_J = Quantity<TypeList<q_mass::kg, q_length::m, q_length::m>, TypeList<q_time::s, q_time::s>>;

// Force user-defined literals
constexpr q_J operator"" _q_J(long double v)
{
    return q_J{static_cast<double>(v)};
}
