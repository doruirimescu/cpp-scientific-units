#pragma once
#include "prefix.hpp"
#include <quantity.hpp>
#include <type_list.hpp>

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
    Prefix prefix_{};
    UnitNameLabel name_;

public:
    T value_;
    constexpr explicit Unit(const T value)
        : value_(value), name_ (Name)
    {
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
    template <typename Prefix2>
    constexpr bool operator==(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() == other.calculateValueNonPrefix();
    }

    constexpr bool operator<(const Unit<T, Name, Prefix>& other) const
    {
        return value_ < other.value_;
    }
    template <typename Prefix2>
    constexpr bool operator<(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() < other.calculateValueNonPrefix();
    }

    constexpr bool operator>(const Unit<T, Name, Prefix>& other) const
    {
        return value_ > other.value_;
    }
    template <typename Prefix2>
    constexpr bool operator>(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() > other.calculateValueNonPrefix();
    }

    constexpr bool operator<=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ <= other.value_;
    }
    template <typename Prefix2>
    constexpr bool operator<=(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() <= other.calculateValueNonPrefix();
    }

    constexpr bool operator>=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ >= other.value_;
    }
    template <typename Prefix2>
    constexpr bool operator>=(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() >= other.calculateValueNonPrefix();
    }

    constexpr bool operator!=(const Unit<T, Name, Prefix>& other) const
    {
        return value_ != other.value_;
    }
    template <typename Prefix2>
    constexpr bool operator!=(const Unit<T, Name, Prefix2>& other) const
    {
        return calculateValueNonPrefix() != other.calculateValueNonPrefix();
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

    //operator - for same Unit with different prefix_
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

    //! Multiplication of units results in a quantity
    template <typename T2, UnitNameLabel Name2, typename Prefix2>
    constexpr decltype(auto) operator*(const Unit<T2, Name2, Prefix2>& other) const
    {
        using current_unit_type_list = TypeList<Unit<T, Name, Prefix>>;
        using other_unit_type_list = TypeList<Unit<T2, Name2, Prefix2>>;

        const auto current_quantity = Quantity<current_unit_type_list, TypeList<>>{this->value_};
        const auto other_quantity = Quantity<other_unit_type_list, TypeList<>>{other.value_};

        return current_quantity * other_quantity;
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
constexpr meter operator""_u_m(long double value)
{
    return meter(value);
}

constexpr centimeter operator""_u_cm(long double value)
{
    return centimeter(value);
}

constexpr milimeter operator""_u_mm(long double value)
{
    return milimeter(value);
}

constexpr kilometer operator""_u_km(long double value)
{
    return kilometer(value);
}

constexpr second operator""_u_s(long double value)
{
    return second(value);
}

constexpr ton operator""_u_T(long double value)
{
    return ton(value);
}

constexpr kilogram operator""_u_kg(long double value)
{
    return kilogram(value);
}

constexpr gram operator""_u_g(long double value)
{
    return gram(value);
}

constexpr milligram operator""_u_mg(long double value)
{
    return milligram(value);
}
