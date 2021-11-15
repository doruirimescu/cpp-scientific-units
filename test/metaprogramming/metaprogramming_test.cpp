#include <gtest/gtest.h>
#include <conditional.hpp>
#include <are_types_equal.hpp>
#include <metaprogramming/variadic.hpp>
#include <get_nth_type.hpp>
#include <remove_type.hpp>
#include <metaprogramming/remove_types.hpp>

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
    static_assert(areTypesEqual<conditional_t<true, int, double>, int>());
}

TEST(Conditional, conditional_false)
{
    static_assert(areTypesEqual<conditional_t<false, const int, double>, double>());
}

TEST(Conditional, conditional)
{
    static_assert(areTypesEqual<conditional_t<false, int, double>, double>());
}

TEST(Variadic, first_type_empty_variadic)
{
    typedef Variadic<>::first_type type;
    static_assert(areTypesEqual<type, Variadic<>>());
}

TEST(Variadic, first_type)
{
    typedef Variadic<int>::first_type type;
    static_assert(areTypesEqual<type, int>());
}

TEST(Variadic, rest_type_empty)
{
    static_assert(areTypesEqual<Variadic<>::rest_type, EMPTY_VARIADIC>());
    static_assert(areTypesEqual<Variadic<int>::rest_type, EMPTY_VARIADIC>());
}

TEST(Variadic, rest_type)
{
    static_assert(areTypesEqual<Variadic<int, double>::rest_type, Variadic<double>>());
    static_assert(areTypesEqual<Variadic<int, double, char, EMPTY_VARIADIC>::rest_type,
                                Variadic<double, char, EMPTY_VARIADIC>>());
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

template <typename... T>
struct TestStruct : public Variadic<T...>
{
};

TEST(Variadic, inheritance)
{
    TestStruct<int, double> test;
    static_assert(TestStruct<int, double>::argument_count == 2);
    static_assert(test.argument_count == 2);
}

TEST(Variadic, hasType)
{
    typedef TestStruct<int, double> test_1;
    typedef Variadic<char, double, int, char> test_2;
    static_assert(hasType<int, test_1>::result && hasType<int, test_1>::position == 1);
    static_assert(hasType<double, test_1>::result && hasType<double, test_1>::position == 2);
    static_assert(hasType<EMPTY_VARIADIC, test_1>::result == false);

    static_assert(hasType<char, test_2>::result && hasType<char, test_2>::position == 1);
    static_assert(hasType<EMPTY_VARIADIC, test_2>::result == false && hasType<EMPTY_VARIADIC, test_2>::position == 0);
}

TEST(combineVariadics, combineVariadics)
{
    typedef combineVariadics<Variadic<>, Variadic<>>::result test_1;
    static_assert(areTypesEqual<Variadic<>, test_1>());

    typedef combineVariadics<Variadic<int, int>, Variadic<double, double>>::result test_2;
    static_assert(areTypesEqual<Variadic<int, int, double, double>, test_2>());
}

TEST(removeTypeFromVariadic, removeTypeFromVariadic)
{
    typedef removeNthOccurrenceOfType_t<1, int, Variadic<double>> test_;
    static_assert(areTypesEqual<Variadic<double>, test_>());

    typedef removeNthOccurrenceOfType_t<1, double, Variadic<double>> test;
    static_assert(areTypesEqual<Variadic<>, test>());

    typedef removeNthOccurrenceOfType_t<1, double, Variadic<double, int, double, int>> test_1;
    static_assert(areTypesEqual<Variadic<int, double, int>, test_1>());

    typedef removeNthOccurrenceOfType_t<1, int, Variadic<double, int, double, int>> test_2;

    static_assert(areTypesEqual<Variadic<double, double, int>, test_2>());

    typedef removeNthOccurrenceOfType_t<1, char, Variadic<double, int, double, int>> test_3;

    static_assert(areTypesEqual<Variadic<double, int, double, int>, test_3>());
}

TEST(getNthType, getNthType_Variadic)
{
    static_assert(areTypesEqual<char, getNthType_t<1, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<int, getNthType_t<2, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<double, getNthType_t<3, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<Variadic<>, getNthType_t<4, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<Variadic<>, getNthType_t<5, Variadic<char, int, double>>>());
}

TEST(getNthType, getNthType_Tuple)
{
    static_assert(areTypesEqual<char, getNthType_t<1, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<int, getNthType_t<2, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<double, getNthType_t<3, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<std::tuple<>, getNthType_t<4, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<std::tuple<>, getNthType_t<5, std::tuple<char, int, double>>>());
}

TEST(RemoveType, removeType_Variadic)
{
    typedef RemoveType<double, Variadic<double, int, double, int>>::result test_1;
    static_assert(areTypesEqual<Variadic<int, int>, test_1>());

    typedef RemoveType<double, Variadic<double, double>>::result test_2;
    static_assert(areTypesEqual<Variadic<>, test_2>());
}

TEST(RemoveTypes, RemoveTypes)
{
    typedef RemoveTypes_t<Variadic<int, int, double>, Variadic<int, int, double>> test_1;
    static_assert(areTypesEqual<Variadic<>, test_1>());

    typedef RemoveTypes_t<Variadic<int, int>, Variadic<int, int, double>> test_2;
    static_assert(areTypesEqual<Variadic<double>, test_2>());

    typedef RemoveTypes_t<Variadic<int>, Variadic<int, int, double>> test_3;
    static_assert(areTypesEqual<Variadic<int, double>, test_3>());

    typedef RemoveTypes_t<Variadic<double>, Variadic<int, int, double>> test_4;
    static_assert(areTypesEqual<Variadic<int, int>, test_4>());
}
