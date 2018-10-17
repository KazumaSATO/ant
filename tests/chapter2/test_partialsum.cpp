#include <string>
#include "gtest/gtest.h"
#include "chapter2/partialsum.h"

TEST(Partialsum, Yes) {
    int n = 4;
    int a[] = {1, 2, 4, 7};
    int k = 13;

    EXPECT_EQ(std::string("Yes"), partialsum(n, a, k));
}

TEST(Partialsum, No) {
    int n = 4;
    int a[] = {1, 2, 4, 7};
    int k = 15;

    EXPECT_EQ(std::string("No"), partialsum(n, a, k));
}