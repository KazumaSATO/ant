#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
using namespace std;

class Knapsack {
public:
    const static int MAX_N = 100;
    const static int MAX_W = 10000;
    int dp[MAX_N][MAX_W];
    vector<int> given_w;
    vector<int> given_v;
    int solve(int n, vector<int> w, vector<int> v, int W) {
      memset();
      given_w = w;
      given_v = v;
      return ans(n, W);
    }

    int ans(int nn, int ww) {
        
        if(dp[nn][ww] != -1) {
          return dp[nn][ww];
        }
        // 最初の人たち
        if(nn == 0) {
          if(ww >= given_w[0]) {
              dp[nn][ww] = given_v[nn];
              return dp[nn][ww];
          }
            dp[nn][ww] = 0;
          return dp[nn][ww];
        }
        // 含むケース
        if(given_w[nn] >= ww) {
            dp[nn][ww] = ans(nn-1, ww);
            return dp[nn][ww];
        }
        
        dp[nn][ww] = max(ans(nn-1, ww - given_w[nn]) + given_v[nn], ans(nn-1, ww));
        return dp[nn][ww];
    }

    void memset() {
      for(int i=0;i< MAX_N;i++) {
        for(int j=0;j<MAX_W;j++) {
          dp[i][j] = -1;
        }
      }
    }

};

int main() {
    Knapsack solver;
    int ws[] = {2,1,3,2};
    int vs[] = {3,2,4,2};
    cout << solver.solve(4, vector<int>(ws, ws+4), vector<int>(vs, vs+4), 5);
    cout << endl;
    return 0;

}
