// p75

f
int solve_fence_repair(int n, int l[]) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> que;

  int cost = 0;
  for(int i =0;i < n; i++) {
    que.push(l[i]);
  }


  while(true) {
    int size = que.size();
    int peek = que.top();
    if(size == 1) {
      return cost;
    }
    que.pop();
    int peek2 = que.top();
    que.pop();
    que.push(peek + peek2);
    cost += peek + peek2;
  }

  return cost;
}
