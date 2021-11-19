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
 * copies.
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
#include <quantity/orderable.hpp>
namespace prefix
{
constexpr int yotta = 24;

constexpr int zetta = 21;

constexpr int exa = 18;

constexpr int peta = 15;

constexpr int tera = 12;

constexpr int giga = 9;

constexpr int mega = 6;

constexpr int kilo = 3;

constexpr int hecto = 2;

constexpr int deca = 1;

constexpr int none = 0;

constexpr int deci = -1;

constexpr int centi = -2;

constexpr int milli = -3;

constexpr int micro = -6;

constexpr int nano = -9;

constexpr int pico = -12;

constexpr int femto = -15;

constexpr int atto = -18;

constexpr int zepto = -21;

constexpr int yocto = -24;

}  // namespace prefix
