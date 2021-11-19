#include <gtest/gtest.h>
#include <test_utils.hpp>

#include <q/electric_charge.hpp>
#include <q/electric_current.hpp>

TEST(electric_charge, all)
{
    static_assert(1.0_q_C == 1.0_q_A * 1.0_q_s);
}
