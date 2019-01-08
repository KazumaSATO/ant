#include<iostream>
#include<algorithm>
#include<vector>
#include "knapsack2.h"

/* p60
 */
int solve_knapsack2(int n, int w[], int v[], int W) {
  int inf = 10000000*100+1;
  int max_value = 100*100 + 1;
  int dp[100+1][max_value];

  for(int i=0;i<n;i++) {
    for(int j=0;j<max_value;j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for(int i =0; i<n; i++) {
    for(int j=0; j<max_value; j++) {
      if(j < v[i])
        dp[i+1][j] = dp[i][j];
      else
        dp[i+1][j] = std::min(dp[i][j], dp[i][j-v[i]] + w[i]);
    }
  }
  int ans = 0;
  for(int j=0;j<max_value;j++) {
    if(dp[n][j] <= W)
      ans = j;
  }

  return ans;
}
