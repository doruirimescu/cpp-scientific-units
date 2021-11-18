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
 * @file   time.hpp
 * @author Doru Irimescu
 *
 */
#pragma once
#include <quantity.hpp>
#include <type_list.hpp>
#include <prefix.hpp>
#include <orderable.hpp>
#include <id.hpp>
#include <scalar.hpp>
namespace q_time
{
struct time
{
    static constexpr int id = TIME;
};

struct s : public prefix::none, public time
{
    static constexpr double time = value;
};
struct ms : public prefix::milli, public time
{
    static constexpr double time = value;
};
struct us : public prefix::micro, public time
{
    static constexpr double time = value;
};
struct ns : public prefix::nano, public time
{
    static constexpr double time = value;
};
struct ps : public prefix::pico, public time
{
    static constexpr double time = value;
};
struct fs : public prefix::femto, public time
{
    static constexpr double time = value;
};

struct min : public time
{
    static constexpr double value = 60;
    static constexpr double time = value;
};
struct hour : public time
{
    static constexpr double value = 3600;
    static constexpr double time = value;
};

struct day : public time
{
    static constexpr double value = 86400;
    static constexpr double time = value;
};

struct year : public time
{
    static constexpr double value = 31536000;
    static constexpr double time = value;
};

}  // namespace q_time

using q_s =     Quantity<TypeList<q_scalar::none, q_time::s>,   TypeList<q_scalar::none>>;
using q_ms =    Quantity<TypeList<q_scalar::none, q_time::ms>,  TypeList<q_scalar::none>>;
using q_us =    Quantity<TypeList<q_scalar::none, q_time::us>,  TypeList<q_scalar::none>>;
using q_ns =    Quantity<TypeList<q_scalar::none, q_time::ns>,  TypeList<q_scalar::none>>;
using q_ps =    Quantity<TypeList<q_scalar::none, q_time::ps>,  TypeList<q_scalar::none>>;
using q_fs =    Quantity<TypeList<q_scalar::none, q_time::fs>,  TypeList<q_scalar::none>>;
using q_min =   Quantity<TypeList<q_scalar::none, q_time::min>, TypeList<q_scalar::none>>;
using q_hour =  Quantity<TypeList<q_scalar::none, q_time::hour>,TypeList<q_scalar::none>>;
using q_day =   Quantity<TypeList<q_scalar::none, q_time::day>, TypeList<q_scalar::none>>;
using q_year =  Quantity<TypeList<q_scalar::none, q_time::year>,TypeList<q_scalar::none>>;

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
