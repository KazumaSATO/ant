#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "chapter2/num_limited_partial_sum.h"


TEST(TestNumLimitedPartialSum, Textbook) {
  int a[] = {3, 5, 8};
  int m[] = {3, 2, 2};
  int k = 17;

  EXPECT_EQ(true, solve_num_limited_partial_sum(3, a, m, k));
}
