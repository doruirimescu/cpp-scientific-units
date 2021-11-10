#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>

namespace q_force
{
struct N : public prefix::none
{
};
}

// Force types
using q_N = Quantity<TypeList<q_mass::kg, q_length::m>, TypeList<q_time::s, q_time::s>>;

// Force user-defined literals
constexpr q_N operator"" _q_N(long double v)
{
    return q_N{static_cast<double>(v)};
}

// Force conversions
template <typename Mass, typename Length, typename Time1, typename Time2>
constexpr q_N to_q_N(const Quantity<TypeList<Mass, Length>, TypeList<Time1, Time2>>& v)
{
    const double mass_kg = to_q_kg(Quantity<TypeList<Mass>, TypeList<>>{1}).value;
    const double length_m = to_q_m(Quantity<TypeList<Length>, TypeList<>>{1}).value;
    const double time2_s = to_q_s(Quantity<TypeList<Time1>, TypeList<>>{1}).value;
    const double time1_s = to_q_s(Quantity<TypeList<Time2>, TypeList<>>{1}).value;

    return q_N{v.value * mass_kg * length_m / (time1_s * time2_s)};
}
