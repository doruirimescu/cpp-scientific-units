#include <gtest/gtest.h>
#include <test_types.hpp>
#include <type_list.hpp>

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
    static_assert(denominator / nominator == TypeList<s, s>{});
}
