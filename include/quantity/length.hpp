#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <id.hpp>
#include <conversion.hpp>

namespace q_length
{
struct length
{
    constexpr static int id = LENGTH;
};
struct Mm : public prefix::mega, public length
{
    static constexpr double length = value;
};
struct km : public prefix::kilo, public length
{
    static constexpr double length = value;
};
struct hm : public prefix::hecto, public length
{
    static constexpr double length = value;
};
struct dam : public prefix::deca, public length
{
    static constexpr double length = value;
};
struct m : public prefix::none, public length
{
    static constexpr double length = value;
};
struct dm : public prefix::deci, public length
{
    static constexpr double length = value;
};
struct cm : public prefix::centi, public length
{
    static constexpr double length = value;
};
struct mm : public prefix::milli, public length
{
    static constexpr double length = value;
};
struct um : public prefix::micro, public length
{
    static constexpr double length = value;
};
struct nm : public prefix::nano, public length
{
    static constexpr double length = value;
};
struct pm : public prefix::pico, public length
{
    static constexpr double length = value;
};
struct fm : public prefix::femto, public length
{
    static constexpr double length = value;
};
struct am : public prefix::atto, public length
{
    static constexpr double length = value;
};
struct zm : public prefix::zepto, public length
{
    static constexpr double length = value;
};
struct ym : public prefix::yocto, public length
{
    static constexpr double length = value;
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
constexpr q_km operator"" _q_km(long double v)
{
    return q_km{static_cast<double>(v)};
}
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
template <typename ToType, typename FromType>
constexpr Quantity<TypeList<ToType>, TypeList<>> to_q_length(const Quantity<TypeList<FromType>, TypeList<>>& from)
{
    return conversion::to_q_<ToType>(from);
}
