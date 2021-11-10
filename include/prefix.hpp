#pragma once

#include <math.h>
#include <string>
#include <orderable.hpp>
namespace prefix
{
enum class prefix_label
{
    none,
    yocto,
    zepto,
    atto,
    femto,
    pico,
    nano,
    micro,
    milli,
    centi,
    deci,
    deca,
    hecto,
    kilo,
    mega,
    giga,
    tera,
    peta,
    exa,
    zetta,
    yotta
};

std::string prefixToString(const prefix_label prefix);
template <int E, prefix_label p>
struct prefix_struct
{
    static constexpr prefix_label label = p;
    static constexpr double value = pow(10, E);
    static inline std::string name = prefixToString(p);
};

struct yotta : public Orderable<double>
{
    explicit constexpr yotta()
        : Orderable<double>(pow(10, 24))
    {
    }
    static constexpr double value = pow(10, 24);
};

struct zetta : public Orderable<double>
{
    explicit constexpr zetta()
        : Orderable<double>(pow(10, 21))
    {
    }
};

struct exa : public Orderable<double>
{
    explicit constexpr exa()
        : Orderable<double>(pow(10, 18))
    {
    }
};

struct peta : public Orderable<double>
{
    explicit constexpr peta()
        : Orderable<double>(pow(10, 15))
    {
    }
};

struct tera : public Orderable<double>
{
    explicit constexpr tera()
        : Orderable<double>(pow(10, 12))
    {
    }
};
struct giga : public Orderable<double>
{
    explicit constexpr giga()
        : Orderable<double>(pow(10, 9))
    {
    }
};
struct mega : public Orderable<double>
{
    explicit constexpr mega()
        : Orderable<double>(pow(10, 6))
    {
    }
};
struct kilo : public Orderable<double>
{
    explicit constexpr kilo()
        : Orderable<double>(pow(10, 3))
    {
    }
    static constexpr double value = pow(10, 3);
};

struct hecto : public Orderable<double>
{
    explicit constexpr hecto()
        : Orderable<double>(pow(10, 2))
    {
    }
};

struct deca : public Orderable<double>
{
    explicit constexpr deca()
        : Orderable<double>(pow(10, 1))
    {
    }
};

struct none : public Orderable<double>
{
    explicit constexpr none()
        : Orderable<double>(1)
    {
    }
};
struct deci : public Orderable<double>
{
    explicit constexpr deci()
        : Orderable<double>(pow(10, -1))
    {
    }
};

struct centi : public Orderable<double>
{
    explicit constexpr centi()
        : Orderable<double>(pow(10, -2))
    {
    }
};

struct milli : public Orderable<double>
{
    explicit constexpr milli()
        : Orderable<double>(pow(10, -3))
    {
    }
};

struct micro : public Orderable<double>
{
    explicit constexpr micro()
        : Orderable<double>(pow(10, -6))
    {
    }
};

struct nano : public Orderable<double>
{
    explicit constexpr nano()
        : Orderable<double>(pow(10, -9))
    {
    }
};

struct pico : public Orderable<double>
{
    explicit constexpr pico()
        : Orderable<double>(pow(10, -12))
    {
    }
};

struct femto : public Orderable<double>
{
    explicit constexpr femto()
        : Orderable<double>(pow(10, -15))
    {
    }
};

struct atto : public Orderable<double>
{
    explicit constexpr atto()
        : Orderable<double>(pow(10, -18))
    {
    }
};

struct zepto : public Orderable<double>
{
    explicit constexpr zepto()
        : Orderable<double>(pow(10, -21))
    {
    }
};

struct yocto : public Orderable<double>
{
    explicit constexpr yocto()
        : Orderable<double>(pow(10, -24))
    {
    }
};

}  // namespace prefix

using yocto_type = prefix::prefix_struct<-24, prefix::prefix_label::yocto>;
using zepto_type = prefix::prefix_struct<-21, prefix::prefix_label::zepto>;
using atto_type = prefix::prefix_struct<-18, prefix::prefix_label::atto>;
using femto_type = prefix::prefix_struct<-15, prefix::prefix_label::femto>;
using pico_type = prefix::prefix_struct<-12, prefix::prefix_label::pico>;
using nano_type = prefix::prefix_struct<-9, prefix::prefix_label::nano>;
using micro_type = prefix::prefix_struct<-6, prefix::prefix_label::micro>;
using milli_type = prefix::prefix_struct<-3, prefix::prefix_label::milli>;
using centi_type = prefix::prefix_struct<-2, prefix::prefix_label::centi>;
using deci_type = prefix::prefix_struct<-1, prefix::prefix_label::deci>;
using none_type = prefix::prefix_struct<0, prefix::prefix_label::none>;
using deca_type = prefix::prefix_struct<1, prefix::prefix_label::deca>;
using hecto_type = prefix::prefix_struct<2, prefix::prefix_label::hecto>;
using kilo_type = prefix::prefix_struct<3, prefix::prefix_label::kilo>;
using mega_type = prefix::prefix_struct<6, prefix::prefix_label::mega>;
using giga_type = prefix::prefix_struct<9, prefix::prefix_label::giga>;
using tera_type = prefix::prefix_struct<12, prefix::prefix_label::tera>;
using peta_type = prefix::prefix_struct<15, prefix::prefix_label::peta>;
using exa_type = prefix::prefix_struct<18, prefix::prefix_label::exa>;
using zetta_type = prefix::prefix_struct<21, prefix::prefix_label::zetta>;
using yotta_type = prefix::prefix_struct<24, prefix::prefix_label::yotta>;

constexpr double yocto_value = yocto_type::value;
constexpr double zepto_value = zepto_type::value;
constexpr double atto_value = atto_type::value;
constexpr double femto_value = femto_type::value;
constexpr double pico_value = pico_type::value;
constexpr double nano_value = nano_type::value;
constexpr double micro_value = micro_type::value;
constexpr double milli_value = milli_type::value;
constexpr double centi_value = centi_type::value;
constexpr double deci_value = deci_type::value;
constexpr double none_value = none_type::value;
constexpr double deca_value = deca_type::value;
constexpr double hecto_value = hecto_type::value;
constexpr double kilo_value = kilo_type::value;
constexpr double mega_value = mega_type::value;
constexpr double giga_value = giga_type::value;
constexpr double tera_value = tera_type::value;
constexpr double peta_value = peta_type::value;
constexpr double exa_value = exa_type::value;
constexpr double zetta_value = zetta_type::value;
constexpr double yotta_value = yotta_type::value;
