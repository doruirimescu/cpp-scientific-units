#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <orderable.hpp>
namespace q_time
{
struct s : public prefix::none
{
};
struct ms : public prefix::milli
{
};
struct us : public prefix::micro
{
};
struct ns : public prefix::nano
{
};
struct ps : public prefix::pico
{
};
struct fs : public prefix::femto
{
};

struct min : public Orderable<double>
{
    static constexpr double value = 60;
};
struct hour : public Orderable<double>
{
    static constexpr double value = 3600;
};

struct day : public Orderable<double>
{
    static constexpr double value = 86400;
};

struct year : public Orderable<double>
{
    static constexpr double value = 31536000;
};

}  // namespace q_time

using q_s = Quantity<TypeList<q_time::s>, TypeList<>>;
using q_ms = Quantity<TypeList<q_time::ms>, TypeList<>>;
using q_us = Quantity<TypeList<q_time::us>, TypeList<>>;
using q_ns = Quantity<TypeList<q_time::ns>, TypeList<>>;
using q_ps = Quantity<TypeList<q_time::ps>, TypeList<>>;
using q_fs = Quantity<TypeList<q_time::fs>, TypeList<>>;
using q_min = Quantity<TypeList<q_time::min>, TypeList<>>;
using q_hour = Quantity<TypeList<q_time::hour>, TypeList<>>;
using q_day = Quantity<TypeList<q_time::day>, TypeList<>>;
using q_year = Quantity<TypeList<q_time::year>, TypeList<>>;

// Time user-defined literal
constexpr q_s operator"" _q_s(long double v)
{
    return q_s{static_cast<double>(v)};
}
constexpr q_ms operator"" _q_ms(long double v)
{
    return q_ms{static_cast<double>(v)};
}
constexpr q_us operator"" _q_us(long double v)
{
    return q_us{static_cast<double>(v)};
}
constexpr q_ns operator"" _q_ns(long double v)
{
    return q_ns{static_cast<double>(v)};
}
constexpr q_ps operator"" _q_ps(long double v)
{
    return q_ps{static_cast<double>(v)};
}
constexpr q_fs operator"" _q_fs(long double v)
{
    return q_fs{static_cast<double>(v)};
}
constexpr q_min operator"" _q_min(long double v)
{
    return q_min{static_cast<double>(v)};
}
constexpr q_hour operator"" _q_hour(long double v)
{
    return q_hour{static_cast<double>(v)};
}
constexpr q_day operator"" _q_day(long double v)
{
    return q_day{static_cast<double>(v)};
}
constexpr q_year operator"" _q_year(long double v)
{
    return q_year{static_cast<double>(v)};
}

// Time conversions
template <typename Time>
constexpr q_s to_q_s(const Quantity<TypeList<Time>, TypeList<>>& v)
{
    return q_s{v.value * Time::value};
}

template <typename Time>
constexpr q_ms to_q_ms(const Quantity<TypeList<Time>, TypeList<>>& v)
{
    const auto in_seconds = to_q_s(v);
    return q_ms{in_seconds.value * 1000.0};
}

template <typename Time>
constexpr q_min to_q_min(const Quantity<TypeList<Time>, TypeList<>>& v)
{
    const auto in_seconds = to_q_s(v);
    return q_min{in_seconds.value / q_time::min::value};
}

template <typename Time>
constexpr q_hour to_q_hour(const Quantity<TypeList<Time>, TypeList<>>& v)
{
    const auto in_seconds = to_q_s(v);
    return q_hour{in_seconds.value / q_time::hour::value};
}
