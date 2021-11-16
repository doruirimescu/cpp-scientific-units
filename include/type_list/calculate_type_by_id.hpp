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
 * @file   calculate_type_by_id.hpp
 * @author Doru Irimescu
 *
 */
#pragma once

//Forward declarations.
template <typename... ThisArgs>
struct TypeList;

template <int id, typename RightArg, typename... RightArgs>
constexpr decltype(auto) calculateTypeById(const TypeList<RightArg, RightArgs...>& list)
{
    static_assert(RightArg::id, "Type RightArg does not have an id");
    const auto selected_list =
        std::conditional_t<RightArg::id == id, RightArg, decltype(calculateTypeById<id>(TypeList<RightArgs...>{}))>{};
    return selected_list;
}

template <int id, typename RightArg>
constexpr decltype(auto) calculateTypeById(const TypeList<RightArg>& list)
{
    static_assert(RightArg::id, "Type RightArg does not have an id");
    auto selected_list = std::conditional_t<RightArg::id == id, RightArg, TypeList<>>{};
    return selected_list;
}
