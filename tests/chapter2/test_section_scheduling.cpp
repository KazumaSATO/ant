#include <string>
#include "gtest/gtest.h"
#include "chapter2/section_scheduling.h"

TEST(SectionScheduling, A) {
    int n = 5;
    int s[] = {1, 2,4,6,8};
    int t[] = {3, 5, 7, 9 , 10};
    EXPECT_EQ(3, solve_section_scheduling(n, s, t));
}