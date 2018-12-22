#include<gtest/gtest.h>
#include "chapter2/knapsack.h"

TEST(TestKnapsack, Textbook) {
  int n = 4;
  int w[] = {2, 1, 3, 2};
  int v[] = {3, 2, 4, 2};
  int W = 5;

  EXPECT_EQ(7, solve_knapsack(n, w, v, W));
}
