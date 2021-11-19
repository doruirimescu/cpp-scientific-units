#include <gtest/gtest.h>
#include <test_utils.hpp>

#include <q/voltage.hpp>
#include <q/mass.hpp>
#include <q/time.hpp>
#include <q/length.hpp>
#include <q/electric_current.hpp>

TEST(voltage, all)
{
    static_assert(1.0_q_V == 1.0_q_kg * 1.0_q_m * 1.0_q_m /(1.0_q_s * 1.0_q_s * 1.0_q_s * 1.0_q_A));
}
