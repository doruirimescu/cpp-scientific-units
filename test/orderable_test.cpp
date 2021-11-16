#include <gtest/gtest.h>
#include <test_types.hpp>

class OrderableTest : public Orderable<double>
{
public:
    constexpr explicit OrderableTest(double value)
        : Orderable<double>(value)
    {
    }
};

TEST(orderable, equality)
{
    OrderableTest a{10.0};
    Orderable<double> b{10.0};
    ASSERT_TRUE(a == b);
    static_assert(Orderable<double>{1} == Orderable<double>{1});
}

TEST(orderable, inequality)
{
    OrderableTest a{10.0};
    Orderable<double> b{10.1};
    ASSERT_TRUE(a != b);
    static_assert(Orderable<double>{2} != Orderable<double>{1});
}

TEST(orderable, less_than)
{
    OrderableTest a{10.5};
    Orderable<double> b{10.9};
    ASSERT_TRUE(a < b);
    static_assert(Orderable<double>{2} < Orderable<double>{13});
}

TEST(orderable, less_than_or_equal)
{
    OrderableTest a{10.5};
    Orderable<double> b{10.9};
    ASSERT_TRUE(a <= b);
    static_assert(Orderable<double>{3} <= Orderable<double>{13});
}

TEST(orderable, greater_than)
{
    OrderableTest a{39};
    Orderable<double> b{7};
    ASSERT_TRUE(a > b);
    static_assert(Orderable<double>{3} > Orderable<double>{1});
}

TEST(orderable, greater_than_or_equal)
{
    constexpr OrderableTest a{39};
    constexpr Orderable<double> b{7};
    static_assert(a >= b);
    static_assert(Orderable<double>{0} >= Orderable<double>{0});
    static_assert(Orderable<double>{3}.value * Orderable<double>{5}.value == 15);
}
