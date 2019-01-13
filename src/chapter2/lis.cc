#include<iostream>
#include<algorithm>
#include<vector>


int solve_lis(int n, int a[]) {
  int dp[n];
  int inf = 2000;
  for(int i =0;i<n;i++) {
    dp[i]=inf;
  }

  for(int i=0;i<n;i++) {
    *std::lower_bound(dp, dp+n, a[i]) = a[i];
  }

  return std::lower_bound(dp, dp + n, inf) - dp;
}
