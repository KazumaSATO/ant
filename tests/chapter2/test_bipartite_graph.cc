#include<gtest/gtest.h>
#include<vector>
#include "chapter2/bipartite_graph.h"


TEST(TestBipartiteGraph, TextbookFalse) {
  std::vector<int> graph[3];

  graph[0] = std::vector<int>(2);
  graph[0][0] = 1;
  graph[0][1] = 2;
  graph[1] = std::vector<int>(2);
  graph[1][0] = 0;
  graph[1][1] = 2;
  graph[2] = std::vector<int>(2);
  graph[2][0] = 0;
  graph[2][1] = 1;

  EXPECT_EQ(false, bipartite_graph(graph, 3));
}

TEST(TestBipartiteGraph, TextbookTrue) {
  std::vector<int> graph[4];

  graph[0] = std::vector<int>(2);
  graph[0][0] = 1;
  graph[0][1] = 3;
  graph[1] = std::vector<int>(2);
  graph[1][0] = 0;
  graph[1][1] = 2;
  graph[2] = std::vector<int>(2);
  graph[2][0] = 1;
  graph[2][1] = 3;
  graph[3] = std::vector<int>(2);
  graph[3][0] = 0;
  graph[3][1] = 2;

  EXPECT_EQ(true, bipartite_graph(graph, 4));
}
