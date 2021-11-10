#include <gtest/gtest.h>
#include <quantity_conversions.hpp>
#include <test_utils.hpp>
#include <time.hpp>
#include <mass.hpp>
#include <speed.hpp>

TEST(Time, to_q_s)
{
    constexpr q_hour h{1};
    constexpr auto seconds = to_q_s(h);
    static_assert(seconds.value == 3600);

    static_assert(q_ms{}.value == 0);
    static_assert(to_q_s(q_ms{100.0}).value == 0.1);

    static_assert(to_q_ms(q_ms{100.0}).value == 100.0);
}

TEST(Time, to_q_ms)
{
    static_assert(to_q_ms(q_ms{100.0}).value == 100.0);
    static_assert(to_q_ms(q_us{1000.0}).value == 1.0);
    static_assert(to_q_ms(q_us{1.0}).value == 0.001);
    EXPECT_FLOAT_EQ(to_q_ms(q_us{100.0}).value, 0.1);
    static_assert(to_q_ms(q_us{10000.0}).value == 10.0);
    EXPECT_FLOAT_EQ(to_q_ms(q_ns{100000.0}).value, 0.1);
    EXPECT_FLOAT_EQ(to_q_ms(q_ps{100000000.0}).value, 0.1);
    EXPECT_FLOAT_EQ(to_q_ms(q_min{1.0}).value, 60000.0);
}

TEST(Time, to_q_min)
{
    static_assert(to_q_min(q_s{60.0}).value == 1.0);
    static_assert(to_q_min(q_hour{1.0}).value == 60.0);
    static_assert(to_q_min(q_ms{1000.0}).value == 1 / 60.0);
}

TEST(Mass, to_q_g)
{
    static_assert(to_q_g(q_g{1.0}).value == 1.0);
    static_assert(to_q_g(q_kg{1.0}).value == 1000.0);
    static_assert(to_q_g(q_mg{1000.0}).value == 1.0);
}

TEST(Time, to_q_x)
{
    static_assert(to_q_s(q_hour{1.0}).value == 3600.0);
    static_assert(to_q_hour(q_hour{1.0}).value == 1.0);
    static_assert(to_q_hour(q_hour{2.0}).value == 2.0);
    EXPECT_FLOAT_EQ(to_q_hour(q_s{3600.0}).value, 1.0);
}

// TEST(Speed, speed)
// {
//     constexpr q_mps speed = 1.0_q_m / 2.0_q_s;
//     static_assert(speed.value == 0.5);

//     constexpr q_mps speed_2 = speed * 2.0;
//     static_assert(speed_2.value == 1.0);

//     constexpr q_mps speed3 = to_q_mps(3.6_q_kmph);
//     EXPECT_FLOAT_EQ(speed3.value, 1.0);

//     constexpr q_kmph speed4 = to_q_kmph(speed3);
//     // EXPECT_FLOAT_EQ(speed4.value, 3.6);
// }
