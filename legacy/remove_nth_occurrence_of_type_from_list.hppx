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
 * @file   remove_nth_occurrence_of_type_from_list.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file defines the templates for removeNthOccurenceOfTypeFromTypeList.
 */

#pragma once
//Forward declarations.
template <typename... ThisArgs>
struct TypeList;

/**
 * @brief  Removes the Nth occurrence of a type from a TypeList.
 *
 * Example: TypeList{T1,T2,T1,T3}.removeNthOccurenceOfTypeFromTypeList<T1,2>(); returns TypeList<T1,T2,T3>{}.
 *
 * @tparam N : Nth occurrence of the type to remove.
 * @tparam TypeToRemove : The type to remove.
 * @param  list_to_remove_from : TypeList to remove the type from
 * @return constexpr decltype(auto) : The resulting TypeList after removing the type.
 */
template <int N, typename TypeToRemove, typename FirstArg, typename... Args>
constexpr decltype(auto) removeNthOccurenceOfTypeFromTypeList(const TypeList<FirstArg, Args...>& list_to_remove_from)
{
    const auto selected_list = std::conditional_t < std::is_same<FirstArg, TypeToRemove>::value && N == 1,
               const TypeList<>, const TypeList<FirstArg> > {};
    const auto n_update = std::is_same<FirstArg, TypeToRemove>::value ? N - 1 : N;
    const auto returned = removeNthOccurenceOfTypeFromTypeList<n_update, TypeToRemove>(TypeList<Args...>{});
    return selected_list + returned;
}

template <int N, typename TypeToRemove, typename FirstArg>
constexpr decltype(auto) removeNthOccurenceOfTypeFromTypeList(const TypeList<FirstArg>& list_to_remove_from)
{
    const auto selected_list = std::conditional_t < std::is_same<FirstArg, TypeToRemove>::value && N == 1,
               const TypeList<>, const TypeList<FirstArg> > {};
    return selected_list;
}

template <int N, typename TypeToRemove>
constexpr decltype(auto) removeNthOccurenceOfTypeFromTypeList(const TypeList<>& list_to_remove_from)
{
    return list_to_remove_from;
}
