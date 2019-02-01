#include<gtest/gtest.h>
#include "chapter2/truck.h"

TEST(TestTruck, Textbook) {

  int n = 4;
  int l = 25;
  int p = 10;
  int a[] = {10, 14, 20, 21};
  int b[] = {10, 5, 2, 4};

  EXPECT_EQ(2, solve_truck(4, 25, 10, a, b));
}
