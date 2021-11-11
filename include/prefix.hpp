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
 * @file   prefix.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file describes prefix structs.
 */

#pragma once

#include <math.h>
#include <string>
#include <orderable.hpp>
namespace prefix
{

struct yotta
{
    static constexpr double value = pow(10, 24);
};

struct zetta
{
    static constexpr double value = pow(10, 21);
};

struct exa
{
    static constexpr double value = pow(10, 18);
};

struct peta
{
    static constexpr double value = pow(10, 15);
};

struct tera
{
    static constexpr double value = pow(10, 12);
};
struct giga
{
    static constexpr double value = pow(10, 9);
};
struct mega
{
    static constexpr double value = pow(10, 6);
};
struct kilo
{
    static constexpr double value = pow(10, 3);
};

struct hecto
{
    static constexpr double value = pow(10, 2);
};

struct deca
{
    static constexpr double value = pow(10, 1);
};

struct none
{
    static constexpr double value = 1.0;
};
struct deci
{
    static constexpr double value = pow(10, -1);
};

struct centi
{
    static constexpr double value = pow(10, -2);
};

struct milli
{
    static constexpr double value = pow(10, -3);
};

struct micro
{
    static constexpr double value = pow(10, -6);
};

struct nano
{
    static constexpr double value = pow(10, -9);
};

struct pico
{
    static constexpr double value = pow(10, -12);
};

struct femto
{
    static constexpr double value = pow(10, -15);
};

struct atto
{
    static constexpr double value = pow(10, -18);
};

struct zepto
{
    static constexpr double value = pow(10, -21);
};

struct yocto
{
    static constexpr double value = pow(10, -24);
};

}  // namespace prefix
