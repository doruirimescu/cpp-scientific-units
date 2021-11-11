#pragma once
#include <quantity.hpp>
#include <type_list.hpp>

//Single quantity conversion. Ex. mass to mass, length to length. Not speed to speed or force to force.
namespace conversion
{
template <typename ToType, typename FromType>
constexpr Quantity<TypeList<ToType>, TypeList<>> to_q_(const Quantity<TypeList<FromType>, TypeList<>>& from)
{
    const auto from_tl = TypeList<FromType>{};
    const auto to_tl = TypeList<ToType>{};
    const double from_as_to = qConvertLists(from_tl, to_tl);
    return Quantity<TypeList<ToType>, TypeList<>>{from.value * from_as_to};
}
}
