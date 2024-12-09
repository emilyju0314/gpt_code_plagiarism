#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
vector<int> g[2][maxn];
int fa[2][maxn];
int pp[maxn];
vector<pair<pair<int, int>, pair<int, int> > > gg;
int find(int p) {
  if (pp[p] == -1 || pp[p] == p) return pp[p] = p;
  return pp[p] = find(pp[p]);
}
int panduan(int u, int x, int y) {
  if (fa[u][x] == y || fa[u][y] == x) return 1;
  return 0;
}
void dfs(int u, int p, int pa) {
  fa[u][p] = pa;
  for (int v : g[u][p]) {
    if (v == pa) continue;
    dfs(u, v, p);
  }
}
void solve(int u, int pa) {
  for (int v : g[0][u]) {
    if (v != pa) {
      solve(v, u);
      if (!panduan(1, u, v)) {
        int w = find(v);
        gg.push_back(make_pair(make_pair(u, v), make_pair(w, fa[1][w])));
      }
    }
  }
}
int main() {
  int i, n;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[0][x].push_back(y);
    g[0][y].push_back(x);
  }
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[1][x].push_back(y);
    g[1][y].push_back(x);
  }
  dfs(0, 1, -1);
  dfs(1, 1, -1);
  memset(pp, -1, sizeof(pp));
  for (i = 2; i <= n; i++) {
    if (panduan(0, i, fa[1][i])) {
      pp[i] = fa[1][i];
    }
  }
  solve(1, -1);
  int p = gg.size();
  printf("%d\n", p);
  for (i = 0; i < p; i++) {
    printf("%d %d %d %d\n", gg[i].first.first, gg[i].first.second,
           gg[i].second.first, gg[i].second.second);
  }
}
