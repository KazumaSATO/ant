#include<iostream>
#include<algorithm>
#include <functional>
#include<vector>
#include "nlknapsack.h"

int solve_nlknapsack(int n, int w[], int v[], int W) {
  int vw[n+1][W+1];

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      vw[i][j] = 0;
    }
  }

  for(int i=1;i<n+1;i++) {
    for(int j=1;j<W+1;j++) {
      if(j-w[i]>=0)
        vw[i][j] = std::max(vw[i-1][j], vw[i][j-w[i]]+v[i]);
      else
        vw[i][j] = vw[i-1][j];
    }
  }
  return vw[n][W];
}
