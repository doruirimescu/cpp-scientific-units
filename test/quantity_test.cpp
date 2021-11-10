#include <gtest/gtest.h>
#include <quantity.hpp>
#include <test_types.hpp>

TEST(Quantity, multiplication_1)
{
    constexpr Quantity<TypeList<m, m>, TypeList<>> square_meter{10};
    constexpr Quantity<TypeList<>, TypeList<s>> hertz{1};

    constexpr auto result = square_meter * hertz;
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

template <typename ToCompare, typename T>
constexpr bool compareTypes(const T& t)
{
    return std::is_same<ToCompare, T>::value;
}
TEST(Quantity, general)
{
    using mass = Quantity<TypeList<kg>, TypeList<>>;
    using acceleration = Quantity<TypeList<m>, TypeList<s, s>>;
    using force = Quantity<TypeList<m, kg>, TypeList<s, s>>;

    constexpr mass object_weight{1000};
    constexpr acceleration gravitational_acceleration{9.81};

    std::string printout = "LAL BAL";

    static_assert(compareTypes<double>(1.0));
    static_assert(compareTypes<mass>(object_weight));

    constexpr auto result = object_weight * gravitational_acceleration;
    static_assert(result.numerator == TYPELIST(kg, m));
    static_assert(result.denominator == TYPELIST(s, s));


    force n = object_weight* gravitational_acceleration ;
    //static_assert(compareTypes<force>(n));

    //static_assert(std::is_same<decltype(object_weight * gravitational_acceleration), force>::value == true);
}
