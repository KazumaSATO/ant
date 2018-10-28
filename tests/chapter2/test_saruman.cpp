#include <gtest/gtest.h>
#include "chapter2/saruman.h"


TEST(TestSaruman, I) {

    int n = 6;
    int r = 10;
    int x[] = {1, 7, 15, 20, 30, 50};

    EXPECT_EQ(3, solve_saruman(n, r, x));
}