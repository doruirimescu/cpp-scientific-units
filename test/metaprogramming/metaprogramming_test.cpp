#include <gtest/gtest.h>
#include <conditional.hpp>
#include <are_types_equal.hpp>
#include <variadic.hpp>

TEST(Conditional, areTypesEqual_true)
{
    static_assert(areTypesEqual<int, int>());
}

TEST(Conditional, areTypesEqual_false)
{
    static_assert(areTypesEqual<int, double>() == false);
}

TEST(Conditional, conditional_true)
{
    typedef conditional<true, int, double>::type type;
    static_assert(areTypesEqual<type, int>());
}

TEST(Conditional, conditional_false)
{
    typedef conditional<false, int, double>::type type;
    static_assert(areTypesEqual<type, double>());
}

TEST(Conditional, CONDITIONAL)
{
    CONDITIONAL(false, int, double);
    static_assert(areTypesEqual<conditional_type, double>());
}

TEST(Variadic, first_type_empty_variadic)
{
    typedef Variadic<>::first_type type;
    static_assert(areTypesEqual< type, Variadic<>>());
}

TEST(Variadic, first_type)
{
    typedef Variadic<int>::first_type type;
    static_assert(areTypesEqual< type, int>());
}

TEST(Variadic, rest_type_empty)
{
    static_assert(areTypesEqual<Variadic<>::rest_type, EMPTY_VARIADIC>());
    static_assert(areTypesEqual<Variadic<int>::rest_type, EMPTY_VARIADIC>());
}

TEST(Variadic, rest_type)
{
    static_assert(areTypesEqual<Variadic<int, double>::rest_type, Variadic<double>>());
    static_assert(areTypesEqual<Variadic<int, double, char, EMPTY_VARIADIC>::rest_type, Variadic<double, char, EMPTY_VARIADIC>>());
}

TEST(Variadic, argument_count)
{
    static_assert(EMPTY_VARIADIC::argument_count == 0);
    static_assert(Variadic<int>::argument_count == 1);
    static_assert(Variadic<int, double>::argument_count == 2);
}

TEST(Variadic, is_variadic)
{
    static_assert(EMPTY_VARIADIC::is_variadic);
    static_assert(Variadic<int, double>::is_variadic);
}
