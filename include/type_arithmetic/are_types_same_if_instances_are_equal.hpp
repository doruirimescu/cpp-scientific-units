#pragma once

/**
 * @brief  Assert type equality based on instance equality
 *
 * Ex: areTypesSameIfInstancesAreEqual<TypeList<T1, T2>, TypeList<T2,T1>() == true
 * @tparam T :
 * @tparam U :
 */
template<typename T, typename U>
constexpr void areTypesSameIfInstancesAreEqual()
{
    static_assert(T{} == U{});
}
