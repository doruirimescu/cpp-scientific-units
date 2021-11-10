#pragma once

#include <math.h>
#include <string>
#include <orderable.hpp>
namespace prefix
{

struct yotta
{
    static constexpr double value = pow(10, 24);
};

struct zetta
{
    static constexpr double value = pow(10, 21);
};

struct exa
{
    static constexpr double value = pow(10, 18);
};

struct peta
{
    static constexpr double value = pow(10, 15);
};

struct tera
{
    static constexpr double value = pow(10, 12);
};
struct giga
{
    static constexpr double value = pow(10, 9);
};
struct mega
{
    static constexpr double value = pow(10, 6);
};
struct kilo
{
    static constexpr double value = pow(10, 3);
};

struct hecto
{
    static constexpr double value = pow(10, 2);
};

struct deca : public Orderable<double>
{
    static constexpr double value = pow(10, 1);
};

struct none : public Orderable<double>
{
    static constexpr double value = 1.0;
};
struct deci : public Orderable<double>
{
    static constexpr double value = pow(10, -1);
};

struct centi : public Orderable<double>
{
    static constexpr double value = pow(10, -2);
};

struct milli : public Orderable<double>
{
    static constexpr double value = pow(10, -3);
};

struct micro : public Orderable<double>
{
    static constexpr double value = pow(10, -6);
};

struct nano : public Orderable<double>
{
    static constexpr double value = pow(10, -9);
};

struct pico : public Orderable<double>
{
    static constexpr double value = pow(10, -12);
};

struct femto : public Orderable<double>
{
    static constexpr double value = pow(10, -15);
};

struct atto : public Orderable<double>
{
    static constexpr double value = pow(10, -18);
};

struct zepto : public Orderable<double>
{
    static constexpr double value = pow(10, -21);
};

struct yocto : public Orderable<double>
{
    static constexpr double value = pow(10, -24);
};

}  // namespace prefix
