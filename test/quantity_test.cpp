#include <gtest/gtest.h>
#include <test_types.hpp>

TEST(Quantity, multiplication_1)
{
    constexpr Quantity<TypeList<m, m>, TypeList<>> square_meter{10};
    constexpr Quantity<TypeList<>, TypeList<s>> hertz{1};

    constexpr auto result = square_meter * hertz;
    constexpr auto expect_numerator = TypeList<m, m>{};
    constexpr auto expect_denominator = TypeList<s>{};
    EXPECT_EQ(result.numerator, expect_numerator);
    EXPECT_EQ(result.denominator, expect_denominator);
    EXPECT_EQ(result.value, 10);
}

TEST(Quantity, multiplication_2)
{
    Quantity<TypeList<m, kg>, TypeList<>> q1{10};
    Quantity<TypeList<>, TypeList<s, s, kg>> q2{5};
    const auto newton = q1 * q2;
    const auto expected_newton_numerator = TypeList<m>{};
    const auto expected_newton_denominator = TypeList<s, s>{};
    EXPECT_EQ(newton.numerator, expected_newton_numerator);
    EXPECT_EQ(newton.denominator, expected_newton_denominator);
    EXPECT_EQ(newton.value, 50);
}

TEST(Quantity, multiplication_3)
{
    Quantity<TypeList<>, TypeList<>> unitless_1{1};
    Quantity<TypeList<>, TypeList<>> unitless_2{2};
    const auto result = unitless_1 * unitless_2;
    const auto expected_numerator = TypeList<>{};
    const auto expected_denominator = TypeList<>{};
    EXPECT_EQ(result.numerator, expected_numerator);
    EXPECT_EQ(result.denominator, expected_denominator);
    EXPECT_EQ(result.value, 2);
}
