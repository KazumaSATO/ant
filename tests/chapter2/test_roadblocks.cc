#include<gtest/gtest.h>
#include "chapter2/roadblocks.h"


TEST(TestRoadBlocks, Textbook) {
  edge e01 = {1, 100};
  std::vector<edge> ee0 = {e01};
  edge e10 = {0, 100};
  edge e12 = {2, 250};
  edge e13 = {3, 200};
  std::vector<edge> ee1 = {e10, e12, e13};
  edge e21 = {1, 250};
  edge e23 = {3, 100};
  std::vector<edge> ee2 = {e21, e23};
  edge e31 = {1, 200};
  edge e32 = {2, 100};
  std::vector<edge> ee3 = {e31, e32};

  std::vector<edge> e[] = {ee0, ee1, ee2, ee3};

  EXPECT_EQ(450, roadblocks(4, 4, e));
}
