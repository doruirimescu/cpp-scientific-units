#include <gtest/gtest.h>
#include <quantity/quantity.hpp>
#include <test_types.hpp>
#include <test_utils.hpp>
#include <q/scalar.hpp>

#include <q/length.hpp>

class QuantityTest : public ::testing::Test
{
public:
    using unitless = Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>>;
    using mass = Quantity<TypeList<q_scalar::unit_none, kg>, TypeList<q_scalar::unit_none>>;
    using acceleration = Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, s, s>>;
    using force = Quantity<TypeList<q_scalar::unit_none, m, kg>, TypeList<q_scalar::unit_none, s, s>>;
    using velocity = Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, s>>;
    using time = Quantity<TypeList<q_scalar::unit_none, s>, TypeList<q_scalar::unit_none>>;
    using distance = Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>>;
    using frequency = Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none, s>>;
    using energy = decltype(force{} * distance{});
};

TEST(Quantity, multiplication_1)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m, m>, TypeList<q_scalar::unit_none>> square_meter{10};
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none, s>> frequency{1};

    constexpr auto result = square_meter * frequency;
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m, m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none,s));
    EXPECT_EQ(result.value, 10);
}

TEST(Quantity, multiplication_2)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m, kg>, TypeList<q_scalar::unit_none>> q1{10};
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none, s, s, kg>> q2{5};
    constexpr auto newton = q1 * q2;
    static_assert(newton.numerator == TYPELIST(q_scalar::unit_none,m));
    static_assert(newton.denominator == TYPELIST(q_scalar::unit_none,s, s));
    static_assert(newton.value == 50);
}

TEST(Quantity, multiplication_3)
{
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>> unitless_1{1};
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>> unitless_2{2};
    constexpr auto result = unitless_1 * unitless_2;
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
    static_assert(result.value == 2);
}

TEST(Quantity, multiplication_4)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> left{1};
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 2);

    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m, m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST(Quantity, multiplication_5)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> left{2};
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none, m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST(Quantity, multiplication_6)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, m>> left{2};
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST(Quantity, addition_1)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> left{1};
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> right{2};
    constexpr auto result = left + right;
    static_assert(result.value == 3);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST(Quantity, addition_2)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, m>> left{1};
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none, m>> right{20};
    constexpr auto result = left + right;
    static_assert(result.value == 21);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none,m));
}

TEST_F(QuantityTest, addition_3)
{
    constexpr auto result = distance{5} + distance{10};
    static_assert(result.value == 15);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
    static_assert(compareTypes<distance>(result));
}

TEST(Quantity, subtraction_1)
{
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> left{1};
    constexpr Quantity<TypeList<q_scalar::unit_none, m>, TypeList<q_scalar::unit_none>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST(Quantity, subtraction_2)
{
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>> left{1};
    constexpr Quantity<TypeList<q_scalar::unit_none>, TypeList<q_scalar::unit_none>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none));
}

TEST_F(QuantityTest, general)
{
    constexpr mass object_weight{1000};
    constexpr acceleration gravitational_acceleration{9.81};

    constexpr auto result = object_weight * gravitational_acceleration;
    static_assert(result.numerator == TYPELIST(q_scalar::unit_none,kg, m));
    static_assert(result.denominator == TYPELIST(q_scalar::unit_none,s, s));
    static_assert(compareTypes<force>(result));

    velocity vel = distance{30} / time{1};

    constexpr auto potential_energy = mass{10} * distance{10} * acceleration{9.81};
    EXPECT_FLOAT_EQ(potential_energy.value, 10 * 10 * 9.81);

    EXPECT_FLOAT_EQ(static_cast<energy>(potential_energy).value, 10*10*9.81);
    static_assert(compareTypes<energy>(potential_energy));

    constexpr energy kinetic_energy = mass{10} * velocity{10} * velocity{10} / 2.0;
    EXPECT_FLOAT_EQ(kinetic_energy.value , 10 * 10 * 10 / 2.0);

    constexpr auto work = potential_energy + kinetic_energy + force{10} * distance{10};
    EXPECT_FLOAT_EQ(work.value , 10 * 10 * 9.81 + 10 * 10 * 10 / 2.0 + 10 * 10);
    static_assert(compareTypes<energy>(work));
}

TEST_F(QuantityTest, uncomment_each_to_see_compilation_error)
{
//     //!velocity vel1 = distance{30} * time{1};
//     velocity vel2 = distance{30} / time{1};
//     //!velocity vel3 = time{1} / distance{1};
//     frequency one_hz = unitless{1} / time{1};
//     //!frequency fail_hz = 1/time{2};
//     //!distance{2} + time{2};
//     distance{2} + distance{3};
}

TEST_F(QuantityTest, multiplication_of_scalars)
{
    using namespace q_scalar;
    constexpr auto res = 1.0_q_milli * 1.0_q_kilo * 1.0_q_nano;
    typedef Quantity<TypeList<Unit<-9, q_scalar::scalar_t, (Q_ID)7> >, TypeList<Unit<0, q_scalar::scalar_t, (Q_ID)7> > > expected;
    static_assert(compareTypes<expected>(res));
}
TEST_F(QuantityTest, multiplication_of_units)
{
    constexpr auto result = 1.0_q_m * 1.0_q_km * 1.0_q_km;
    typedef const struct Quantity<TypeList<Unit<6, q_scalar::scalar_t, (Q_ID)7>, Unit<0, q_length::meter_t, (Q_ID)2>, Unit<0, q_length::meter_t, (Q_ID)2>, Unit<0, q_length::meter_t, (Q_ID)2> >, TypeList<Unit<0, q_scalar::scalar_t, (Q_ID)7> > > expected;
    static_assert(compareTypes<expected>(result));
}

TEST_F(QuantityTest, division_of_units)
{
    constexpr auto result = 1.0_q_m / 1.0_q_km;
    typedef const struct Quantity<TypeList<Unit<-3, q_scalar::scalar_t, (Q_ID)7> >, TypeList<Unit<0, q_scalar::scalar_t, (Q_ID)7> > > expected;
    static_assert(compareTypes<expected>(result));
}
