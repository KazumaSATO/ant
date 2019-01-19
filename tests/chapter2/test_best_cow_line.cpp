#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "chapter2/best_cow_line.h"

TEST(TestBestCowLine, First) {
    char s[] = {'A', 'C', 'D', 'B', 'C','B'};
    std::string ans = "ABCBCD";
    EXPECT_EQ(ans, solve_best_cow_line(6,s));
}

TEST(TestBestCowLine, One) {
    char s[] = {'A'};
    std::string ans = "A";
    EXPECT_EQ(ans, solve_best_cow_line(1,s));
}
