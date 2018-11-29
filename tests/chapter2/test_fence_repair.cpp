#include "gtest/gtest.h"
#include "chapter2/fence_repair.h"


TEST(FenceRepairTest, Text) {
  int l[3] = {8, 5, 8};

  EXPECT_EQ(34, solve_fence_repair(3, l));
  
}

TEST(FenceRepairTest, One) {
  int l[3] = {8};

  EXPECT_EQ(0, solve_fence_repair(1, l));
  
}
