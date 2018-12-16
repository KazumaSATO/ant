#include<gtest/gtest.h>
#include "chapter2/food_chain.h"


TEST(TestFoodChain, Textbook) {
  int n = 100;
  int k = 7;
  int t[] = {1, 2, 2, 2, 1, 2, 1};
  int x[] = {101, 1, 2, 3, 1, 3, 5};
  int y[] = {1, 2, 3, 3, 3, 1, 5};

  EXPECT_EQ(3, solve_food_chain(n, k, t, x, y));

}
