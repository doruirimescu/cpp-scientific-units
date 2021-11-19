#pragma once
#include <mass.hpp>
#include <length.hpp>
#include <time.hpp>
#include <unit/unit.hpp>
#include <scalar.hpp>
#include <force.hpp>

using q_J =  decltype(1.0_q_N * 1.0_q_m);
using q_kJ = decltype(1.0_q_kilo * 1.0_q_N * 1.0_q_m);
using q_MJ = decltype(1.0_q_mega * 1.0_q_N * 1.0_q_m);
using q_GJ = decltype(1.0_q_giga * 1.0_q_N * 1.0_q_m);

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

constexpr q_GJ operator"" _q_GJ(long double v)
{
    return q_GJ{static_cast<double>(v)};
}
