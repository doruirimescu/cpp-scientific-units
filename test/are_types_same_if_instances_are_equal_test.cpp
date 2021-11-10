#include <gtest/gtest.h>
#include <test_types.hpp>
#include <are_types_equal_if_instances_are_equal.hpp>

TEST(areTypesEqualIfInstancesAreEqual, same_types)
{
    areTypesEqualIfInstancesAreEqual<int, int>();
}

TEST(areTypesEqualIfInstancesAreEqual, different_types)
{
    areTypesEqualIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2, T1>>();
}

// TEST(areTypesEqualIfInstancesAreEqual, static_assertion_fails_when_uncommented)
// {
//     areTypesEqualIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2>>() ==false;
// }
