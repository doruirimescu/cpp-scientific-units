#include <gtest/gtest.h>
#include <test_utils.hpp>
#include <quantity.hpp>
#include <time.hpp>
#include <mass.hpp>
#include <speed.hpp>
#include <force.hpp>
#include <energy.hpp>
#include <scalar.hpp>
#include <acceleration.hpp>

// /**
//  * Naming convention
//  * TEST(Quantity, explanation)
//  * ex: TEST(Time, static_cast_q_h)
//  */

TEST(Time, static_cast_q_s)
{
    constexpr q_hour h{1};
    constexpr auto seconds = static_cast<q_s>(h);
    static_assert(seconds.value == 3600);

    static_assert(q_ms{}.value == 1);
    static_assert(static_cast<q_s>(q_ms{100.0}).value == 0.1);

    static_assert(static_cast<q_s>(q_ms{100.0}).value == 0.1);
}

TEST(Time, static_cast_q_ms)
{
    static_assert(static_cast<q_ms>(1.0_q_ms).value == 1.0);
    static_assert(static_cast<q_ms>(q_ms{100.0}).value == 100.0);
    static_assert(static_cast<q_ms>(q_us{1000.0}).value == 1.0);
    static_assert(static_cast<q_ms>(q_us{1.0}).value == 0.001);
    EXPECT_FLOAT_EQ(static_cast<q_ms>(q_us{100.0}).value, 0.1);
    static_assert(static_cast<q_ms>(q_us{10000.0}).value == 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_ms>(q_ns{100000.0}).value, 0.1);
    EXPECT_FLOAT_EQ(static_cast<q_ms>(q_ps{100000000.0}).value, 0.1);
    EXPECT_FLOAT_EQ(static_cast<q_ms>(q_min{1.0}).value, 60000.0);
}

TEST(Time, static_cast_q_min)
{
    static_assert(static_cast<q_min>(q_s{60.0}).value == 1.0);
    static_assert(static_cast<q_min>(q_hour{1.0}).value == 60.0);
    static_assert(static_cast<q_min>(q_ms{1000.0}).value == 1 / 60.0);
}

TEST(Time, static_cast_q_hour)
{
    static_assert(static_cast<q_hour>(q_hour{1.0}).value == 1.0);
    static_assert(static_cast<q_hour>(q_min{60.0}).value == 1.0);
    static_assert(static_cast<q_hour>(q_s{3600.0}).value == 1.0);
}
// //*********************************MASS******************************************

TEST(Mass, to_q_kg)
{
    static_assert(static_cast<q_kg>(1000.0_q_g).value == 1.0);
}

TEST(Mass, static_cast_q_g)
{
    static_assert(static_cast<q_g>(q_g{1.0}).value == 1.0);
    static_assert(static_cast<q_g>(q_kg{1.0}).value == 1000.0);
    static_assert(static_cast<q_g>(q_mg{1000.0}).value == 1.0);
    EXPECT_FLOAT_EQ(static_cast<q_g>(1.0_q_kg).value, 1000.0);
}

TEST(Mass, addition_of_quantities_with_same_id)
{
    constexpr auto result = 1.0_q_kg + 1000.0_q_g;
    static_assert(result.value == 2.0);
}

TEST(Mass, subtraction_of_quantities_with_same_id)
{
    constexpr auto result = 1.0_q_kg - 1000.0_q_g;
    static_assert(result.value == 0.0);
}

TEST(Mass, comparison_of_quantities_with_same_id)
{
    static_assert(1.0_q_kg == 1000.0_q_g);
    static_assert(1.0_q_kg <= 1000.0_q_g);
    static_assert(1.0_q_kg >= 1000.0_q_g);
    static_assert(1.0_q_kg != 100.0_q_g);
    static_assert(1.0_q_kg < 10000.0_q_g);
    static_assert(1.0_q_kg > 100.0_q_g);
}

// TEST(Time, to_q_x)
// {
//     static_assert(to_q_s(q_hour{1.0}).value == 3600.0);
//     static_assert(to_q_hour(q_hour{1.0}).value == 1.0);
//     static_assert(to_q_hour(q_hour{2.0}).value == 2.0);
//     static_assert(to_q_hour(q_s{3600.0}).value == 1.0);
//     static_assert(to_q_day(q_hour{24.0}).value == 1.0);

//     auto result = to_q_time<q_time::min>(q_hour{1.0}).value;
//     EXPECT_FLOAT_EQ(result, 60.0);

//     result = to_q_time<q_time::s>(q_min{1.0}).value;
//     EXPECT_FLOAT_EQ(result, 60.0);
// }

//*********************************LENGTH****************************************

TEST(Length, static_cast_q_km)
{
    static_assert(static_cast<q_km>(1.0_q_km).value == 1.0);
    static_assert(static_cast<q_km>(1000.0_q_m).value == 1.0);
}
TEST(Length, static_cast_all)
{
    EXPECT_FLOAT_EQ(static_cast<q_m>(1.0_q_m).value, 1.0);
    EXPECT_FLOAT_EQ(static_cast<q_km>(1.0_q_m).value, 0.001);
    EXPECT_FLOAT_EQ(static_cast<q_m>(1.0_q_km).value, 1000.0);
    static_assert(static_cast<q_m>(100.0_q_m).value == 100.0);
    EXPECT_FLOAT_EQ(static_cast<q_cm>(1.0_q_dm).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_cm>(1.0_q_m).value, 100.0);
    EXPECT_FLOAT_EQ(static_cast<q_mm>(1.0_q_cm).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_mm>(1.0_q_in).value, 25.4);
    EXPECT_FLOAT_EQ(static_cast<q_cm>(1.0_q_in).value, 2.54);
    EXPECT_FLOAT_EQ(static_cast<q_mil>(1.0_q_in).value, 1000.0);

    EXPECT_FLOAT_EQ(static_cast<q_Zm>(1.0_q_Ym).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_Em>(1.0_q_Zm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_Pm>(1.0_q_Em).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_Tm>(1.0_q_Pm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_Gm>(1.0_q_Tm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_Mm>(1.0_q_Gm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_km>(1.0_q_Mm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_hm>(1.0_q_km).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_dam>(1.0_q_hm).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_m>(1.0_q_dam).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_dm>(1.0_q_m).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_cm>(1.0_q_dm).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_mm>(1.0_q_cm).value, 10.0);
    EXPECT_FLOAT_EQ(static_cast<q_um>(1.0_q_mm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_nm>(1.0_q_um).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_pm>(1.0_q_nm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_fm>(1.0_q_pm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_am>(1.0_q_fm).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_zm>(1.0_q_am).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_ym>(1.0_q_zm).value, 1000.0);
}

TEST(Speed, speed)
{
    constexpr q_mps speed = 1.0_q_m / 2.0_q_s;
    static_assert(speed.value == 0.5);

    constexpr q_mps speed_2 = speed * 2.0;
    static_assert(speed_2.value == 1.0);

    constexpr q_mps speed3 = static_cast<q_mps>(3.6_q_kmph);
    EXPECT_FLOAT_EQ(speed3.value, 1.0);

    constexpr q_kmph speed4 = static_cast<q_kmph>(1.0_q_mps);
    EXPECT_FLOAT_EQ(speed4.value, 3.6);

    auto result = static_cast<QUANTITY(NUMERATOR(q_scalar::unit_none, q_length::unit_m),
                                       DENOMINATOR(q_scalar::unit_none, q_time::hour))>(0.5_q_mps + 0.5_q_mps)
                      .value;
    EXPECT_FLOAT_EQ(result, 3600.0);

    EXPECT_FLOAT_EQ(static_cast<q_mps>(1.0_q_kmph).value, 1 / 3.6);

    EXPECT_FLOAT_EQ(static_cast<q_kmph>(1.0_q_mps).value, 3.6);
}

//*********************************FORCE****************************************
TEST(Force, cast_to_q_N_1)
{
    EXPECT_FLOAT_EQ(static_cast<q_N>(1.0_q_N).value, 1.0);

    constexpr auto f1 = 2.0_q_kg * 1.0_q_m / (1.0_q_s * 1.0_q_s);
    constexpr Quantity<TypeList<q_scalar::unit_k, q_mass::g, q_length::unit_m>,
                       TypeList<q_scalar::unit_none, q_time::s, q_time::s>>
        f2{2.0};
    static_assert(f1 == f2);
    EXPECT_FLOAT_EQ(static_cast<q_N>(2.0_q_kg * 1.0_q_m / (1.0_q_s * 1.0_q_s)).value, 2.0);
    static_assert(static_cast<q_N>(1.0_q_kg * 2.0_q_m / (1.0_q_s * 1.0_q_s)).value == 2.0);
    static_assert(static_cast<q_N>(1.0_q_kg * 2.0_q_m / (2.0_q_s * 1.0_q_s)).value == 1.0);
    static_assert(static_cast<q_N>(1.0_q_kg * 60.0_q_m / (static_cast<q_s>(1.0_q_min) * 1.0_q_s)).value == 1.0);
}

TEST(Force, cast_to_q_N_2)
{
    constexpr auto mass = 1000.0_q_g;
    constexpr auto length = 100.0_q_cm;
    constexpr auto time_1 = 1.0_q_s;
    constexpr auto time_2 = 1.0_q_s;
    constexpr auto some_value_convertible_to_force = mass * length / (time_1 * time_2);
    constexpr q_N newtons = static_cast<q_N>(some_value_convertible_to_force);

    EXPECT_FLOAT_EQ(
        newtons.value,
        (static_cast<q_kg>(mass) * static_cast<q_m>(length) / (static_cast<q_s>(time_1) * static_cast<q_s>(time_2)))
            .value);
}

TEST(Force, conversions)
{
    auto result = static_cast<q_N>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1.0);

    result = static_cast<decltype(1.0_q_g * 1.0_q_m / (1.0_q_s * 1.0_q_s))>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1000.0);

    result = static_cast<decltype(1.0_q_kg * 1.0_q_mm / (1.0_q_s * 1.0_q_s))>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 1000.0);

    result = static_cast<decltype(1.0_q_m * 1.0_q_kg / (1.0_q_s * 1.0_q_s))>(2.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 2.0);

    result = static_cast<decltype(1.0_q_m * 1.0_q_kg / (1.0_q_s * 1.0_q_min))>(1.0_q_N).value;
    EXPECT_FLOAT_EQ(result, 60.0);
}

TEST(Force, inversion)
{
    constexpr auto inverse_acceleration = 2 / 1.0_q_mps2;
    constexpr auto inverse_mass = 5 / 1.0_q_kg;
    constexpr auto inverse_force = inverse_acceleration * inverse_mass;
    static_assert(1.0 / inverse_force == 0.1_q_N);
}

TEST(Conversions, uncomment_to_fail)
{
    // to_q_s(1.0_q_m);
    // static_assert(static_cast<q_mass::kg>(100.0_q_m).value == 100.0);
    //1.0_q_m + 1.0_q_J;
    //1.0_q_m - 1.0_q_J;
    //static_assert(1.0_q_kg == 1000.0_q_m);
    // static_assert(1.0_q_kg <= 1000.0_q_m);
    // static_assert(1.0_q_kg != 1000.0_q_m);
    // static_assert(1.0_q_kg < 1000.0_q_m);
    // static_assert(1.0_q_kg > 1000.0_q_m);
    // static_assert(1.0_q_kg >= 1000.0_q_m);
}

TEST(energy, conversions)
{
    constexpr auto pot_energy = 10.0_q_kg * 10.0_q_m * 9.81_q_m / (1.0_q_s * 1.0_q_s);
    auto pot_energy_value = pot_energy.value;

    constexpr q_J conversion = pot_energy;

    EXPECT_FLOAT_EQ(pot_energy_value, 10.0 * 10.0 * 9.81 / (1.0 * 1.0));

    static_assert(static_cast<q_J>(1.0_q_J).value == 1.0);
    constexpr auto grav_acc = 10.0_q_mps / 1.0_q_s;
    constexpr auto height = 10.0_q_m;
    constexpr auto mass = 10.0_q_g;
    static_assert(static_cast<q_J>(1.0_q_J + 2.0_q_N * 2.5_q_m - grav_acc * height * mass).value == 5.0);

    static_assert(static_cast<q_kJ>(1.0_q_kJ).value == 1.0);
    static_assert(static_cast<q_MJ>(1.0_q_kJ).value == 0.001);
    static_assert(static_cast<q_MJ>(1000.0_q_kJ).value == 1.0);

    EXPECT_FLOAT_EQ(static_cast<q_kJ>(1.0_q_J * 1000.0 + 1.0_q_kJ).value, 2.0);
    EXPECT_FLOAT_EQ(static_cast<q_kJ>(1000.0 * 1.0_q_J + 1.0_q_kJ).value, 2.0);
    EXPECT_FLOAT_EQ(static_cast<q_MJ>(1.0_q_GJ).value, 1000.0);
    EXPECT_FLOAT_EQ(static_cast<q_GJ>(1000.0_q_MJ).value, 1.0);
    EXPECT_FLOAT_EQ(static_cast<q_MJ>(1.0_q_MJ).value, 1.0);
    EXPECT_FLOAT_EQ(static_cast<q_J>(1.0_q_MJ).value, 1000000.0);

    static_assert(1.0_q_kJ + 1000.0_q_J == 2.0_q_kJ);
    static_assert(1000.0_q_J + 1.0_q_kJ == 2000.0_q_J);
    static_assert(1000.0 * 1.0_q_kJ <= 1.0_q_MJ);

    static_assert(static_cast<q_scalar::q_none>(1.0_q_MJ / 1.0_q_kJ).value == 1000.0);
}

TEST(energy, comparisons)
{
    static_assert(1.0_q_MJ == 1000.0_q_kJ);
    static_assert(1.0_q_MJ != 1000.1_q_MJ);
    static_assert(1.0_q_kJ < 1.0_q_MJ);
    static_assert(1.0_q_kJ > 1.0_q_J);
}

TEST(energy, energy_to_force)
{
    static_assert(1.0_q_N == 1.0_q_J / 1.0_q_m);
}

TEST(energy, energy_to_mass)
{
    static_assert(1.0_q_kg == 1.0_q_J / (1.0_q_m * 1.0_q_mps2));
}

TEST(ComplexConversions, energy)
{
    constexpr auto g = 9.81_q_mps2;
    constexpr auto m = 1.0_q_kg + 2.0_q_N / 0.5_q_mps2;
    constexpr auto h = 2.0_q_m - 100.0_q_cm;
    constexpr auto potential_energy = m * g * h;
    static_assert(potential_energy.value == 5 * 9.81);

    constexpr auto kinetic_energy = 4.0_q_mps * 4.0_q_mps * 1 / 16 * 2.0_q_kg * 1 / 2;
    static_assert(kinetic_energy.value == 1);

    constexpr auto work = 1.3_q_N * 0.3_q_m;
    static_assert(work.value == 1.3 * 0.3);

    constexpr auto total_energy = potential_energy - kinetic_energy + work;

    static_assert(total_energy == (5 * 9.81 - 1 + 1.3 * 0.3) * 1.0_q_J);
}
