#include <gtest/gtest.h>
#include <test_types.hpp>
#include <type_list/type_list.hpp>
#include <q/length.hpp>
#include <q/time.hpp>
#include <q/scalar.hpp>

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

TEST(TypeList, scalar_addition)
{
    static_assert(TypeList<q_scalar::unit_none>{} + TypeList<q_scalar::unit_none>{} == TypeList<q_scalar::unit_none>{});
    static_assert(TypeList<q_scalar::unit_k>{} + TypeList<q_scalar::unit_k>{} == TypeList<q_scalar::unit_M>{});
    static_assert(TypeList<q_scalar::unit_k>{} + TypeList<q_scalar::unit_m>{} == TypeList<q_scalar::unit_none>{});
    static_assert(TypeList<q_scalar::unit_c>{} + TypeList<q_scalar::unit_d>{} == TypeList<q_scalar::unit_m>{}, "Centi + deci = milli - addition of type lists means multiplication of quantities");
}

TEST(TypeList, mixed_addition)
{
    static_assert(TypeList<q_scalar::unit_none, q_length::unit_m>{} + TypeList<q_scalar::unit_none>{} == TypeList<q_scalar::unit_none, q_length::unit_m>{});
    static_assert(TypeList<q_scalar::unit_none>{} + TypeList<q_scalar::unit_none, q_length::unit_m>{} == TypeList<q_scalar::unit_none, q_length::unit_m>{});

    static_assert(TypeList<q_scalar::unit_none, q_length::unit_m>{} + TypeList<q_scalar::unit_none, q_length::unit_m>{} == TypeList<q_scalar::unit_none, q_length::unit_m, q_length::unit_m>{});
    static_assert(TypeList<q_length::unit_m, q_scalar::unit_none>{} + TypeList<q_length::unit_m, q_scalar::unit_none>{} == TypeList<q_length::unit_m, q_scalar::unit_none, q_length::unit_m, q_scalar::unit_none>{}, "If scalar is not first type in typelist, it does not add them");
}

TEST(TypeList, addition_of_scalar_units)
{
    constexpr auto new_list = TYPELIST(q_scalar::unit_k) + TYPELIST(q_scalar::unit_k);
    // static_assert(new_list == TypeList<Unit<6, q_scalar::scalar_t, SCALAR> >{});
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

TEST(TypeList, RemoveType)
{
    static_assert(TypeList<T1>{}.RemoveType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<>{}.RemoveType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<T1>{}.RemoveType() == TypeList<T1>{}, "");
    static_assert(TypeList<T1, T1, T1>{}.RemoveType<T1>() == TypeList<>{}, "");
    static_assert(TypeList<T2, T1, T1, T1, T2>{}.RemoveType<T1>() == TypeList<T2, T2>{}, "");
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
    static_assert(TypeList<T1, T2, T3, T3>{}.RemoveType<T3>() == TypeList<T1, T2>{});
    static_assert(TypeList<T1, T1, T1, T1>{}.RemoveType<T1>() == TypeList<>{});
    static_assert(TypeList<T1, T2>{}.RemoveType<T1>() == TypeList<T2>{});

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
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::s>{}, TypeList<q_time::min>{}), 1.0/60.0);
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::min>{}, TypeList<q_time::s>{}), 60.0);

    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::min, q_time::s>{}, TypeList<q_time::s, q_time::s>{}), 60.0);
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::s, q_time::min>{}, TypeList<q_time::s, q_time::s>{}), 60.0);
    EXPECT_FLOAT_EQ(qConvertLists(TypeList<q_time::s, q_time::s>{}, TypeList<q_time::s, q_time::min>{}), 1.0/60.0);

    //Uncomment for it to fail
    //! EXPECT_FLOAT_EQ(convertLists(TYPELIST(T1, T3), TYPELIST(T4)), 4.0);
    //! qConvertLists(TypeList<T1>{},  TypeList<T1, T1>{});
    //! qConvertLists(TypeList<T1>{},  TypeList<T2>{});
}
