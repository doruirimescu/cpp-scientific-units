#pragma once

template <typename T1, typename T2>
constexpr bool areTypesTheSame()
{
    return std::is_same<T1, T2>::value;
}

struct Empty
{
    typedef Empty first_type;
    typedef Empty rest_type;
};

template <typename... Args>
struct Mega
{
};


template <template <class...> class Container, class... Rest>
struct get
{
};

template <>
struct get<Mega>
{
    typedef Empty first_type;
    typedef Empty rest_type;
};

template <typename First>
struct get<Mega, First>
{
    typedef First first_type;
    typedef Empty rest_type;
};

template <typename First, typename... Rest>
struct get<Mega, First, Rest...>
{
    typedef First first_type;
    typedef get<Mega, Rest...> rest_type;
};

template <typename T, typename U>
constexpr bool isNotEmpty()
{
    return false;
}
template <typename T>
constexpr bool isNotEmpty()
{
    return not areTypesTheSame<T, Empty>();
}

template <typename T, typename Container>
constexpr bool isTypeInContainer()
{
    if (not isNotEmpty<Container>())
    {
        return false;
    }
    return areTypesTheSame<T, typename Container::first_type>() ? true : isTypeInContainer<T, typename Container::rest_type>();
}
