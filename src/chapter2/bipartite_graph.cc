#include<iostream>
#include<vector>
#include "bipartite_graph.h"

bool solve(int vertex, int draw, std::vector<int> graph[], int color[]) {
  color[vertex] = draw;
  for(int i=0;i<graph[vertex].size(); i++) {
    int neighbor = graph[vertex][i];
    if(color[neighbor] == draw) {
      return false;
    }
    if(color[neighbor] == 0) {
      solve(neighbor, -1 * draw, graph, color);
    }

  }
  return true;
}


bool bipartite_graph(std::vector<int> graph[], int size) {
  int color[size];
  for(int i= 0; i < size; i++) {
    color[i] = 0;
  }

  for(int i =0;i<size; i++) {
    if(color[i]  == 0 && !solve(i, 1, graph, color)) {
      return false;
    }
  }

  return true;
}

