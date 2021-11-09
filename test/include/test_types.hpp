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



struct Area_m_m : public Orderable<double>
{
public:
    constexpr explicit Area_m_m(double val)
        : Orderable<double>::Orderable(val)
    {
        this->value = 20;
    }
};
