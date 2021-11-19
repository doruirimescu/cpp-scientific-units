#pragma once
#include <speed.hpp>

using q_mps2 = decltype(1.0_q_mps / 1.0_q_s);

constexpr q_mps2 operator"" _q_mps2(long double v)
{
    return q_mps2{static_cast<double>(v)};
}
