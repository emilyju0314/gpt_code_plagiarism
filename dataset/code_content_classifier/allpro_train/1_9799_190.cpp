#include <bits/stdc++.h>
using namespace std;
int n, m, q, p[200002], adj[200002], v[200002];
int vis[200002], bst[200002], lev[200002];
vector<int> G[200002];
void dfs(int nod, int lvl) {
  lev[lvl] = nod;
  for (int nxt : G[nod]) dfs(nxt, lvl + 1);
  if (lvl - n + 1 > 0) bst[nod] = lev[lvl - n + 1];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    if (i) adj[p[i]] = p[i - 1];
  }
  adj[p[0]] = p[n - 1];
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &v[i]);
    G[vis[adj[v[i]]]].push_back(i);
    vis[v[i]] = i;
  }
  dfs(0, 0);
  for (int i = 2; i <= m; ++i) bst[i] = max(bst[i], bst[i - 1]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d", bst[r] >= l);
  }
  return 0;
}
