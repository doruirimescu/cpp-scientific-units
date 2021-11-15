/**
 *
 * Copyright (c) 2021 Doru Irimescu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file   metaprogramming_test.hpp
 * @author Doru Irimescu
 *
 * @brief
 * One test per file form metaprogramming folder
 */

#include <gtest/gtest.h>
#include <metaprogramming/are_types_equal.hpp>
#include <metaprogramming/are_variadics_containing_the_same_types.hpp>
#include <metaprogramming/get_nth_type.hpp>
#include <metaprogramming/remove_type.hpp>
#include <metaprogramming/remove_types.hpp>
#include <metaprogramming/is_type_in_variadic.hpp>
#include <metaprogramming/is_variadic.hpp>
template <typename... T>
struct Variadic
{
};

using EMPTY_VARIADIC = Variadic<>;

TEST(Metaprogramming, are_variadics_containing_the_same_types)
{
    static_assert(AreVariadicsContainingTheSameTypes<Variadic<>, Variadic<>>::value);
    static_assert(!AreVariadicsContainingTheSameTypes<Variadic<int>, Variadic<>>::value);
    static_assert(!AreVariadicsContainingTheSameTypes<Variadic<>, Variadic<int>>::value);
    static_assert(AreVariadicsContainingTheSameTypes<Variadic<int, double>, Variadic<double, int>>::value);
    static_assert(AreVariadicsContainingTheSameTypes<Variadic<char, int, double>, Variadic<double, int, char>>::value);
}

TEST(Metaprogramming, combine_variadics)
{
    typedef combineVariadics_t<Variadic<>, Variadic<>> test_1;
    static_assert(areTypesEqual<Variadic<>, test_1>());

    typedef combineVariadics_t<Variadic<int>, Variadic<>> test_2;
    static_assert(areTypesEqual<Variadic<int>, test_2>());

    typedef combineVariadics_t<Variadic<>, Variadic<int>> test_3;
    static_assert(areTypesEqual<Variadic<int>, test_3>());

    typedef combineVariadics_t<Variadic<int, int>, Variadic<double, double>> test_4;
    static_assert(areTypesEqual<Variadic<int, int, double, double>, test_4>());
}

TEST(Metaprogramming, get_nth_type)
{
    static_assert(areTypesEqual<Variadic<>, getNthType_t<0, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<char, getNthType_t<1, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<int, getNthType_t<2, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<double, getNthType_t<3, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<Variadic<>, getNthType_t<4, Variadic<char, int, double>>>());
    static_assert(areTypesEqual<Variadic<>, getNthType_t<5, Variadic<char, int, double>>>());

    static_assert(areTypesEqual<char, getNthType_t<1, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<int, getNthType_t<2, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<double, getNthType_t<3, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<std::tuple<>, getNthType_t<4, std::tuple<char, int, double>>>());
    static_assert(areTypesEqual<std::tuple<>, getNthType_t<5, std::tuple<char, int, double>>>());
}

TEST(Metaprogramming, is_type_in_variadic)
{
    typedef Variadic<int, double> test_1;
    typedef Variadic<char, double, int, char> test_2;
    static_assert(IsTypeInVariadic<int, test_1>::value);
    static_assert(IsTypeInVariadic<double, test_1>::value);
    static_assert(!IsTypeInVariadic<EMPTY_VARIADIC, test_1>::value);
    static_assert(!IsTypeInVariadic<EMPTY_VARIADIC, EMPTY_VARIADIC>::value);
}

TEST(Metaprogramming, is_variadic)
{
    static_assert(IsVariadic<Variadic<>>::value);
    static_assert(IsVariadic<Variadic<int, double>>::value);
    static_assert(!IsVariadic<int>::value);
    static_assert(!IsVariadic<double>::value);
}

TEST(Metaprogramming, remove_nth_occurrence_of_type)
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

TEST(Metaprogramming, remove_type)
{
    typedef removeType_t<double, Variadic<double, int, double, int>> test_1;
    static_assert(areTypesEqual<Variadic<int, int>, test_1>());

    typedef RemoveType<double, Variadic<double, double>>::type test_2;
    static_assert(areTypesEqual<Variadic<>, test_2>());

    static_assert(areTypesEqual<Variadic<>, removeType_t<double, Variadic<double, double>>>());
}

TEST(Metaprogramming, remove_types)
{
    typedef removeTypes_t<Variadic<int, int, double>, Variadic<int, int, double>> test_1;
    static_assert(areTypesEqual<Variadic<>, test_1>());

    typedef removeTypes_t<Variadic<int, int>, Variadic<int, int, double>> test_2;
    static_assert(areTypesEqual<Variadic<double>, test_2>());

    typedef removeTypes_t<Variadic<int>, Variadic<int, int, double>> test_3;
    static_assert(areTypesEqual<Variadic<int, double>, test_3>());

    typedef removeTypes_t<Variadic<double>, Variadic<int, int, double>> test_4;
    static_assert(areTypesEqual<Variadic<int, int>, test_4>());
}
