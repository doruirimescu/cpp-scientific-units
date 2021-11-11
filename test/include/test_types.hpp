#pragma once
#include <iostream>
#include <type_list.hpp>
#include <orderable.hpp>
#include <quantity.hpp>
struct T1
{
    static constexpr double value = 2;
    static constexpr int id = 1;
};
struct T2
{
    static constexpr double value = 2;
    static constexpr int id = 2;
};
struct T3
{
    static constexpr double value = 3;
    static constexpr int id = 3;
};
struct T4
{
    static constexpr double value = 4;
    static constexpr int id = 1;
};

struct T5
{
    static constexpr double value = 5;
    static constexpr int id = 2;
};

struct T6
{
    static constexpr double value = 6;
    static constexpr int id = 3;
};

struct T7
{
    int value = 7;
};

struct kg
{
    static constexpr int id = 30;
    static constexpr double value = 1000;
};
struct s
{
    static constexpr int id = 32;
    static constexpr double value = 1;
};

struct m
{
    static constexpr int id = 31;
    static constexpr double value = 1;
};

struct km
{
    static constexpr int id = 31;
    static constexpr double value = 1000;
};
struct h
{
    static constexpr int id = 32;
    static constexpr double value = 3600;
};
