#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>

namespace q_force
{
struct N : public prefix::none
{
};
}  // namespace q_force

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
    const double mass_kg = to_q_mass<q_mass::kg>(Quantity<TypeList<Mass>, TypeList<>>{1}).value;
    const double length_m = to_q_length<q_length::m>(Quantity<TypeList<Length>, TypeList<>>{1}).value;
    const double time2_s = to_q_s(Quantity<TypeList<Time1>, TypeList<>>{1}).value;
    const double time1_s = to_q_s(Quantity<TypeList<Time2>, TypeList<>>{1}).value;

    return q_N{v.value * mass_kg * length_m / (time1_s * time2_s)};
}

template <typename ToMass,
          typename ToLength,
          typename ToTime1,
          typename ToTime2,
          typename FromMass,
          typename FromLength,
          typename FromTime1,
          typename FromTime2>
constexpr q_N to_q_force(const Quantity<TypeList<FromMass, FromLength>, TypeList<FromTime1, FromTime2>>& v)
{
    const double mass = to_q_length<ToMass>(Quantity<TypeList<FromMass>, TypeList<>>{1}).value;
    const double length = to_q_length<ToLength>(Quantity<TypeList<FromLength>, TypeList<>>{1}).value;
    const double time1 = to_q_time<ToTime1>(Quantity<TypeList<FromTime1>, TypeList<>>{1}).value;
    const double time2 = to_q_time<ToTime2>(Quantity<TypeList<FromTime2>, TypeList<>>{1}).value;

    const double new_force = mass * length / (time1 * time2);

    return q_N{v.value * new_force};
}

template <typename ToMass,
          typename ToLength,
          typename ToTime1,
          typename ToTime2,
          typename FromMass,
          typename FromLength,
          typename FromTime1,
          typename FromTime2>
constexpr void to_q_force(const Quantity<TypeList<FromMass, FromLength>, TypeList<FromTime1, FromTime2>>& from,
                          Quantity<TypeList<ToMass, ToLength>, TypeList<ToTime1, ToTime2>>& to)
{
    const double mass = to_q_length<ToMass>(Quantity<TypeList<FromMass>, TypeList<>>{1}).value;
    const double length = to_q_length<ToLength>(Quantity<TypeList<FromLength>, TypeList<>>{1}).value;
    const double time1 = to_q_time<ToTime1>(Quantity<TypeList<FromTime1>, TypeList<>>{1}).value;
    const double time2 = to_q_time<ToTime2>(Quantity<TypeList<FromTime2>, TypeList<>>{1}).value;
    const double new_force = mass * length / (time1 * time2);
    to.value = new_force;
}

// template <typename To, typename FromMass, typename FromLength, typename FromTime1, typename FromTime2>
// constexpr void to_q_force(const Quantity<TypeList<FromMass, FromLength>, TypeList<FromTime1, FromTime2>>& from)
// {
//     const double mass = to_q_length<ToMass>(Quantity<TypeList<FromMass>, TypeList<>>{1}).value;
//     const double length = to_q_length<ToLength>(Quantity<TypeList<FromLength>, TypeList<>>{1}).value;
//     const double time1 = to_q_time<ToTime1>(Quantity<TypeList<FromTime1>, TypeList<>>{1}).value;
//     const double time2 = to_q_time<ToTime2>(Quantity<TypeList<FromTime2>, TypeList<>>{1}).value;
//     const double new_force = mass * length / (time1 * time2);
//     to.value = new_force;
// }

template <typename Q>
void doQuantity()
{
    Q::numerator;
    Q::denominator;
}

void use()
{
    doQuantity<Quantity<TypeList<int>, TypeList<>>>();
}
