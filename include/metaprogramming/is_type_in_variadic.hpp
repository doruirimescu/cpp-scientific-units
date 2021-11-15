#pragma once

template<typename...Args>
struct IsTypeInVariadic;

template<typename Type, template<class...> typename Variadic, typename FirstArg, typename...RestArgs>
struct IsTypeInVariadic<Type, Variadic<FirstArg, RestArgs...>>
{
    static constexpr bool value = std::is_same<FirstArg, Type>::value ? true : IsTypeInVariadic<Type, Variadic<RestArgs...>>::value;
};

template <typename Type, template<class...> typename Variadic, typename FirstArg>
struct IsTypeInVariadic<Type, Variadic<FirstArg>>
{
    static constexpr bool value = std::is_same<FirstArg, Type>::value;
};

template <typename Type, template<class...> typename Variadic>
struct IsTypeInVariadic<Type, Variadic<>>
{
    static constexpr bool value = false;
};
