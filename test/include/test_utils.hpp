#pragma once
#include <are_types_equal_if_instances_are_equal.hpp>

template <typename ToCompare, typename T>
constexpr bool compareTypes(const T& object)
{
    areTypesEqualIfInstancesAreEqual<ToCompare, T>();
    return true;
}
