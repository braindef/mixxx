#include <gtest/gtest.h>
#include "util/math.h"

#include <QtDebug>

namespace {

class MathUtilTest : public testing::Test {
  protected:

    MathUtilTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    static const int MIN;
    static const int MAX;

    static const int VALUE_MIN;
    static const int VALUE_MAX;
};

const int MathUtilTest::MIN = -10;
const int MathUtilTest::MAX = 10;

const int MathUtilTest::VALUE_MIN = 2 * MathUtilTest::MIN;
const int MathUtilTest::VALUE_MAX = 2  * MathUtilTest::MAX;

TEST_F(MathUtilTest, MathClampUnsafe) {
    for (int i = VALUE_MIN; i <= VALUE_MAX; ++i) {
        EXPECT_LE(MIN, math_clamp_unsafe(i, MIN, MAX));
        EXPECT_GE(MAX, math_clamp_unsafe(i, MIN, MAX));
        EXPECT_EQ(MIN, math_clamp_unsafe(i, MIN, MIN));
        EXPECT_EQ(MAX, math_clamp_unsafe(i, MAX, MAX));
        if (MIN >= i) {
            EXPECT_EQ(MIN, math_clamp_unsafe(i, MIN, MAX));
        }
        if (MAX <= i) {
            EXPECT_EQ(MAX, math_clamp_unsafe(i, MIN, MAX));
        }
    }
}

TEST_F(MathUtilTest, MathClampSafe) {
    for (int i = VALUE_MIN; i <= VALUE_MAX; ++i) {
        EXPECT_LE(MIN, math_clamp_safe(i, MIN, MAX));
        EXPECT_GE(MAX, math_clamp_safe(i, MIN, MAX));
        EXPECT_EQ(MIN, math_clamp_safe(i, MIN, MIN));
        EXPECT_EQ(MAX, math_clamp_safe(i, MAX, MAX));
        if (MIN >= i) {
            EXPECT_EQ(MIN, math_clamp_safe(i, MIN, MAX));
        }
        if (MAX <= i) {
            EXPECT_EQ(MAX, math_clamp_safe(i, MIN, MAX));
        }
    }
}

TEST_F(MathUtilTest, MathClampSafeInvalidBounds) {
    for (int i = VALUE_MIN; i <= VALUE_MAX; ++i) {
        EXPECT_EQ(i, math_clamp_safe(i, MAX, MIN));
    }
}

}  // namespace
