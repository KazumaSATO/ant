#include<iostream>
#include<algorithm>
#include <functional>
#include<vector>
#include "nlknapsack.h"

int solve_nlknapsack(int n, int w[], int v[], int W) {


  int dp[n][W+1];

  for(int j=0;j<W+1;j++) {
    if(w[0] <= j) {
      dp[0][j] = v[0];
    } else {
      dp[0][j] = 0;
    }
  }

  for(int i=0;i<n;i++) {
    dp[i][0] = 0;
  }

  for(int i=1;i<n;i++) {
    for(int j=1;j<W+1;j++) {
      if(j-w[i]>=0)
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-w[i]]+v[i]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n-1][W];
}
