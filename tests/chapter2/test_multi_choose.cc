#include <iostream>
#include "gtest/gtest.h"
#include "chapter2/multi_choose.h"


TEST(TestMultiChoose, Textbook) {
  int n = 3;
  int m = 3;
  int a[] = {1, 2, 3};
  int M = 10000;
  EXPECT_EQ(6, solve_multi_choose(n, m, a, M));
}
