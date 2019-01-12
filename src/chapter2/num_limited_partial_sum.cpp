#include<iostream>
#include<algorithm>
#include<vector>


bool solve_num_limited_partial_sum(int n, int a[], int m[], int k) {
  int dp[n][k+1];

  for(int i= 0;i<n;i++) {
    for(int j=0;j<k+1;j++) {
      dp[i][j] = -1;
    }
  }
  for(int i=0;i<k+1;i++) {
    dp[0][i] = m[i];
  }
  for(int i=1;i<n;i++) {
    for(int j=0;j<k+1;j++) {
      if(dp[i-1][j] > 0)
        dp[i][j] = m[i];
      else if(j<a[i] || dp[i][j-a[i]] == -1)
        dp[i][j] = -1;
      else
        dp[i][j] = dp[i][j-a[i]] - 1;

    }
  }

  return dp[n-1][k];
}
