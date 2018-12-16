#include <iostream>
#include <string>
#include <vector>

void peek(int par[], int size);
int find_root(int par[], int node);
void unite(int par[], int node_a, int node_b);
bool same_group(int par[],int node_a, int node_b);


void peek(int par[], int size) {

  for(int i=0; i<size;i++) {
    std::cout << std::to_string(i) + " -> " + std::to_string(par[i])  << std::endl;
  }
}

int find_root(int par[], int node) {
  int parent = par[node];

  if(parent == node)
    return parent;

  return par[node] = find_root(par, parent);
}

void unite(int par[], int node_a, int node_b) {
  int root_a = find_root(par, node_a);
  int root_b = find_root(par, node_b);

  if (root_a == root_b)
    return;

  par[root_a] = root_b;
}

bool same_group(int par[], int node_a, int node_b) {
  return find_root(par, node_a) == find_root(par, node_b);
}

int solve_food_chain(int n, int k, int t[], int x[], int y[]) {
  int MAX_N = 50000*3;
  int ans = 0;

  int par[MAX_N];

  // init
  for(int i=0;i<3*n;i++) {
    par[i] = i;
  }

  for(int i=0;i<k;i++) {
    int xx = x[i]-1;
    int yy = y[i]-1;

    if( 0 > xx || xx >= n || 0 > yy || yy >= n ) {
      ans++;
      continue;
    }
    if(t[i]==1) {
      if(same_group(par, xx, yy+n) || same_group(par, xx, yy+2*n) || same_group(par, xx+n, yy) || same_group(par, xx+n, yy + 2*n) || same_group(par, xx+2*n, yy) || same_group(par, xx+2*n, yy+n)) {
        ans++;
        continue;
      }
      unite(par, xx, yy);
      unite(par, xx+n, yy+n);
      unite(par, xx+2*n, yy+2*n);
      continue;
    } else if(t[i] == 2) {
      if(same_group(par, xx, yy) || same_group(par, xx+n, yy+n) || same_group(par, xx+2*n, yy+2*n) || same_group(par, xx, yy+2*n) || same_group(par, xx+n, yy) || same_group(par, xx+2*n, yy+n) ) {
        ans++;
        continue;
      }
      unite(par, xx, yy+n);
      unite(par, xx+n, yy+2*n);
      unite(par, xx+2*n, yy);
      continue;
    }
  }
  return ans;
}

