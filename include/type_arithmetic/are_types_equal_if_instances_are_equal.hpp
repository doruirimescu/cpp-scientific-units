#pragma once

/**
 * @brief  Assert type equality based on instance equality
 *
 * Ex: areTypesEqualIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2,T1>() == true
 * @tparam T :
 * @tparam U :
 */
template<typename T, typename U>
constexpr bool areTypesEqualIfInstancesAreEqual()
{
    static_assert(T{} == U{});
    return true;
}
