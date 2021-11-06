#include <gtest/gtest.h>
#include "prefix.hpp"
using ::testing::StaticAssertTypeEq;

TEST(prefixNamespace, prefixToString)
{
    using namespace prefix;
    EXPECT_EQ(prefixToString(prefix_label::yocto), "yocto");
    EXPECT_EQ(prefixToString(prefix_label::zepto), "zepto");
    EXPECT_EQ(prefixToString(prefix_label::atto), "atto");
    EXPECT_EQ(prefixToString(prefix_label::femto), "femto");
    EXPECT_EQ(prefixToString(prefix_label::pico), "pico");
    EXPECT_EQ(prefixToString(prefix_label::nano), "nano");
    EXPECT_EQ(prefixToString(prefix_label::micro), "micro");
    EXPECT_EQ(prefixToString(prefix_label::milli), "milli");
    EXPECT_EQ(prefixToString(prefix_label::centi), "centi");
    EXPECT_EQ(prefixToString(prefix_label::deci), "deci");
    EXPECT_EQ(prefixToString(prefix_label::deca), "deca");
    EXPECT_EQ(prefixToString(prefix_label::hecto), "hecto");
    EXPECT_EQ(prefixToString(prefix_label::kilo), "kilo");
    EXPECT_EQ(prefixToString(prefix_label::mega), "mega");
    EXPECT_EQ(prefixToString(prefix_label::giga), "giga");
    EXPECT_EQ(prefixToString(prefix_label::tera), "tera");
    EXPECT_EQ(prefixToString(prefix_label::peta), "peta");
    EXPECT_EQ(prefixToString(prefix_label::exa), "exa");
    EXPECT_EQ(prefixToString(prefix_label::zetta), "zetta");
    EXPECT_EQ(prefixToString(prefix_label::yotta), "yotta");
    EXPECT_EQ(prefixToString(prefix_label::none), "none");
}

TEST(prefix_struct, yocto_type)
{
    yocto_type yocto;
    static_assert(yocto.label == prefix::prefix_label::yocto);
    static_assert(yocto.value == 1e-24);

    EXPECT_EQ(yocto.name, "yocto");
    EXPECT_EQ(yocto_type::value, 1e-24);
    EXPECT_EQ(yocto_type::label, prefix::prefix_label::yocto);
    EXPECT_EQ(yocto.value, 1e-24);
    EXPECT_EQ(yocto.label, prefix::prefix_label::yocto);
}

TEST(prefix_struct, zepto_type)
{
    zepto_type zepto;
    static_assert(zepto.label == prefix::prefix_label::zepto);
    static_assert(zepto.value == 1e-21);

    EXPECT_EQ(zepto.name, "zepto");
    EXPECT_EQ(zepto_type::value, 1e-21);
    EXPECT_EQ(zepto_type::label, prefix::prefix_label::zepto);
    EXPECT_EQ(zepto.value, 1e-21);
    EXPECT_EQ(zepto.label, prefix::prefix_label::zepto);
}

TEST(prefix_struct, atto_type)
{
    atto_type atto;
    static_assert(atto.label == prefix::prefix_label::atto);
    static_assert(atto.value == 1e-18);

    EXPECT_EQ(atto.name, "atto");
    EXPECT_EQ(atto_type::value, 1e-18);
    EXPECT_EQ(atto_type::label, prefix::prefix_label::atto);
    EXPECT_EQ(atto.value, 1e-18);
    EXPECT_EQ(atto.label, prefix::prefix_label::atto);
}

TEST(prefix_struct, femto_type)
{
    femto_type femto;
    static_assert(femto.label == prefix::prefix_label::femto);
    static_assert(femto.value == 1e-15);

    EXPECT_EQ(femto.name, "femto");
    EXPECT_EQ(femto_type::value, 1e-15);
    EXPECT_EQ(femto_type::label, prefix::prefix_label::femto);
    EXPECT_EQ(femto.value, 1e-15);
    EXPECT_EQ(femto.label, prefix::prefix_label::femto);
}

TEST(prefix_struct, pico_type)
{
    pico_type pico;
    static_assert(pico.label == prefix::prefix_label::pico);
    static_assert(pico.value == 1e-12);

    EXPECT_EQ(pico.name, "pico");
    EXPECT_EQ(pico_type::value, 1e-12);
    EXPECT_EQ(pico_type::label, prefix::prefix_label::pico);
    EXPECT_EQ(pico.value, 1e-12);
    EXPECT_EQ(pico.label, prefix::prefix_label::pico);
}

TEST(prefix_struct, nano_type)
{
    nano_type nano;
    static_assert(nano.label == prefix::prefix_label::nano);
    static_assert(nano.value == 1e-9);

    EXPECT_EQ(nano.name, "nano");
    EXPECT_EQ(nano_type::value, 1e-9);
    EXPECT_EQ(nano_type::label, prefix::prefix_label::nano);
    EXPECT_EQ(nano.value, 1e-9);
    EXPECT_EQ(nano.label, prefix::prefix_label::nano);
}

TEST(prefix_struct, micro_type)
{
    micro_type micro;
    static_assert(micro.label == prefix::prefix_label::micro);
    static_assert(micro.value == 1e-6);

    EXPECT_EQ(micro.name, "micro");
    EXPECT_EQ(micro_type::value, 1e-6);
    EXPECT_EQ(micro_type::label, prefix::prefix_label::micro);
    EXPECT_EQ(micro.value, 1e-6);
    EXPECT_EQ(micro.label, prefix::prefix_label::micro);
}

TEST(prefix_struct, milli_type)
{
    milli_type milli;
    static_assert(milli.label == prefix::prefix_label::milli);
    static_assert(milli.value == 1e-3);

    EXPECT_EQ(milli.name, "milli");
    EXPECT_EQ(milli_type::value, 1e-3);
    EXPECT_EQ(milli_type::label, prefix::prefix_label::milli);
    EXPECT_EQ(milli.value, 1e-3);
    EXPECT_EQ(milli.label, prefix::prefix_label::milli);
}

TEST(prefix_struct, centi_type)
{
    centi_type centi;
    static_assert(centi.label == prefix::prefix_label::centi);
    static_assert(centi.value == 1e-2);

    EXPECT_EQ(centi.name, "centi");
    EXPECT_EQ(centi_type::value, 1e-2);
    EXPECT_EQ(centi_type::label, prefix::prefix_label::centi);
    EXPECT_EQ(centi.value, 1e-2);
    EXPECT_EQ(centi.label, prefix::prefix_label::centi);
}

TEST(prefix_struct, deci_type)
{
    deci_type deci;
    static_assert(deci.label == prefix::prefix_label::deci);
    static_assert(deci.value == 1e-1);

    EXPECT_EQ(deci.name, "deci");
    EXPECT_EQ(deci_type::value, 1e-1);
    EXPECT_EQ(deci_type::label, prefix::prefix_label::deci);
    EXPECT_EQ(deci.value, 1e-1);
    EXPECT_EQ(deci.label, prefix::prefix_label::deci);
}

TEST(prefix_struct, none_type)
{
    none_type non;
    static_assert(non.label == prefix::prefix_label::none);
    static_assert(non.value == 1);

    EXPECT_EQ(non.name, "none");
    EXPECT_EQ(none_type::value, 1);
    EXPECT_EQ(none_type::label, prefix::prefix_label::none);
    EXPECT_EQ(non.value, 1);
    EXPECT_EQ(non.label, prefix::prefix_label::none);
}

TEST(prefix_struct, deca_type)
{
    deca_type deca;
    static_assert(deca.label == prefix::prefix_label::deca);
    static_assert(deca.value == 1e1);

    EXPECT_EQ(deca.name, "deca");
    EXPECT_EQ(deca_type::value, 1e1);
    EXPECT_EQ(deca_type::label, prefix::prefix_label::deca);
    EXPECT_EQ(deca.value, 1e1);
    EXPECT_EQ(deca.label, prefix::prefix_label::deca);
}

TEST(prefix_struct, hecto_type)
{
    hecto_type hecto;
    static_assert(hecto.label == prefix::prefix_label::hecto);
    static_assert(hecto.value == 1e2);

    EXPECT_EQ(hecto.name, "hecto");
    EXPECT_EQ(hecto_type::value, 1e2);
    EXPECT_EQ(hecto_type::label, prefix::prefix_label::hecto);
    EXPECT_EQ(hecto.value, 1e2);
    EXPECT_EQ(hecto.label, prefix::prefix_label::hecto);
}

TEST(prefix_struct, kilo_type)
{
    kilo_type kilo;
    static_assert(kilo.label == prefix::prefix_label::kilo);
    static_assert(kilo.value == 1e3);

    EXPECT_EQ(kilo.name, "kilo");
    EXPECT_EQ(kilo_type::value, 1e3);
    EXPECT_EQ(kilo_type::label, prefix::prefix_label::kilo);
    EXPECT_EQ(kilo.value, 1e3);
    EXPECT_EQ(kilo.label, prefix::prefix_label::kilo);
}

TEST(prefix_struct, mega_type)
{
    mega_type mega;
    static_assert(mega.label == prefix::prefix_label::mega);
    static_assert(mega.value == 1e6);

    EXPECT_EQ(mega.name, "mega");
    EXPECT_EQ(mega_type::value, 1e6);
    EXPECT_EQ(mega_type::label, prefix::prefix_label::mega);
    EXPECT_EQ(mega.value, 1e6);
    EXPECT_EQ(mega.label, prefix::prefix_label::mega);
}

TEST(prefix_struct, giga_type)
{
    giga_type giga;
    static_assert(giga.label == prefix::prefix_label::giga);
    static_assert(giga.value == 1e9);

    EXPECT_EQ(giga.name, "giga");
    EXPECT_EQ(giga_type::value, 1e9);
    EXPECT_EQ(giga_type::label, prefix::prefix_label::giga);
    EXPECT_EQ(giga.value, 1e9);
    EXPECT_EQ(giga.label, prefix::prefix_label::giga);
}

TEST(prefix_struct, tera_type)
{
    tera_type tera;
    static_assert(tera.label == prefix::prefix_label::tera);
    static_assert(tera.value == 1e12);

    EXPECT_EQ(tera.name, "tera");
    EXPECT_EQ(tera_type::value, 1e12);
    EXPECT_EQ(tera_type::label, prefix::prefix_label::tera);
    EXPECT_EQ(tera.value, 1e12);
    EXPECT_EQ(tera.label, prefix::prefix_label::tera);
}

TEST(prefix_struct, peta_type)
{
    peta_type peta;
    static_assert(peta.label == prefix::prefix_label::peta);
    static_assert(peta.value == 1e15);

    EXPECT_EQ(peta.name, "peta");
    EXPECT_EQ(peta_type::value, 1e15);
    EXPECT_EQ(peta_type::label, prefix::prefix_label::peta);
    EXPECT_EQ(peta.value, 1e15);
    EXPECT_EQ(peta.label, prefix::prefix_label::peta);
}

TEST(prefix_struct, exa_type)
{
    exa_type exa;
    static_assert(exa.label == prefix::prefix_label::exa);
    static_assert(exa.value == 1e18);

    EXPECT_EQ(exa.name, "exa");
    EXPECT_EQ(exa_type::value, 1e18);
    EXPECT_EQ(exa_type::label, prefix::prefix_label::exa);
    EXPECT_EQ(exa.value, 1e18);
    EXPECT_EQ(exa.label, prefix::prefix_label::exa);
}

TEST(prefix_struct, zetta_type)
{
    zetta_type zetta;
    static_assert(zetta.label == prefix::prefix_label::zetta);
    static_assert(zetta.value == 1e21);

    EXPECT_EQ(zetta.name, "zetta");
    EXPECT_EQ(zetta_type::value, 1e21);
    EXPECT_EQ(zetta_type::label, prefix::prefix_label::zetta);
    EXPECT_EQ(zetta.value, 1e21);
    EXPECT_EQ(zetta.label, prefix::prefix_label::zetta);
}

TEST(prefix_struct, yotta_type)
{
    yotta_type yotta;
    static_assert(yotta.label == prefix::prefix_label::yotta);
    static_assert(yotta.value == 1e24);

    EXPECT_EQ(yotta.name, "yotta");
    EXPECT_EQ(yotta_type::value, 1e24);
    EXPECT_EQ(yotta_type::label, prefix::prefix_label::yotta);
    EXPECT_EQ(yotta.value, 1e24);
    EXPECT_EQ(yotta.label, prefix::prefix_label::yotta);
}
