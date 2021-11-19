#include <gtest/gtest.h>
#include <test_types.hpp>
#include <unit.hpp>
#include <prefix.hpp>
#include <id.hpp>

struct value_type
{
    static constexpr double value = 1.0;
};

constexpr auto unit_milli   = Unit<prefix::milli, value_type, SCALAR>{};
constexpr auto unit_none    = Unit<prefix::none, value_type, SCALAR>{};
constexpr auto unit_kilo    = Unit<prefix::kilo, value_type, SCALAR>{};
constexpr auto unit_mega    = Unit<prefix::mega, value_type, SCALAR>{};
constexpr auto unit_centi   = Unit<prefix::centi, value_type, SCALAR>{};
constexpr auto unit_deci    = Unit<prefix::deci, value_type, SCALAR>{};

TEST(Unit, Unit)
{
    static_assert(Unit<prefix::milli, value_type, SCALAR>::value == 0.001);
    static_assert(Unit<prefix::milli, value_type, SCALAR>::id == (int)SCALAR);
    static_assert(Unit<prefix::none, value_type, MASS>::value == 1.0);
    static_assert(Unit<prefix::kilo, value_type, MASS>::value == 1000.0);
    static_assert(Unit<prefix::kilo, value_type, MASS>::id == (int)MASS);
}

TEST(Unit, multiplication)
{
    static_assert(unit_none * unit_none == unit_none);
    static_assert(unit_kilo * unit_kilo == unit_mega);
    static_assert(unit_milli * unit_none == unit_milli);
    constexpr auto res = unit_milli * unit_kilo;
    static_assert(std::is_same<decltype(res), const Unit<prefix::none, value_type, SCALAR>>::value);
    static_assert(unit_centi * unit_deci == unit_milli);
}

TEST(Unit, divsion)
{
    static_assert(unit_kilo / unit_kilo == unit_none);
    static_assert(unit_kilo / unit_none == unit_kilo);
    static_assert(unit_none / unit_kilo == unit_milli);
    static_assert(unit_mega / unit_kilo == unit_kilo);
}

TEST(Unit, IsUnit)
{
    constexpr auto unit_milli = Unit<prefix::milli, value_type, LENGTH>{};
    constexpr auto unit_none = Unit<prefix::none, value_type, LENGTH>{};
    static_assert(IsUnit<Unit<prefix::milli, value_type, LENGTH>>::value);
    static_assert(IsUnit<int>::value == false);
}
