#include <gtest/gtest.h>
#include "unit.hpp"
using ::testing::StaticAssertTypeEq;

TEST(UnitNameLabel, unitNameToString)
{
    EXPECT_EQ(unitNameToString(UnitNameLabel::second), "second");
    EXPECT_EQ(unitNameToString(UnitNameLabel::meter), "meter");
    EXPECT_EQ(unitNameToString(UnitNameLabel::gram), "gram");
    EXPECT_EQ(unitNameToString(UnitNameLabel::hertz), "hertz");
}

TEST(Unit, meter_units)
{
    auto result = 20.0_m + 1.0_km + 10.0_cm;
    ASSERT_TRUE(result.value_ == 1020.1);
    ASSERT_TRUE(result.getUnitName() == "meter");
    ASSERT_TRUE(result.getPrefix() == "none");

    result = 20.0_m + 1.0_km + 10.0_cm + 1.0_mm;
    ASSERT_TRUE(result.value_ == 1020.101);
}

TEST(Unit, gram_units)
{
    auto result = 1000.0_mg;
    EXPECT_EQ(result.value_, 1000.0);
    EXPECT_EQ(result.getUnitName(), "gram");
    EXPECT_EQ(result.getPrefix(), "milli");
}

TEST(Unit, gram_equal)
{
    ASSERT_TRUE(1000.0_mg == 1000.0_mg);
    ASSERT_TRUE(1000.0_mg == 1.0_g);
    ASSERT_TRUE(1.0_g == 1000.0_mg);
    ASSERT_FALSE(1.0_g == 1.1_g);
    ASSERT_FALSE(1.0_g == 1.0_kg);
    ASSERT_FALSE(1.0_kg == 1.0_g);
}

TEST(Unit, gram_lessThan)
{
    ASSERT_FALSE(1000.0_mg < 1000.0_mg);
    ASSERT_FALSE(1000.0_mg < 1.0_g);
    ASSERT_FALSE(1.0_g < 1000.0_mg);
    ASSERT_TRUE(1.0_g < 1.1_g);
    ASSERT_TRUE(1.0_g < 1.0_kg);
    ASSERT_TRUE(1.0_kg < 10.0_kg);
}

TEST(Unit, gram_lessThanOrEqual)
{
    ASSERT_TRUE(1000.0_mg <= 1000.0_mg);
    ASSERT_TRUE(1000.0_mg <= 1.0_g);
    ASSERT_TRUE(1.0_g <= 1000.0_mg);
    ASSERT_TRUE(1.0_g <= 1.1_g);
    ASSERT_TRUE(1.0_g <= 1.0_kg);
    ASSERT_TRUE(1.0_kg <= 10.0_kg);
}

TEST(Unit, gram_greaterThan)
{
    ASSERT_TRUE(2.0_g > 1.0_g);
    ASSERT_TRUE(2.0_kg > 1.0_g);
    ASSERT_TRUE(1000.0_g > 0.1_kg);
    ASSERT_FALSE(2.0_g > 1.0_kg);
    ASSERT_FALSE(2.0_g > 5.0_g);
    ASSERT_FALSE(2.0_g > 2.0_g);
}

TEST(Unit, gram_greaterThanOrEqual)
{
    ASSERT_TRUE(2.0_g >= 1.0_g);
    ASSERT_TRUE(2.0_kg >= 1.0_g);
    ASSERT_TRUE(1000.0_g >= 0.1_kg);
    ASSERT_FALSE(2.0_g >= 1.0_kg);
    ASSERT_FALSE(2.0_g >= 5.0_g);
    ASSERT_TRUE(2.0_g >= 2.0_g);
    ASSERT_TRUE(200.0_g >= 0.2_kg);
}

TEST(Unit, gram_plus_milligram)
{
    auto new_result = 1000.0_mg + 1.0_g;
    EXPECT_EQ(new_result.getUnitName(), "gram");
    EXPECT_EQ(new_result.getPrefix(), "none");
    EXPECT_EQ(new_result.value_, 2.0);

    new_result = 1.0_g + 1000.0_mg;
    EXPECT_EQ(new_result.getUnitName(), "gram");
    EXPECT_EQ(new_result.getPrefix(), "none");
    EXPECT_EQ(new_result.value_, 2.0);
}

TEST(Unit, gram_minus_milligram)
{
    auto result  = 1.0_g - 1000.0_mg;
    EXPECT_EQ(result.getUnitName(), "gram");
    EXPECT_EQ(result.getPrefix(), "none");
    EXPECT_EQ(result.value_, 0.0);

    EXPECT_EQ(1.0_g - 100.0_mg, 0.9_g);

    auto new_result = 1000.0_mg - 2.0_g;
    EXPECT_EQ(new_result.getUnitName(), "gram");
    EXPECT_EQ(new_result.getPrefix(), "none");
    EXPECT_EQ(new_result.value_, -1.0);
}