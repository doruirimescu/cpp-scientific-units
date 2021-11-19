#include <gtest/gtest.h>
#include <test_utils.hpp>

#include <q/voltage.hpp>
#include <q/mass.hpp>
#include <q/time.hpp>
#include <q/length.hpp>
#include <q/electric_resistance.hpp>

TEST(electric_resistance, all)
{
    static_assert(1.0_q_Ohm == 1.0_q_V / 1.0_q_A);
}
