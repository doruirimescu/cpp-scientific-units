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
 * @file   calculate_type_list_intersection.hpp
 * @author Doru Irimescu
 *
 */
#pragma once

//Forward declarations.
template <typename... ThisArgs>
struct TypeList;

template <typename... LeftArgs, typename RightArg, typename... RightArgs>
constexpr decltype(auto) calculateTypeListIntersection(const TypeList<LeftArgs...>& left_list,
                                                       const TypeList<RightArg, RightArgs...>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    const auto selected_list = std::conditional_t<is_first_arg_type_in_t2, TypeList<RightArg>, TypeList<>>{};
    const auto returned = calculateTypeListIntersection(left_list, TypeList<RightArgs...>{});
    return selected_list + returned;
}

template <typename... LeftArgs, typename RightArg>
constexpr decltype(auto) calculateTypeListIntersection(const TypeList<LeftArgs...>& left_list,
                                                       const TypeList<RightArg>& right_list)
{
    const bool is_first_arg_type_in_t2 = left_list.template hasType<RightArg>();
    const auto selected_list = std::conditional_t<is_first_arg_type_in_t2, TypeList<RightArg>, TypeList<>>{};
    return selected_list;
}
