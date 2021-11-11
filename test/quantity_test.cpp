#include <gtest/gtest.h>
#include <quantity.hpp>
#include <test_types.hpp>
#include <test_utils.hpp>


class QuantityTest : public ::testing::Test
{
public:
    using unitless = Quantity<TypeList<>, TypeList<>>;
    using mass = Quantity<TypeList<kg>, TypeList<>>;
    using acceleration = Quantity<TypeList<m>, TypeList<s, s>>;
    using force = Quantity<TypeList<m, kg>, TypeList<s, s>>;
    using velocity = Quantity<TypeList<m>, TypeList<s>>;
    using time = Quantity<TypeList<s>, TypeList<>>;
    using distance = Quantity<TypeList<m>, TypeList<>>;
    using frequency = Quantity<TypeList<>, TypeList<s>>;
    using energy = decltype(force{} * distance{});
};

TEST(Quantity, multiplication_1)
{
    constexpr Quantity<TypeList<m, m>, TypeList<>> square_meter{10};
    constexpr Quantity<TypeList<>, TypeList<s>> frequency{1};

    constexpr auto result = square_meter * frequency;
    static_assert(result.numerator == TYPELIST(m, m));
    static_assert(result.denominator == TYPELIST(s));
    EXPECT_EQ(result.value, 10);
}

TEST(Quantity, multiplication_2)
{
    constexpr Quantity<TypeList<m, kg>, TypeList<>> q1{10};
    constexpr Quantity<TypeList<>, TypeList<s, s, kg>> q2{5};
    constexpr auto newton = q1 * q2;
    static_assert(newton.numerator == TYPELIST(m));
    static_assert(newton.denominator == TYPELIST(s, s));
    static_assert(newton.value == 50);
}

TEST(Quantity, multiplication_3)
{
    constexpr Quantity<TypeList<>, TypeList<>> unitless_1{1};
    constexpr Quantity<TypeList<>, TypeList<>> unitless_2{2};
    constexpr auto result = unitless_1 * unitless_2;
    static_assert(result.numerator == TYPELIST());
    static_assert(result.denominator == TYPELIST());
    static_assert(result.value == 2);
}

TEST(Quantity, multiplication_4)
{
    constexpr Quantity<TypeList<m>, TypeList<>> left{1};
    constexpr Quantity<TypeList<m>, TypeList<>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 2);
    static_assert(result.numerator == TYPELIST(m, m));
    static_assert(result.denominator == TYPELIST());
}

TEST(Quantity, multiplication_5)
{
    constexpr Quantity<TypeList<m>, TypeList<>> left{2};
    constexpr Quantity<TypeList<>, TypeList<m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST());
    static_assert(result.denominator == TYPELIST());
}

TEST(Quantity, multiplication_6)
{
    constexpr Quantity<TypeList<m>, TypeList<m>> left{2};
    constexpr Quantity<TypeList<m>, TypeList<m>> right{2};
    constexpr auto result = left * right;
    static_assert(result.value == 4);
    static_assert(result.numerator == TYPELIST());
    static_assert(result.denominator == TYPELIST());
}

TEST(Quantity, addition_1)
{
    constexpr Quantity<TypeList<m>, TypeList<>> left{1};
    constexpr Quantity<TypeList<m>, TypeList<>> right{2};
    constexpr auto result = left + right;
    static_assert(result.value == 3);
    static_assert(result.numerator == TYPELIST(m));
    static_assert(result.denominator == TYPELIST());
}

TEST(Quantity, addition_2)
{
    constexpr Quantity<TypeList<m>, TypeList<m>> left{1};
    constexpr Quantity<TypeList<m>, TypeList<m>> right{20};
    constexpr auto result = left + right;
    static_assert(result.value == 21);
    static_assert(result.numerator == TYPELIST(m));
    static_assert(result.denominator == TYPELIST(m));
}

TEST_F(QuantityTest, addition_3)
{
    constexpr auto result = distance{5} + distance{10};
    static_assert(result.value == 15);
    static_assert(result.numerator == TYPELIST(m));
    static_assert(result.denominator == TYPELIST());
    static_assert(compareTypes<distance>(result));
}

TEST(Quantity, subtraction_1)
{
    constexpr Quantity<TypeList<m>, TypeList<>> left{1};
    constexpr Quantity<TypeList<m>, TypeList<>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST(m));
    static_assert(result.denominator == TYPELIST());
}

TEST(Quantity, subtraction_2)
{
    constexpr Quantity<TypeList<>, TypeList<>> left{1};
    constexpr Quantity<TypeList<>, TypeList<>> right{2};
    constexpr auto result = left - right;
    static_assert(result.value == -1);
    static_assert(result.numerator == TYPELIST());
    static_assert(result.denominator == TYPELIST());
}

TEST_F(QuantityTest, general)
{
    constexpr mass object_weight{1000};
    constexpr acceleration gravitational_acceleration{9.81};

    constexpr auto result = object_weight * gravitational_acceleration;
    static_assert(result.numerator == TYPELIST(kg, m));
    static_assert(result.denominator == TYPELIST(s, s));
    static_assert(compareTypes<force>(result));

    velocity vel = distance{30} / time{1};

    constexpr energy potential_energy = mass{10} * distance{10} * acceleration{9.81};
    EXPECT_FLOAT_EQ(potential_energy.value, 10 * 10 * 9.81);

    constexpr energy kinetic_energy = mass{10} * velocity{10} * velocity{10} / 2.0;
    EXPECT_FLOAT_EQ(kinetic_energy.value , 10 * 10 * 10 / 2.0);

    constexpr auto work = potential_energy + kinetic_energy + force{10} * distance{10};
    EXPECT_FLOAT_EQ(work.value , 10 * 10 * 9.81 + 10 * 10 * 10 / 2.0 + 10 * 10);
    static_assert(compareTypes<energy>(work));
}

TEST_F(QuantityTest, uncomment_each_to_see_compilation_error)
{
    //velocity vel1 = distance{30} * time{1};
    velocity vel2 = distance{30} / time{1};
    //velocity vel3 = time{1} / distance{1};

    frequency one_hz = unitless{1} / time{1};

    //frequency fail_hz = 1/time{2};

    //distance{2} + time{2};
    distance{2} + distance{3};
}
