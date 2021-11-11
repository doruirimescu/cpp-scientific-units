/**
 *
 * Copyright (c) 2021 Doru Irimescu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file   quantity.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file describes a quantity template.
 */

#pragma once
#include <orderable.hpp>
#include <are_types_equal_if_instances_are_equal.hpp>

template <typename To, typename From>
constexpr To to_any_q(const From& from)
{
    const double new_numerator = qConvertLists(From::numerator, To::numerator);
    const double new_denominator = qConvertLists(From::denominator, To::denominator);

    const double value = from.value * new_numerator / new_denominator;
    return To{value};
}

template <class Numerator, class Denominator>
struct Quantity : public Orderable<double>
{
    constexpr explicit Quantity(const double value)
        : Orderable<double>::Orderable(value)
    {
    }
    constexpr explicit Quantity()
        : Orderable<double>::Orderable(1.0)
    {
    }

    //copy assignment
    template <typename N2, typename D2>
    constexpr Quantity& operator=(const Quantity<N2, D2>& other)
    {
        //This will throw compile-time error if the types' instances are not the same
        areTypesEqualIfInstancesAreEqual<Numerator, N2>();
        areTypesEqualIfInstancesAreEqual<Denominator, D2>();

        this->value = other.value;
        return *this;
    }

    //conversion operator
    template <typename N2, typename D2>
    constexpr operator Quantity<N2, D2>() const
    {
        //This will throw compile-time error if the types' instances are not the same
        return to_any_q<Quantity<N2, D2>>(*this);
    }

    static const Numerator numerator;
    static const Denominator denominator;

    //operator ==
    template <typename N2, typename D2>
    constexpr bool operator==(const Quantity<N2, D2>& other) const
    {
        return value == other.value && numerator == other.numerator && denominator == other.denominator;
    }

    //Multiplication of quantities
    template <typename N2, typename D2>
    constexpr decltype(auto) operator*(const Quantity<N2, D2>& other) const
    {
        const auto num_sum = numerator + other.numerator;
        const auto den_sum = denominator + other.denominator;
        auto num = num_sum - den_sum;
        auto den = den_sum - num_sum;
        return Quantity<decltype(num), decltype(den)>{this->value * other.value};
    }

    //Multiplication by scalar
    constexpr Quantity<Numerator, Denominator> operator*(const double scalar) const
    {
        auto new_quantity = *this;
        new_quantity.value *= scalar;
        return (new_quantity);
    }

    template <typename N2, typename D2>
    constexpr decltype(auto) operator/(const Quantity<N2, D2>& other) const
    {
        return (*this) * Quantity<D2, N2>{1.0 / other.value};
    }

    //Division by scalar
    constexpr Quantity<Numerator, Denominator> operator/(const double scalar) const
    {
        auto new_quantity = *this;
        new_quantity.value /= scalar;
        return (new_quantity);
    }

    constexpr Quantity<Numerator, Denominator> operator+(const Quantity<Numerator, Denominator>& other) const
    {
        auto new_quantity = *this;
        new_quantity.value = this->value + other.value;
        return new_quantity;
    }

    constexpr Quantity<Numerator, Denominator> operator-(const Quantity<Numerator, Denominator>& other) const
    {
        auto new_quantity = *this;
        new_quantity.value = this->value - other.value;
        return new_quantity;
    }
};

#define NUMERATOR(...)  TypeList<__VA_ARGS__>
#define DENOMINATOR(...)  TypeList<__VA_ARGS__>

#define QUANTITY(...)  Quantity<__VA_ARGS__>
