#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> G[1000006];
int par[1000006];
int best = 1e9;
int bestFromRoot[1000006];
bool vis[1000006];
void dfs(int u, int p, int mn) {
  par[u] = p;
  mn = min(mn, u);
  bestFromRoot[u] = mn;
  for (int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    if (p == v) continue;
    dfs(v, u, mn);
  }
}
void update(int u) {
  while (u != -1 && !vis[u]) {
    vis[u] = true;
    best = min(best, u);
    u = par[u];
  }
}
int query(int u) { return min(best, bestFromRoot[u]); }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int last = 0;
  int type, x;
  scanf("%d%d", &type, &x);
  x = (x + last) % n + 1;
  dfs(x, -1, 1e9);
  q--;
  while (q--) {
    scanf("%d%d", &type, &x);
    x = (x + last) % n + 1;
    if (type == 1) {
      update(x);
    } else {
      int ans = query(x);
      printf("%d\n", ans);
      last = ans;
    }
  }
  return 0;
}
