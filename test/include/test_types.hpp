#pragma once
#include <iostream>
#include <type_list.hpp>
#include <orderable.hpp>
struct T1
{
    int value = 1;
    //to string operator <<
    friend std::ostream& operator<<(std::ostream& os, const T1& t1)
    {
        os << "T1";
        return os;
    }
};
struct T2
{
    int value = 2;
    friend std::ostream& operator<<(std::ostream& os, const T2& t2)
    {
        os << "T2";
        return os;
    }
};
struct T3
{
    int value = 3;
    friend std::ostream& operator<<(std::ostream& os, const T3& t3)
    {
        os << "T3";
        return os;
    }
};
struct T4
{
    int value = 4;
    friend std::ostream& operator<<(std::ostream& os, const T4& t4)
    {
        os << "T4";
        return os;
    }
};

struct T5
{
    int value = 5;
    friend std::ostream& operator<<(std::ostream& os, const T5& t5)
    {
        os << "T5";
        return os;
    }
};

struct T6
{
    int value = 6;
    friend std::ostream& operator<<(std::ostream& os, const T6& t6)
    {
        os << "T6";
        return os;
    }
};

struct T7
{
    int value = 7;
    friend std::ostream& operator<<(std::ostream& os, const T7& t8)
    {
        os << "T7";
        return os;
    }
};

struct m
{
};
struct kg
{
};
struct s
{
};

template <class Numerator, class Denominator>
struct Quantity : public Orderable<double>
{
    constexpr Quantity(const double value)
        : Orderable<double>::Orderable(value)
    {
    }
    const Numerator numerator{};
    const Denominator denominator{};

    template <typename N2, typename D2>
    constexpr decltype(auto) operator*(const Quantity<N2, D2>& other) const
    {
        return Quantity<decltype(numerator + other.numerator - other.denominator), decltype(denominator + other.denominator - numerator)>{this->value * other.value};
    }

    template <typename N2, typename D2>
    constexpr decltype(auto) operator/(const Quantity<N2, D2>& other) const
    {
        return (*this) * Quantity<D2, N2>{1.0 / other.value};
    }
};

struct Area_m_m : public Orderable<double>
{
public:
    constexpr explicit Area_m_m(double val)
        : Orderable<double>::Orderable(val)
    {
        this->value = 20;
    }
};
