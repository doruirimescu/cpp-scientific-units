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
 * @file   is_type_in_type_list.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file defines the templates for isTypeInTypeList.
 */

#pragma once

/**
 * @brief Checks if type is present in given TypeList.
 *
 * Example usage: isTypeInTypeList<T>(TypeList{T, U, V}); returns true.
 * @tparam Type : Type to be checked.
 * @param  list : TypeList to check if it contains the type.
 * @return constexpr bool : True if the TypeList contains the Type, false otherwise.
 */
template <typename Type, typename FirstArg, typename... RestOfArgs>
constexpr bool isTypeInTypeList(const TypeList<FirstArg, RestOfArgs...>& list)
{
    const bool result = std::is_same<FirstArg, Type>::value ? true : isTypeInTypeList<Type>(TypeList<RestOfArgs...>{});
    return result;
}

template <typename Type, typename FirstArg>
constexpr bool isTypeInTypeList(const TypeList<FirstArg>& fa)
{
    return std::is_same<FirstArg, Type>::value;
}

template <typename Type>
constexpr bool isTypeInTypeList(const TypeList<>& fa)
{
    return false;
}
