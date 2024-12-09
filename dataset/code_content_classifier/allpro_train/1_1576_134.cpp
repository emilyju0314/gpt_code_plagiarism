#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct node {
  int v;
  int a;
} dd[MAXN];
int n, m, k;
int a[MAXN];
vector<int> g[MAXN];
int dis[2][MAXN];
bool vis[MAXN];
queue<int> que;
void bfs(int x, int st) {
  for (int i = 1; i <= n; i++) {
    dis[x][i] = 2e9;
    vis[i] = false;
  }
  dis[x][st] = 0;
  vis[st] = true;
  while (!que.empty()) que.pop();
  que.push(st);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (vis[v]) continue;
      dis[x][v] = dis[x][u] + 1;
      que.push(v);
      vis[v] = true;
    }
  }
}
bool cmp(node a, node b) { return a.v < b.v; }
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(0, 1);
  bfs(1, n);
  for (int i = 1; i <= k; i++) {
    dd[i].v = dis[0][a[i]] - dis[1][a[i]];
    dd[i].a = a[i];
  }
  sort(dd + 1, dd + 1 + k, cmp);
  int maxx = 0;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (i != 1) {
      ans = max(ans, maxx + dis[1][dd[i].a] + 1);
    }
    maxx = max(maxx, dis[0][dd[i].a]);
  }
  cout << min(ans, dis[0][n]) << endl;
  return 0;
}
