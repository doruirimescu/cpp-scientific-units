#include <gtest/gtest.h>
#include <quantity.hpp>
#include <test_types.hpp>
#include <test_utils.hpp>


class QuantityTest : public ::testing::Test
{
public:
    using unitless = Quantity<TypeList<scalar>, TypeList<scalar>>;
    using mass = Quantity<TypeList<scalar, kg>, TypeList<scalar>>;
    using acceleration = Quantity<TypeList<scalar, m>, TypeList<scalar, s, s>>;
    using force = Quantity<TypeList<scalar, m, kg>, TypeList<scalar, s, s>>;
    using velocity = Quantity<TypeList<scalar, m>, TypeList<scalar, s>>;
    using time = Quantity<TypeList<scalar, s>, TypeList<scalar>>;
    using distance = Quantity<TypeList<scalar, m>, TypeList<scalar>>;
    using frequency = Quantity<TypeList<scalar>, TypeList<scalar, s>>;
    using energy = decltype(force{} * distance{});
};

TEST(Quantity, multiplication_1)
{
    constexpr Quantity<TypeList<scalar, m, m>, TypeList<scalar>> square_meter{10};
    constexpr Quantity<TypeList<scalar>, TypeList<scalar, s>> frequency{1};

    constexpr auto result = square_meter * frequency;
    static_assert(result.numerator == TYPELIST(scalar,m, m));
    static_assert(result.denominator == TYPELIST(scalar,s));
    EXPECT_EQ(result.value, 10);
}

TEST(Quantity, multiplication_2)
{
    constexpr Quantity<TypeList<scalar, m, kg>, TypeList<scalar>> q1{10};
    constexpr Quantity<TypeList<scalar>, TypeList<scalar, s, s, kg>> q2{5};
    constexpr auto newton = q1 * q2;
    static_assert(newton.numerator == TYPELIST(scalar,m));
    static_assert(newton.denominator == TYPELIST(scalar,s, s));
    static_assert(newton.value == 50);
}

TEST(Quantity, multiplication_3)
{
    constexpr Quantity<TypeList<scalar>, TypeList<scalar>> unitless_1{1};
    constexpr Quantity<TypeList<scalar>, TypeList<scalar>> unitless_2{2};
    constexpr auto result = unitless_1 * unitless_2;
    static_assert(result.numerator == TYPELIST(scalar));
    static_assert(result.denominator == TYPELIST(scalar));
    static_assert(result.value == 2);
}

TEST(Quantity, multiplication_4)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> left{1};
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 2);

    static_assert(result.numerator == TYPELIST(scalar,m, m));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST(Quantity, multiplication_5)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> left{2};
    constexpr Quantity<TypeList<scalar>, TypeList<scalar, m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST(scalar));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST(Quantity, multiplication_6)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar, m>> left{2};
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar, m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST(scalar));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST(Quantity, addition_1)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> left{1};
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> right{2};
    constexpr auto result = left + right;
    static_assert(result.value == 3);
    static_assert(result.numerator == TYPELIST(scalar,m));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST(Quantity, addition_2)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar, m>> left{1};
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar, m>> right{20};
    constexpr auto result = left + right;
    static_assert(result.value == 21);
    static_assert(result.numerator == TYPELIST(scalar,m));
    static_assert(result.denominator == TYPELIST(scalar,m));
}

TEST_F(QuantityTest, addition_3)
{
    constexpr auto result = distance{5} + distance{10};
    static_assert(result.value == 15);
    static_assert(result.numerator == TYPELIST(scalar,m));
    static_assert(result.denominator == TYPELIST(scalar));
    static_assert(compareTypes<distance>(result));
}

TEST(Quantity, subtraction_1)
{
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> left{1};
    constexpr Quantity<TypeList<scalar, m>, TypeList<scalar>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST(scalar,m));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST(Quantity, subtraction_2)
{
    constexpr Quantity<TypeList<scalar>, TypeList<scalar>> left{1};
    constexpr Quantity<TypeList<scalar>, TypeList<scalar>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST(scalar));
    static_assert(result.denominator == TYPELIST(scalar));
}

TEST_F(QuantityTest, general)
{
    constexpr mass object_weight{1000};
    constexpr acceleration gravitational_acceleration{9.81};

    constexpr auto result = object_weight * gravitational_acceleration;
    static_assert(result.numerator == TYPELIST(scalar,kg, m));
    static_assert(result.denominator == TYPELIST(scalar,s, s));
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
    //!velocity vel1 = distance{30} * time{1};
    velocity vel2 = distance{30} / time{1};
    //!velocity vel3 = time{1} / distance{1};
    frequency one_hz = unitless{1} / time{1};
    //!frequency fail_hz = 1/time{2};
    //!distance{2} + time{2};
    distance{2} + distance{3};
}
