#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, LG = 18;
vector<int> adj[N];
int n;
int ST[N][LG];
int lev[N];
int subtree_size[N];
int dfs(int idx, int l = 0, int par = -1) {
  ST[idx][0] = par;
  for (int i = 1; (1 << i) <= l; ++i) {
    ST[idx][i] = ST[ST[idx][i - 1]][i - 1];
  }
  subtree_size[idx] = 1;
  lev[idx] = l;
  for (int i = 0; i < adj[idx].size(); i++) {
    int to = adj[idx][i];
    if (to != par) {
      subtree_size[idx] += dfs(to, l + 1, idx);
    }
  }
  return subtree_size[idx];
}
int LCA(int x, int y) {
  if (lev[x] < lev[y]) swap(x, y);
  int d = lev[x] - lev[y];
  for (int i = 0; d; i++) {
    if (d & 1) x = ST[x][i];
    d >>= 1;
  }
  if (x == y) return x;
  int l = log2(lev[x]);
  for (int i = l; i >= 0; i--) {
    if (ST[x][i] != ST[y][i]) x = ST[x][i], y = ST[y][i];
  }
  return ST[x][0];
}
int KthParent(int u, int k) {
  for (int i = 0; k; i++) {
    if (k & 1) u = ST[u][i];
    k >>= 1;
  }
  return u;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int l = LCA(u, v);
    int d = lev[u] + lev[v] - 2 * lev[l];
    if (d & 1)
      puts("0");
    else if (u == v)
      printf("%d\n", n);
    else if (lev[u] == lev[v]) {
      int k = lev[u] - lev[l] - 1;
      u = KthParent(u, k);
      v = KthParent(v, k);
      printf("%d\n", n - subtree_size[u] - subtree_size[v]);
    } else {
      if (lev[u] < lev[v]) swap(u, v);
      d /= 2;
      int a = KthParent(u, d);
      int b = KthParent(u, d - 1);
      printf("%d\n", subtree_size[a] - subtree_size[b]);
    }
  }
}
