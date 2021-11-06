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
