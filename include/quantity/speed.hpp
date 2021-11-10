#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <orderable.hpp>
#include <time.hpp>
#include <length.hpp>

// Speed types
using q_mps = Quantity<TypeList<q_length::m>, TypeList<q_time::s>>;
using q_kmph = Quantity<TypeList<q_length::km>, TypeList<q_time::hour>>;

// Mass user-defined literals
constexpr q_mps operator"" _q_mps(long double v)
{
    return q_mps{static_cast<double>(v)};
}
constexpr q_kmph operator"" _q_kmph(long double v)
{
    return q_kmph{static_cast<double>(v)};
}

// Speed conversions

template <typename Length, typename Time>
constexpr q_mps to_q_mps(const Quantity<TypeList<Length>, TypeList<Time>>& v)
{
    const Length length_unit;
    const Time time_unit;
    const double length_in_meters = length_unit.value;
    const double time_in_seconds = time_unit.value;
    return q_mps{v.value * length_in_meters / time_in_seconds};
}

template <typename Length, typename Time>
constexpr q_kmph to_q_kmph(const Quantity<TypeList<Length>, TypeList<Time>>& v)
{
    const Length length_unit;
    const Time time_unit;
    const double length_in_meters = length_unit.value;
    const double time_in_seconds = time_unit.value;
    const double length_in_kilometers = length_in_meters / 1000.0;
    const double time_in_hours = time_in_seconds / 3600.0;

    return q_mps{v.value * length_in_kilometers / time_in_hours};
}
