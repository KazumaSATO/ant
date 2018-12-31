#include<gtest/gtest.h>
#include "chapter2/nlknapsack.h"

TEST(NoLimitKnapsack, Textbook) {
  int n = 3;
  int w[] = {3, 4, 2};
  int v[] = {4, 5, 3};
  int W = 7;

  EXPECT_EQ(10, solve_nlknapsack(n, w, v, W));
}

