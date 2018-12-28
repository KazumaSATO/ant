#include<gtest/gtest.h>
#include<string>
#include "chapter2/lcs.h"


TEST(TestLcs, Textbook) {

  std::string s("abcd");
  std::string t("becd");
  EXPECT_EQ(3, solve_lcs(4, 4, s, t));
}
