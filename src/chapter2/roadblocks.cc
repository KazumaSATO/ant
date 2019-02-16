#include<vector>
#include<queue>
#include "roadblocks.h"

typedef std::pair<int, int> P;


int roadblocks(int n, int r, std::vector<edge> g[]) {
  int inf = 100000;

  int dist[n];
  int dist2[n];

  for(int i=0; i<n; i++) {
    dist[i] = inf;
    dist2[i] = inf;
  }
  dist[0] = 0;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  que.push(P(0, 0));

  while(que.size() > 0) {
    P p = que.top(); que.pop();
    int v = p.second;
    int d = p.first;

    if (dist2[v] < d) continue;
    for(int i=0; i < g[v].size(); i++) {
       edge e = g[v][i];
       int d2 = d + e.cost;
       if(dist[e.to] > d2) {
         std::swap(dist[e.to], d2);
         que.push(P(dist[e.to], e.to));
       }

       if(dist2[e.to] > d2 && dist[e.to] < d2) {
         std::swap(dist2[e.to], d2);
         que.push(P(dist2[e.to], e.to));
       }
    }
  }
  return dist2[n-1];
}
