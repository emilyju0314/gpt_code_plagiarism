#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010], path;
int pai[100010], dist1[100010], who1[100010], dist2[100010], who2[100010],
    up[100010];
bool mark[100010];
void dfs(int u) {
  who1[u] = who2[u] = -1;
  dist1[u] = dist2[u] = -1;
  path.push_back(u);
  for (int i = 0; i < int(adj[u].size()); i++) {
    int v = adj[u][i];
    if (v == pai[u]) continue;
    pai[v] = u;
    dfs(v);
    if (dist1[v] != -1 && dist1[v] + 1 > dist1[u]) {
      dist2[u] = dist1[u];
      who2[u] = who1[u];
      dist1[u] = dist1[v] + 1;
      who1[u] = who1[v];
    } else if (dist1[v] != -1 && dist1[v] + 1 > dist2[u]) {
      dist2[u] = dist1[v] + 1;
      who2[u] = who1[v];
    }
  }
  if (mark[u]) {
    if (dist1[u] == -1) {
      dist1[u] = 0;
      who1[u] = u;
    } else if (dist2[u] == -1) {
      dist2[u] = 0;
      who2[u] = u;
    }
  }
  return;
}
int main() {
  int n, m, d, ans;
  scanf("%d%d%d", &n, &m, &d);
  memset(mark, false, sizeof(mark));
  while (m--) {
    int u;
    scanf("%d", &u);
    mark[u - 1] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pai[0] = -1;
  dfs(0);
  ans = 0;
  up[0] = (mark[0] ? 0 : -1);
  if (dist1[0] <= d && up[0] <= d) ans++;
  for (int i = 1; i < n; i++) {
    int u = path[i];
    up[u] = -1;
    if (up[pai[u]] != -1) up[u] = up[pai[u]] + 1;
    if (who1[pai[u]] != -1 && who1[pai[u]] != who1[u])
      up[u] = max(up[u], dist1[pai[u]] + 1);
    else if (who2[pai[u]] != -1)
      up[u] = max(up[u], dist2[pai[u]] + 1);
    if (up[u] == -1 && mark[u]) up[u] = 0;
    if (dist1[u] <= d && up[u] <= d) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
