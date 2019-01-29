#include <iostream>

// m個選ぶ n種類品物がある。 Mで割る
int solve_multi_choose(int n, int m, int a[], int M) {
  int dp[n+1][m+1];

  for(int i =0;i<=n;i++) {
    dp[i][0] = 1;
  }

  for(int j=0; j<=m; j++) {
    if(j==0)
      dp[0][j] = 1;
    else
      dp[0][j] = 0;
  }

  for(int i=0;i<n;i++) {
    for(int j=1;j<=m;j++) {
      if(j-1 -a[i] >= 0) {
        dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]];
      } else {
        dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
      }
    }
  }
  /*
  for(int i=0;i<n+1;i++) {
    for(int j =0;j<m+1;j++) {
      std::cout << i << "," << j <<  "->" << dp[i][j] << std::endl;
    }
  }
  */
  return dp[n][m] % M;
}
