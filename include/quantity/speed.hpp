#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
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
    const double length_in_meters = Length::value;
    const double time_in_seconds = Time::value;
    return q_mps{v.value * length_in_meters / time_in_seconds};
}

template <typename Length, typename Time>
constexpr q_kmph to_q_kmph(const Quantity<TypeList<Length>, TypeList<Time>>& v)
{
    const double length_in_meters = Length::value;
    const double time_in_seconds = Time::value;
    const double length_in_kilometers = length_in_meters / q_length::km::value;
    const double time_in_hours = time_in_seconds / q_time::hour::value;
    return q_kmph{v.value * length_in_kilometers / time_in_hours};
}

template <typename ToLength, typename ToTime, typename FromLength, typename FromTime>
constexpr Quantity<TypeList<ToLength>, TypeList<ToTime>>
    to_q_speed(const Quantity<TypeList<FromLength>, TypeList<FromTime>>& from)
{
    const double new_length = to_q_length<ToLength>(Quantity<TypeList<FromLength>, TypeList<>>{1}).value;
    const double new_time = to_q_time<ToTime>(Quantity<TypeList<FromTime>, TypeList<>>{1}).value;
    const double new_speed = new_length / new_time;

    return Quantity<TypeList<ToLength>, TypeList<ToTime>>{from.value * new_speed};
}
