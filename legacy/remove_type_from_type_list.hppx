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
 * @file   remove_type_from_type_list.hpp
 * @author Doru Irimescu
 *
 * @brief
 * This file defines the templates for removeTypeFromTypeList.
 */
#pragma once

//Forward declarations.
template <typename... ThisArgs>
struct TypeList;

/**
 * @brief  Removes all occurrences of TypeToRemove from a TypeList.
 *
 * Example: TypeList<int, char, float, int>.removeTypeFromTypeList<int>() == TypeList<char, float>
 * @tparam TypeToRemove : The type to remove from the list.
 * @param  list_to_remove_from : TypeList to remove the type from.
 * @return constexpr decltype(auto) : The resulting TypeList after having removed the type.
 */
template <typename TypeToRemove, typename FirstArg, typename... RestOfArgs>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<FirstArg, RestOfArgs...>& list_to_remove_from)
{
    const auto selected_list =
        std::conditional_t<std::is_same<FirstArg, TypeToRemove>::value, TypeList<>, TypeList<FirstArg>>{};
    auto returned = removeTypeFromTypeList<TypeToRemove>(TypeList<RestOfArgs...>{});
    return selected_list + returned;
}

template <typename TypeToRemove, typename FirstArg>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<FirstArg>& fa)
{
    const auto selected_list =
        std::conditional_t<std::is_same<FirstArg, TypeToRemove>::value, const TypeList<>, const TypeList<FirstArg>>{};
    return selected_list;
}

template<typename TypeToRemove>
constexpr decltype(auto) removeTypeFromTypeList(const TypeList<>&)
{
    return TypeList<>{};
}
