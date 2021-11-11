#pragma once
#include <iostream>
#include <type_list.hpp>
#include <orderable.hpp>
#include <quantity.hpp>
struct T1
{
    static constexpr int value = 1;
    static constexpr int id = 1;
};
struct T2
{
    int value = 2;
    static constexpr int id = 2;
};
struct T3
{
    int value = 3;
    static constexpr int id = 3;
};
struct T4
{
    static constexpr int value = 4;
    static constexpr int id = 1;
};

struct T5
{
    static constexpr int value = 5;
    static constexpr int id = 2;
};

struct T6
{
    int value = 6;
    static constexpr int id = 3;
};

struct T7
{
    int value = 7;
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

struct km
{
};
struct h
{
};
