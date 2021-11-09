#pragma once

template <typename Type, typename FirstArg, typename... RestOfArgs>
constexpr bool isTypeInTypeList(const TypeList<FirstArg, RestOfArgs...>& list)
{
    const bool result = std::is_same<FirstArg, Type>::value ? true : isTypeInTypeList<Type>(TypeList<RestOfArgs...>{});
    return result;
}

template <typename Type, typename FirstArg>
constexpr bool isTypeInTypeList(const TypeList<FirstArg>& fa)
{
    return std::is_same<FirstArg, Type>::value;
}
