#include <iostream>
#include <algorithm>
#include "triangle.h"

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int length(int array[]) {
  return sizeof(array)/array[0];
}

bool is_trianglable(int e0, int e1, int e2) {
  return e0 <= (e1 + e2) && e1 <= (e0 + e2) && e2 <= (e1 + e0);
}

int solve_triangle(int n, int array[]) {
  int ans = 0;

  for (int i=0; i < n; i++) {
    int e0 = array[i];
    for(int j=i+1; j < n; j++) {
      if(j>=n) {
        break;
      }
      int e1 = array[j];
      for(int k= j+1; j < n; k++) {
        if(k >= n) {
          break;
        }
        int e2 = array[k];
        if(is_trianglable(e0, e1, e2)) {
          ans = std::max(ans, e0+e1+e2);
        }
      }
    }
  }
  return ans;
}