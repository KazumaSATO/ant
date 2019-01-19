#include "gtest/gtest.h"
#include "chapter2/partition_num.h"


TEST(TestPartitionNum, Textbook) {
  int n = 4;
  int m = 3;
  int M = 10000;

  EXPECT_EQ(4, solve_partition_num(n, m, M));
}

