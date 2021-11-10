#include <gtest/gtest.h>
#include <test_types.hpp>
#include <are_types_same_if_instances_are_equal.hpp>

TEST(areTypesSameIfInstancesAreEqual, same_types)
{
    areTypesSameIfInstancesAreEqual<int, int>();
}

TEST(areTypesSameIfInstancesAreEqual, different_types)
{
    areTypesSameIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2, T1>>();
}

// TEST(areTypesSameIfInstancesAreEqual, static_assertion_fails_when_uncommented)
// {
//     areTypesSameIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2>>() ==false;
// }
