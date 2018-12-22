#include<iostream>
#include<algorithm>
#include<vector>
#include "knapsack.h"


int solve_knapsack(int n, int w[], int v[], int W) {

  int m[W+1][n];

  for(int i=0;i<n;i++) {
    m[0][i] = 0;
  }

  for(int i=0;i<W+1;i++) {
    if(i >= w[n-1])
      m[i][n-1] = w[n-1];
    else
      m[i][n-1] = 0;
  }

  for(int i=1;i<W+1;i++) {
    for(int j=n-2;j>=0;j--) {
      int cand1 = m[i][j+1];
      if(i-w[j]>=0 && m[i-w[j]][j+1] + v[j] >= cand1) {
        m[i][j] = m[i-w[j]][j+1] + v[j];
      } else {
        m[i][j] = cand1;
      }
    }
  }
  return m[W][0];
}
