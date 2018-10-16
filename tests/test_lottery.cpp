#include<iostream>
#include "lottery.h"
#include "gtest/gtest.h"

TEST(LotteryTest, Sort) {
    int array[] = {1, 5, 2};
    asc_sort(array, 3);
    int answer[] = {1, 2, 5};
    EXPECT_EQ(true, std::equal(std::begin(answer), std::end(answer), std::begin(array)));
}

TEST(LotteryTest, Yes) {
    int n = 3;
    int m = 10;
    int k [] = {1, 3, 5};
    EXPECT_EQ(std::string("Yes"), solve_lottery(n, m, k));
}

TEST(LotteryTest, No) {
    int n = 3;
    int m = 9;
    int k [] = {1, 3, 5};
    EXPECT_EQ(std::string("No"), solve_lottery(n, m, k));
}