#include<iostream>
#include<algorithm>
#include<tuple>

/*
  tuple 男、女、親密度
  n: 女の数
  m: 男の数
  std::get<i>(tuple); でi番目の値を取得できる
 */

/**
   v: 頂点の数
   e_length: 辺の数
   e
*/
struct edge {int u, v, cost;};

// 祖先を返す
int find_root(int index, int par[]) {
  // rootである
  if(par[index] == index)
    return index;

  return par[index] = find_root(par[index], par);
}

// 同じクラスタであれば真を返す
bool is_same_cluster(int a, int b, int par[]) {
  return find_root(a, par) == find_root(b, par);
}

void unite_clusters(int a, int b, int par[], int rank[]) {
  if(is_same_cluster(a, b, par))
    return;

  int par_a = find_root(a, par);
  int par_b = find_root(b, par);


  if(rank[par_a] > rank[par_b]) {
    par[par_b] = par_a;
  } else {
    par[par_a] = par_b;
    if(rank[par_a] == rank[par_b])
      rank[par_b]++;
  }
}

int kruskal(int v, int e_len, edge e[]) {
  int par[v];
  int rank[v];
  //初期化
  for(int i=0; i<v; i++) {
    par[i] = i;
    rank[i] = 0;
  }
  std::sort(e, e + e_len, [](edge a, edge b) {return a.cost < b.cost;});
  int res = 0;

  for(int i=0;i<e_len;i++) {
    edge ed = e[i];
    if(!is_same_cluster(ed.u, ed.v, par)) {
      unite_clusters(ed.u, ed.v, par, rank);
      res += ed.cost;
    }
  }
  return res;
}


int conscription(int n, int m, int r, std::tuple<int, int, int> relations[]) {
  int v = n+m;
  edge e[r];
  for(int i=0;i<r;i++) {
    auto t = relations[i];
    e[i] = edge {std::get<0>(t), m + std::get<1>(t), -std::get<2>(t)};
  }
  int result = kruskal(v, r, e);
  return 10000*(n+m) + result;
}

