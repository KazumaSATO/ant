#include<iostream>
#include<tuple>
#include "gtest/gtest.h"
#include "chapter2/conscription.h"


TEST(TestConscription, Textbook){

  std::tuple<int, int, int> a0 = std::make_tuple(4, 3, 6831);
  std::tuple<int, int, int> a1 = std::make_tuple(1, 3, 4583);
  std::tuple<int, int, int> a2 = std::make_tuple(0, 0, 6592);
  std::tuple<int, int, int> a3 = std::make_tuple(0, 1, 3063);
  std::tuple<int, int, int> a4 = std::make_tuple(3, 3, 4975);
  std::tuple<int, int, int> a5 = std::make_tuple(1, 3, 2049);
  std::tuple<int, int, int> a6 = std::make_tuple(4, 2, 2104);
  std::tuple<int, int, int> a7 = std::make_tuple(2, 2, 781);

  std::tuple<int, int, int> r[] = {a0, a1, a2, a3, a4, a5, a6, a7};

  EXPECT_EQ(71071, conscription(5, 5, 8, r));
}
