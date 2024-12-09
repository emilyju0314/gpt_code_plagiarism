#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = (int)1e9 + 7;
const int MAXN = (int)2e6 + 7;
int n, m, q;
int dsu[MAXN];
int val[MAXN];
int root;
vector<int> g[MAXN];
pair<int, int> mdist;
void dfs(int v, int parent = 0, int h = 0) {
  dsu[v] = root;
  mdist = max(mdist, make_pair(h, v));
  for (auto to : g[v]) {
    if (to != parent) dfs(to, v, h + 1);
  }
}
int get(int x) {
  if (x == dsu[x]) return x;
  return dsu[x] = get(dsu[x]);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dsu[i]) {
      root = i;
      mdist = make_pair(0, 0);
      dfs(i);
      int x = mdist.second;
      mdist = make_pair(0, 0);
      dfs(x);
      val[root] = mdist.first;
    }
  }
  while (q--) {
    int type, x, y;
    scanf("%d%d", &type, &x);
    if (type == 1) {
      printf("%d\n", val[get(x)]);
    } else {
      scanf("%d", &y);
      x = get(x);
      y = get(y);
      if (x == y) continue;
      dsu[x] = y;
      val[y] =
          max(max(val[x], val[y]), (val[x] + 1) / 2 + (val[y] + 1) / 2 + 1);
    }
  }
  return 0;
}
