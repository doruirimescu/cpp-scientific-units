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

TEST(Orderable, equality)
{
    OrderableTest a{10.0};
    Orderable b{10.0};
    ASSERT_TRUE(a == b);
    static_assert(Orderable{1} == Orderable{1});
}

TEST(Orderable, inequality)
{
    OrderableTest a{10.0};
    Orderable b{10.1};
    ASSERT_TRUE(a != b);
    static_assert(Orderable{2} != Orderable{1});
}

TEST(Orderable, less_than)
{
    OrderableTest a{10.5};
    Orderable b{10.9};
    ASSERT_TRUE(a < b);
    static_assert(Orderable{2} < Orderable{13});
}

TEST(Orderable, less_than_or_equal)
{
    OrderableTest a{10.5};
    Orderable b{10.9};
    ASSERT_TRUE(a <= b);
    static_assert(Orderable{3} <= Orderable{13});
}

TEST(Orderable, greater_than)
{
    OrderableTest a{39};
    Orderable b{7};
    ASSERT_TRUE(a > b);
    static_assert(Orderable{3} > Orderable{1});
}

TEST(Orderable, greater_than_or_equal)
{
    OrderableTest a{39};
    Orderable b{7};
    ASSERT_TRUE(a >= b);
    static_assert(Orderable{0} >= Orderable{0});
}
