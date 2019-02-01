#include<iostream>
#include<queue>

int solve_truck(int n, int l, int p, int a[], int b[]) {

  std::priority_queue<int> que;

  int aa[n+1];
  int bb[n+1];
  for(int i=0;i<n;i++) {
    aa[i] = a[i];
    bb[i] = b[i];
  }
  aa[n] = l;
  bb[n] = 0;

  int ans = 0;
  int cur_p = p;
  int current_position = 0;
  for(int i=0;i<n+1;i++) {
    int required_p = aa[i] - current_position;
    while(cur_p < required_p) {
      if(que.size() == 0) {
        return -1;
      }
      cur_p += que.top();
      que.pop();
      ans++;
    }
    cur_p -= required_p;
    current_position = aa[i];
    que.push(bb[i]);
  }
  return ans;
}

