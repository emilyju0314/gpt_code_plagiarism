#include <bits/stdc++.h>
using namespace std;
int vis[510];
vector<pair<int, int> > g[510];
void dfs(int cnt, int lef, int rig) {
  vis[cnt] = 1;
  for (int i = 0; i < (int)g[cnt].size(); i++) {
    if (g[cnt][i].second >= lef && g[cnt][i].second <= rig) continue;
    int nex = g[cnt][i].first;
    if (!vis[nex]) dfs(nex, lef, rig);
  }
}
int main() {
  int n, m, i, k, res, lef, rig, u, v;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
  }
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d", &lef, &rig);
    memset(vis, 0, sizeof(vis));
    for (i = 1, res = 0; i <= n; i++)
      if (!vis[i]) {
        dfs(i, lef, rig);
        res++;
      }
    printf("%d\n", res);
  }
  return 0;
}
