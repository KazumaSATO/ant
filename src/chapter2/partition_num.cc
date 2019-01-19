#include<iostream>


int solve_partition_num(int n, int m, int M) {
  int dp[m+1][n+1];

  dp[0][0] = 1;

  for(int j = 0;j<n+1;j++) {
    dp[1][j] = 1;
  }
  for(int i=2;i<m+1;i++) {
    for(int j=0;j<n+1;j++) {
      if(j>=i) {
        std::cout << "{" << i << "," << j << "}" << dp[i][j-1] << std::endl;
        dp[i][j] = dp[i][j-i] + dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      std::cout << "dp[" << i << "," << j << "]" << dp[i][j] << std::endl;
    }
  }

  return dp[m][n];
}
