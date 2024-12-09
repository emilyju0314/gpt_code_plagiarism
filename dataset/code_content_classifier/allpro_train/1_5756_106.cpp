#include <bits/stdc++.h>
using namespace std;
struct node {
  int v;
  long long w;
  node(){};
  node(int V, long long W) { v = V, w = W; }
};
int n, m, dep[200005], dp[200005][21], fa[200005], U[200005], V[200005];
long long cost[200005];
vector<node> G[200005];
void dfs(int u, int fa0) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].v;
    if (v == fa0) continue;
    dep[v] = dep[u] + 1;
    dp[v][0] = u;
    dfs(v, u);
    cost[v] = G[u][i].w;
    fa[v] = v;
    if (G[u][i].w == 1 && fa0 != 0) fa[v] = u;
  }
}
void build(int root) {
  dfs(root, 0);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
void mov(int &u, int v) {
  for (int i = 20; i >= 0; i--)
    if (dep[dp[u][i]] >= dep[v]) u = dp[u][i];
}
int getlca(int u, int v) {
  if (dep[u] > dep[v]) mov(u, v);
  if (dep[u] < dep[v]) mov(v, u);
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  return dp[u][0];
}
int findset(int x) {
  if (fa[x] != x) fa[x] = findset(fa[x]);
  return fa[x];
}
void make(int l, int fuck, long long &c) {
  while (c && dep[l] > dep[fuck]) {
    c = c / cost[l];
    l = dp[l][0];
    l = findset(l);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    long long w;
    scanf("%d%d", &U[i], &V[i]);
    scanf("%lld", &w);
    G[U[i]].push_back(node(V[i], w));
    G[V[i]].push_back(node(U[i], w));
  }
  build(1);
  while (m--) {
    int flag;
    scanf("%d", &flag);
    if (flag == 1) {
      int a, b;
      long long c;
      scanf("%d%d%lld", &a, &b, &c);
      int lca = getlca(a, b);
      make(a, lca, c);
      make(b, lca, c);
      printf("%lld\n", c);
    } else {
      int p;
      long long c;
      scanf("%d%lld", &p, &c);
      int u = U[p];
      int v = V[p];
      if (dep[U[p]] < dep[V[p]]) swap(U[p], V[p]);
      cost[U[p]] = c;
      if (c == 1) fa[U[p]] = fa[V[p]];
    }
  }
}
