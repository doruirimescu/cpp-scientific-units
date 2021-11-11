#include <gtest/gtest.h>
#include <test_utils.hpp>
#include <time.hpp>
#include <mass.hpp>
#include <speed.hpp>
#include <force.hpp>

TEST(Time, to_q_s)
{
    constexpr q_hour h{1};
    constexpr auto seconds = to_q_s(h);
    static_assert(seconds.value == 3600);

    static_assert(q_ms{}.value == 1);
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

TEST(Mass, to_grams)
{
    static_assert(to_q_mass<q_mass::g>(q_g{1.0}).value == 1.0);
    static_assert(to_q_mass<q_mass::g>(q_kg{1.0}).value == 1000.0);
    static_assert(to_q_mass<q_mass::g>(q_mg{1000.0}).value == 1.0);
}

TEST(Time, to_q_x)
{
    static_assert(to_q_s(q_hour{1.0}).value == 3600.0);
    static_assert(to_q_hour(q_hour{1.0}).value == 1.0);
    static_assert(to_q_hour(q_hour{2.0}).value == 2.0);
    static_assert(to_q_hour(q_s{3600.0}).value == 1.0);
    static_assert(to_q_day(q_hour{24.0}).value == 1.0);

    auto result = to_q_time<q_time::min>(q_hour{1.0}).value;
    EXPECT_FLOAT_EQ(result, 60.0);

    result = to_q_time<q_time::s>(q_min{1.0}).value;
    EXPECT_FLOAT_EQ(result, 60.0);
}

TEST(Length, to_q_x)
{
    static_assert(to_q_length<q_length::km>(1.0_q_km).value == 1.0);
    static_assert(to_q_length<q_length::km>(1000.0_q_m).value == 1.0);
}

TEST(Speed, speed)
{
    static_assert(to_q_ms(1.0_q_ms).value == 1.0);

    constexpr q_mps speed = 1.0_q_m / 2.0_q_s;
    static_assert(speed.value == 0.5);

    constexpr q_mps speed_2 = speed * 2.0;
    static_assert(speed_2.value == 1.0);

    constexpr q_mps speed3 = to_q_mps(3.6_q_kmph);
    EXPECT_FLOAT_EQ(speed3.value, 1.0);

    constexpr q_kmph speed4 = to_q_speed<q_length::km, q_time::hour>(1.0_q_mps);
    EXPECT_FLOAT_EQ(speed4.value, 3.6);

    auto result = to_q_speed<q_length::m, q_time::hour>(0.5_q_mps + 0.5_q_mps).value;
    EXPECT_FLOAT_EQ(result, 3600.0);
}

TEST(Force, to_q_N_1)
{
    EXPECT_FLOAT_EQ(to_q_N(1.0_q_N).value, 1.0);

    static_assert(to_q_N(2.0_q_kg * 1.0_q_m / (1.0_q_s * 1.0_q_s)).value == 2.0);
    static_assert(to_q_N(1.0_q_kg * 2.0_q_m / (1.0_q_s * 1.0_q_s)).value == 2.0);
    static_assert(to_q_N(1.0_q_kg * 2.0_q_m / (2.0_q_s * 1.0_q_s)).value == 1.0);
    static_assert(to_q_N(1.0_q_kg * 60.0_q_m / (to_q_s(1.0_q_min) * 1.0_q_s)).value == 1.0);
}

TEST(Force, to_q_N_2)
{
    constexpr auto mass = 1000.0_q_g;
    constexpr auto length = 100.0_q_cm;
    constexpr auto time_1 = 1.0_q_s;
    constexpr auto time_2 = 1.0_q_s;
    constexpr auto some_value_convertible_to_force = mass * length / (time_1 * time_2);
    constexpr q_N newtons = to_q_N(some_value_convertible_to_force);

    EXPECT_FLOAT_EQ(
        newtons.value,
        (to_q_mass<q_mass::kg>(mass) * to_q_length<q_length::m>(length) / (to_q_s(time_1) * to_q_s(time_2))).value);
}
TEST(Force, to_q_force)
{
    auto result = to_q_force<q_mass::kg, q_length::m, q_time::s, q_time::s>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1.0);
    result = to_q_force<q_mass::g, q_length::m, q_time::s, q_time::s>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1000.0);
    result = to_q_force<q_mass::kg, q_length::mm, q_time::s, q_time::s>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1000.0);
    result = to_q_force<q_mass::kg, q_length::m, q_time::min, q_time::s>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 60.0);
}
TEST(Conversions, uncomment_to_fail)
{
    // to_q_s(1.0_q_m);
    // static_assert(to_q_length<q_mass::kg>(100.0_q_m).value == 100.0);
}

TEST(Length, to_q_length)
{
    static_assert(to_q_length<q_length::m>(100.0_q_m).value == 100.0);
    EXPECT_FLOAT_EQ(to_q_length<q_length::cm>(1.0_q_m).value, 100.0);
    EXPECT_FLOAT_EQ(to_q_length<q_length::mm>(1.0_q_cm).value, 10.0);
    EXPECT_FLOAT_EQ(to_q_length<q_length::km>(1000.0_q_m).value, 1.0);
}

TEST(ConvertToAnyQuantity, to_any_q)
{
    // double result = static_cast<q_m>(1.0_q_m).value;
    // EXPECT_FLOAT_EQ(result, 1.0);

    auto result = to_any_q<q_km>(1.0_q_m).value;
    EXPECT_FLOAT_EQ(result, 0.001);

    result = to_any_q<q_m>(1.0_q_km).value;
    EXPECT_FLOAT_EQ(result, 1000.0);

    // result = to_any_q<q_g>(1.0_q_kg).value;
    // EXPECT_FLOAT_EQ(result, 1000.0);

    // result = to_any_q<q_mps>(1.0_q_kmph).value;
    // EXPECT_FLOAT_EQ(result, 1/3.6);
}

TEST(Length, to_q_mass)
{
    static_assert(to_q_length<q_mass::kg>(1000.0_q_g).value == 1.0);
}
