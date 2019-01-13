#include "gtest/gtest.h"
#include "chapter2/lis.h"



TEST(TestLis, Textbook) {
  int n=5;
  int a[] = {4, 2, 3, 1, 5};

  EXPECT_EQ(3, solve_lis(n, a));
}
