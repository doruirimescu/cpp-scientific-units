#pragma once

#include <math.h>
#include <string>
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
