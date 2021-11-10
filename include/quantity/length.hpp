#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <orderable.hpp>
namespace q_length
{
struct Mm : public prefix::mega
{
};
struct km : public prefix::kilo
{
};
struct hm : public prefix::hecto
{
};
struct dam : public prefix::deca
{
};
struct m : public prefix::none
{
};
struct dm : public prefix::deci
{
};
struct cm : public prefix::centi
{
};
struct mm : public prefix::milli
{
};
struct um : public prefix::micro
{
};
struct nm : public prefix::nano
{
};
struct pm : public prefix::pico
{
};
struct fm : public prefix::femto
{
};
struct am : public prefix::atto
{
};
struct zm : public prefix::zepto
{
};
struct ym : public prefix::yocto
{
};
}  // namespace q_length

// Length types
using q_km = Quantity<TypeList<q_length::km>, TypeList<>>;
using q_dam = Quantity<TypeList<q_length::dam>, TypeList<>>;
using q_m = Quantity<TypeList<q_length::m>, TypeList<>>;
using q_dm = Quantity<TypeList<q_length::dm>, TypeList<>>;
using q_cm = Quantity<TypeList<q_length::cm>, TypeList<>>;
using q_mm = Quantity<TypeList<q_length::mm>, TypeList<>>;
using q_um = Quantity<TypeList<q_length::um>, TypeList<>>;
using q_nm = Quantity<TypeList<q_length::nm>, TypeList<>>;
using q_pm = Quantity<TypeList<q_length::pm>, TypeList<>>;
using q_fm = Quantity<TypeList<q_length::fm>, TypeList<>>;
using q_am = Quantity<TypeList<q_length::am>, TypeList<>>;
using q_zm = Quantity<TypeList<q_length::zm>, TypeList<>>;
using q_ym = Quantity<TypeList<q_length::ym>, TypeList<>>;

// Length user-defined literals
constexpr q_dam operator"" _q_dam(long double v)
{
    return q_dam{static_cast<double>(v)};
}
constexpr q_m operator"" _q_m(long double v)
{
    return q_m{static_cast<double>(v)};
}
constexpr q_dm operator"" _q_dm(long double v)
{
    return q_dm{static_cast<double>(v)};
}
constexpr q_cm operator"" _q_cm(long double v)
{
    return q_cm{static_cast<double>(v)};
}
constexpr q_mm operator"" _q_mm(long double v)
{
    return q_mm{static_cast<double>(v)};
}
constexpr q_um operator"" _q_um(long double v)
{
    return q_um{static_cast<double>(v)};
}
constexpr q_nm operator"" _q_nm(long double v)
{
    return q_nm{static_cast<double>(v)};
}
constexpr q_pm operator"" _q_pm(long double v)
{
    return q_pm{static_cast<double>(v)};
}
constexpr q_fm operator"" _q_fm(long double v)
{
    return q_fm{static_cast<double>(v)};
}
constexpr q_am operator"" _q_am(long double v)
{
    return q_am{static_cast<double>(v)};
}
constexpr q_zm operator"" _q_zm(long double v)
{
    return q_zm{static_cast<double>(v)};
}
constexpr q_ym operator"" _q_ym(long double v)
{
    return q_ym{static_cast<double>(v)};
}

// Length conversions
template <typename Length>
constexpr q_m to_q_m(const Quantity<TypeList<Length>, TypeList<>>& v)
{
    return q_m{v.value * Length::value};
}

template <typename Length>
constexpr q_km to_q_km(const Quantity<TypeList<Length>, TypeList<>>& v)
{
    return q_km{to_q_m(v).value * 1000};
}
