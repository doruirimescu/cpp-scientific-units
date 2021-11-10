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
template <class Numerator, class Denominator>
struct Quantity : public Orderable<double>
{
    constexpr explicit Quantity(const double value)
        : Orderable<double>::Orderable(value)
    {
    }
    const Numerator numerator{};
    const Denominator denominator{};

    template <typename N2, typename D2>
    constexpr decltype(auto) operator*(const Quantity<N2, D2>& other) const
    {
        const auto num_sum = numerator + other.numerator;
        const auto den_sum = denominator + other.denominator;
        const auto num = num_sum - den_sum;
        const auto den = den_sum - num_sum;
        return Quantity<decltype(num), decltype(den)>{this->value * other.value};
    }

    template <typename N2, typename D2>
    constexpr decltype(auto) operator/(const Quantity<N2, D2>& other) const
    {
        return (*this) * Quantity<D2, N2>{1.0 / other.value};
    }

    constexpr Quantity<Numerator, Denominator> operator+(const Quantity<Numerator, Denominator>& other) const
    {
        auto new_quantity = *this;
        new_quantity.value = this->value + other.value;
        return new_quantity;
    }
};
