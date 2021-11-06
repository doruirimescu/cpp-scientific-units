#pragma once
#include "prefix.hpp"

enum class UnitNameLabel
{
    second,
    meter,
    gram,
    hertz
};

std::string unitNameToString(UnitNameLabel label);

template <typename T, UnitNameLabel Name, typename Prefix = none_type>
class Unit
{
private:
    Prefix prefix_;
    UnitNameLabel name_;

public:
    T value_;
    constexpr explicit Unit(T value)
        : value_(value)
    {
        name_ = Name;
    }

    T calculateValueNonPrefix() const
    {
        return value_ * prefix_.value;
    }

    std::string getPrefix() const
    {
        return prefix_.name;
    }

    std::string getUnitName() const
    {
        return unitNameToString(name_);
    }

    constexpr bool operator==(const Unit<T, Name, Prefix>& other) const
    {
        return value_ == other.value_;
    }
    template<typename Prefix2>
    constexpr bool operator==(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() == other.calculateValueNonPrefix();
    }

    constexpr bool operator<(const Unit<T, Name, Prefix>& other) const
    {
        return value_ < other.value_;
    }

    constexpr bool operator>(const Unit<T, Name, Prefix>& other) const
    {
        return value_ > other.value_;
    }

    constexpr bool operator<=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ <= other.value_;
    }

    constexpr bool operator>=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ >= other.value_;
    }

    constexpr bool operator!=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ != other.value_;
    }

    constexpr Unit<T, Name, Prefix> operator+(const Unit<T, Name, Prefix>& other) const
    {
        return Unit<T, Name, Prefix>(value_ + other.value_);
    }

    //operator + for same Unit with different prefix_
    template <typename Prefix2>
    constexpr Unit<T, Name, none_type> operator+(const Unit<T, Name, Prefix2>& other) const
    {
        auto new_value = calculateValueNonPrefix() + other.calculateValueNonPrefix();
        Unit<T, Name, none_type> new_unit(new_value);
        return new_unit;
    }

    constexpr Unit<T, Name, none_type> operator-(const Unit<T, Name, Prefix>& other) const
    {
        return Unit<T, Name, none_type>(calculateValueNonPrefix() - other.calculateValueNonPrefix());
    }

    //operator + for same Unit with different prefix_
    template <typename Prefix2>
    constexpr Unit<T, Name, none_type> operator-(const Unit<T, Name, Prefix2>& other) const
    {
        return Unit<T, Name, none_type>(calculateValueNonPrefix() - other.calculateValueNonPrefix());
    }

    constexpr Unit<T, Name, Prefix>& operator+=(const Unit<T, Name, Prefix>& other)
    {
        value_ += other.value_;
        return *this;
    }

    constexpr Unit<T, Name, Prefix>& operator-=(const Unit<T, Name, Prefix>& other)
    {
        value_ -= other.value_;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Unit<T, Name, Prefix>& unit)
    {
        os << unit.value_;
        return os;
    }
};

//Division operator double with second
template <typename T, typename Prefix>
Unit<T, UnitNameLabel::hertz, Prefix> operator/(double value_, const Unit<T, UnitNameLabel::second, Prefix>& unit)
{
    return Unit<T, UnitNameLabel::hertz, Prefix>(value_ / unit.calculateValueNonPrefix());
}

using meter = Unit<double, UnitNameLabel::meter, none_type>;
using milimeter = Unit<double, UnitNameLabel::meter, milli_type>;
using centimeter = Unit<double, UnitNameLabel::meter, centi_type>;
using kilometer = Unit<double, UnitNameLabel::meter, kilo_type>;

using second = Unit<double, UnitNameLabel::second, none_type>;

using ton = Unit<double, UnitNameLabel::gram, mega_type>;

using gram = Unit<double, UnitNameLabel::gram, none_type>;

using kilogram = Unit<double, UnitNameLabel::gram, kilo_type>;
using milligram = Unit<double, UnitNameLabel::gram, milli_type>;


//User-defined literals
constexpr meter operator""_m(long double value)
{
    return meter(value);
}

constexpr centimeter operator""_cm(long double value)
{
    return centimeter(value);
}

constexpr milimeter operator""_mm(long double value)
{
    return milimeter(value);
}

constexpr kilometer operator""_km(long double value)
{
    return kilometer(value);
}

constexpr second operator""_s(long double value)
{
    return second(value);
}

constexpr ton operator""_T(long double value)
{
    return ton(value);
}

constexpr kilogram operator""_kg(long double value)
{
    return kilogram(value);
}

constexpr gram operator""_g(long double value)
{
    return gram(value);
}

constexpr milligram operator""_mg(long double value)
{
    return milligram(value);
}
