#include <gtest/gtest.h>
#include <test_types.hpp>
#include <type_list.hpp>
#include <length.hpp>
#include <time.hpp>

//! TYPELIST(T1) is same as TypeList<T1>{}, but is more readable. Using both here for testing.
TEST(TypeList, check)
{
    //This does compile :)
    TypeList<TypeList<TypeList<TypeList<TypeList<TypeList<TypeList<TypeList<m>>>>>>>> tl{};
}

TEST(TypeList, equality)
{
    static_assert(TypeList<>{} == TypeList<>{}, "Empty list equality");
    static_assert(TypeList<T1>{} == TypeList<T1>{}, "One element list equality");
    static_assert(TypeList<T1, T2>{} == TypeList<T1, T2>{});
    static_assert(TypeList<T2, T1>{} == TypeList<T1, T2>{}, "Order does not matter");
    static_assert(TypeList<T1, T2, T2>{} == TypeList<T2, T1, T2>{}, "Same element can be repeated");
}

TEST(TypeList, inequality)
{
    static_assert(TypeList<>{} != TypeList<T1>{}, "Empty list left inequality");
    static_assert(TypeList<T1>{} != TypeList<>{}, "Empty list right inequality");
    static_assert(TypeList<T1>{} != TypeList<T2>{}, "One element list equality");

    static_assert(TypeList<T1, T2>{} != TypeList<T1, T1>{});

    static_assert(TypeList<T2, T2>{} != TypeList<T1>{}, "");
    static_assert(TYPELIST(T1, T1, T1) != TYPELIST(T1, T2, T3));
    static_assert(TYPELIST(T1, T2, T3) != TYPELIST(T1, T1, T1));
}

TEST(TypeList, addition)
{
    static_assert(TypeList<>{} + TypeList<>{} == TypeList<>{}, "Add two empty lists");
    static_assert(TypeList<>{} + TypeList<T1>{} == TypeList<T1>{}, "Empty list neutral element for addition");
    static_assert(TypeList<T1>{} + TypeList<>{} == TypeList<T1>{}, "Empty list neutral element for addition");
    static_assert(TypeList<T1>{} + TypeList<T1>{} == TypeList<T1, T1>{});
    static_assert(TypeList<T1>{} + TypeList<T2>{} == TypeList<T1, T2>{});
}

TEST(TypeList, getSize)
{
    static_assert(TypeList<>{}.getSize() == 0, "Empty list size");
    static_assert(TypeList<T1>{}.getSize() == 1);
    static_assert(TypeList<T1, T2>{}.getSize() == 2);
    static_assert(TypeList<T1, T2, T2, T1>{}.getSize() == 4);
}

TEST(TypeList, hasType)
{
    static_assert(TypeList<>{}.hasType() == true, "");
    static_assert(TypeList<T1>{}.hasType() == false, "");
    static_assert(TypeList<T1>{}.hasType<T1>() == true, "");
    static_assert(TypeList<T1, T2, T3>{}.hasType<T3>() == true, "");
    static_assert(TypeList<T1, T2, T3>{}.hasType<T3>() == true, "");
}

TEST(TypeList, subtraction)
{
    static_assert(TypeList<>{} - TypeList<>{} == TypeList<>{}, "");
    static_assert(TypeList<T1>{} - TypeList<T1>{} == TypeList<>{}, "");
    static_assert(TypeList<T1>{} - TypeList<>{} == TypeList<T1>{}, "");
    static_assert(TypeList<T1, T2>{} - TypeList<T1>{} == TypeList<T2>{}, "");
    static_assert(TypeList<T1, T2>{} - TypeList<T2>{} == TypeList<T1>{}, "");
    static_assert(TypeList<T1, T2, T3>{} - TypeList<T1, T2>{} == TypeList<T3>{}, "");
    static_assert(TypeList<T1, T2, T3>{} - TypeList<T1>{} == TypeList<T2, T3>{}, "");
    static_assert(TYPELIST(T1, T2, T3) - TYPELIST(T2, T4, T5) == TYPELIST(T1, T3));
    static_assert(TYPELIST(m, m) + TYPELIST() - TYPELIST(s) == TYPELIST(m, m));
    static_assert(TYPELIST() + TYPELIST(s) - TYPELIST(m, m) == TYPELIST(s));
    static_assert(TYPELIST() + TYPELIST(s) - TYPELIST() == TYPELIST(s));
    static_assert(TYPELIST() + TYPELIST(s) - TYPELIST() == TYPELIST(s));
    static_assert(TypeList<s>{} - TypeList<>{} == TYPELIST(s));
    static_assert(TypeList<m, m>{} - TypeList<>{} == TypeList<m, m>{}, "");
}

TEST(TypeList, removeType)
{
    static_assert(TypeList<T1>{}.removeType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<>{}.removeType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<T1>{}.removeType() == TypeList<T1>{}, "");
    static_assert(TypeList<T1, T1, T1>{}.removeType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<T2, T1, T1, T1, T2>{}.removeType<T1>() == TypeList<T2, T2>{}, "");
}

TEST(TypeList, test_aliases)
{
    static_assert(TYPELIST(T1) == TYPELIST(T1));
    static_assert(TYPELIST(T1) + TYPELIST(T2) == TYPELIST(T1, T2));
    static_assert((TYPELIST(T1, T2, T1, T3) - TYPELIST(T1)) == TYPELIST(T2, T1, T3));
    static_assert((TYPELIST(T1, T2, T1, T3) - TYPELIST(T1, T3)) == TYPELIST(T2, T1));
}

TEST(TypeList, division)
{
    static_assert(TYPELIST(T1) / TYPELIST(T1) == TYPELIST());
    static_assert(TYPELIST(T1, T2) / TYPELIST(T1) == TYPELIST(T2));
    static_assert(TYPELIST(T1, T2, T3) / TYPELIST(T2, T4) == TYPELIST(T1, T3));
}

TEST(TestType, variousExpressions)
{
    constexpr auto t1 = TypeList<T1, T2>{};
    constexpr auto t2 = TypeList<T3, T4>{};
    constexpr auto t3 = TypeList<T1, T2>{};
    auto concat = t1 + t2;

    static_assert(t1.hasType<T1>() == true);
    static_assert(t1.hasType<T3>() == false);
    static_assert(TypeList<T1, T2, T3, T3>{} == TypeList<T3, T1, T2, T3>{});
    static_assert(TypeList<T2, T2>{} != TypeList<T2, T2, T2>{});
    static_assert(t1 == t3);
    static_assert(t1 != t3 == false);
    static_assert(TypeList<T2, T1>{} == TypeList<T1, T2>{});
    static_assert(TypeList<T2, T2>{} != TypeList<T2>{});
    static_assert(t1.calculateIntersection(t2) == TypeList<>{});
    static_assert(t1.calculateIntersection(t3) == t1);
    static_assert(TypeList<T1, T2, T3, T3>{}.calculateIntersection(TypeList<T1, T3, T3>{}) == TypeList<T3, T1, T3>{});
    static_assert(TypeList<T1, T2, T3, T3>{}.removeType<T3>() == TypeList<T1, T2>{});
    static_assert(TypeList<T1, T1, T1, T1>{}.removeType<T1>() == TypeList<>{});
    static_assert(TypeList<T1, T2>{}.removeType<T1>() == TypeList<T2>{});

    static_assert(TypeList<T1, T2, T3, T4>{} - TypeList<T1, T2>{} == TypeList<T3, T4>{});
    static_assert(TypeList<T1, T2>{} - TypeList<T1, T2>{} == TypeList<>{});

    static_assert(TypeList<T1, T2>{} - TypeList<T1, T2>{} + TypeList<T1>{} == TypeList<T1>{});
    static_assert(TypeList<T1, T1, T2>{} - TypeList<T1, T2>{} + TypeList<T1>{} == TypeList<T1, T1>{});

    static_assert(TypeList<kg>{} + TypeList<m>{} == TypeList<kg, m>{});
    static_assert(TypeList<s>{} + TypeList<s>{} == TypeList<s, s>{});

    const auto nominator = TypeList<kg>{} + TypeList<m>{} + TypeList<m>{};
    const auto denominator = TypeList<m>{} + TypeList<s>{} + TypeList<s>{};

    static_assert(nominator / denominator == TypeList<kg, m>{});
    static_assert(nominator - denominator == TypeList<kg, m>{});
    static_assert(denominator / nominator == TypeList<s, s>{});
}

TEST(TypeList, convertLists)
{
    EXPECT_FLOAT_EQ(qConvertLists(TYPELIST(T1), TYPELIST(T4)), 0.5);
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<T1, T2>{}, TypeList<T4, T5>{}), 4.0 / 20.0);

    EXPECT_FLOAT_EQ(qConvertLists(TypeList<T2, T1>{}, TypeList<T4, T5>{}), 4.0 / 20.0);

    EXPECT_FLOAT_EQ(qConvertLists(TypeList<T1>{}, TypeList<T1>{}), 1.0);

    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::hour>{}, TypeList<q_time::min>{}), 60.0);
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::ms>{}, TypeList<q_time::s>{}), 0.001);

    //Uncomment for it to fail
    // EXPECT_FLOAT_EQ(convertLists(TYPELIST(T1, T3), TYPELIST(T4)), 4.0);
    // qConvertLists(TypeList<T1>{},  TypeList<T1, T1>{});
}
