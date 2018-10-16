#include <iostream>
#include "chapter1/triangle.h"
#include "gtest/gtest.h"


TEST(TriangleTest, NotTriangle) {
  int array[] = {1, 5, 2};
  EXPECT_EQ(0 , solve_triangle(sizeof(array)/sizeof(array[0]), array));
}

TEST(TrianglableTest, Pass) {
  EXPECT_EQ(true, is_trianglable(2, 2, 2));
  EXPECT_EQ(false, is_trianglable(1, 5, 2));

}

TEST(TriangleTest, Triangle) {
  int array[] = {2, 3, 4, 5, 10};
  int result = solve_triangle(sizeof(array)/sizeof(array[0]), array);
  EXPECT_EQ(12 , result);
}


TEST(TriangleTest2, Triangle) {
  int array[] = {4, 5, 10, 20};
  int result = solve_triangle(sizeof(array)/sizeof(array[0]), array);
  EXPECT_EQ(0 , result);
}

