#include <algorithm>
#include <iostream>
#include <functional>
#include <string>
#include "lcs.h"


int solve_lcs(int n, int m, std::string s, std::string t) {
  int nm[n][m];

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      nm[i][j] = 0;
    }
  }
  for(int i=0;i<n;i++) {
    if(i>0 && nm[i-1][0] == 1) {
      nm[i][0] = 1;
    } else if (s.at(i) == t.at(0)){
      nm[i][0] = 1;
    }
  }
  for(int i=0;i<m;i++) {
    if(i>0 && nm[0][i-1] == 1) {
      nm[0][i] = 1;

    } else if (s.at(0) == t.at(i)){
      nm[0][i] = 1;
    }
  }
  for(int i=1;i<n;i++) {
    for(int j=1;j<m;j++) {
      if(s.at(i) == t.at(j))
        nm[i][j] = std::max({nm[i-1][j-1] + 1, nm[i][j-1], nm[i-1][j]});
      else
        nm[i][j] = std::max({nm[i-1][j], nm[i][j-1]});
    }
  }
  return nm[n-1][m-1];
}
