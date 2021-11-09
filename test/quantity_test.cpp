#include <gtest/gtest.h>
#include <quantity.hpp>
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
    constexpr Quantity<TypeList<m, kg>, TypeList<>> q1{10};
    constexpr Quantity<TypeList<>, TypeList<s, s, kg>> q2{5};
    constexpr auto newton = q1 * q2;
    constexpr auto expected_newton_numerator = TypeList<m>{};
    constexpr auto expected_newton_denominator = TypeList<s, s>{};
    static_assert(newton.numerator == expected_newton_numerator);
    static_assert(newton.denominator == expected_newton_denominator);
    static_assert(newton.value == 50);
}

TEST(Quantity, multiplication_3)
{
    constexpr Quantity<TypeList<>, TypeList<>> unitless_1{1};
    constexpr Quantity<TypeList<>, TypeList<>> unitless_2{2};
    constexpr auto result = unitless_1 * unitless_2;
    constexpr auto expected_numerator = TypeList<>{};
    constexpr auto expected_denominator = TypeList<>{};
    static_assert(result.numerator == expected_numerator);
    static_assert(result.denominator == expected_denominator);
    static_assert(result.value == 2);
}

TEST(Quantity, multiplication_4)
{
    constexpr Quantity<TypeList<m>, TypeList<>> mass_1{1};
    constexpr Quantity<TypeList<m>, TypeList<>> mass_2{2};
    constexpr auto result = mass_1 * mass_2;
    static_assert(result.value == 2);
}

// TEST(Quantity, addition)
// {
//     constexpr Quantity<TypeList<m>, TypeList<>> mass_1{1};
//     constexpr Quantity<TypeList<m>, TypeList<>> mass_2{2};
//     constexpr auto result = mass_1 + mass_2;
//     static_assert(result.value == 3);
// }
