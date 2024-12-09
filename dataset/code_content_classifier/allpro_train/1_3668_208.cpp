#include <bits/stdc++.h>
using namespace std;
int n, m, ghd, hd[100005], dis[100005];
vector<int> tr[100005];
bool vis[100005];
struct Edge {
  int u, v, w, nxt;
} g[200005];
void AddEdge(int u, int v, int w) {
  g[ghd] = (Edge){u, v, w, hd[u]};
  hd[u] = ghd++;
}
void Dijkstra() {
  priority_queue<pair<int, int> > Q;
  Q.push(make_pair(0, 1));
  while (!Q.empty()) {
    int u = Q.top().second, tm = -Q.top().first;
    Q.pop();
    if (vis[u])
      continue;
    else
      vis[u] = true;
    bool flg = false;
    for (int i = 0; i < tr[u].size(); i++) {
      if (flg) {
        if (tr[u][i] == tm)
          tm++;
        else
          break;
      } else {
        if (tr[u][i] == tm)
          tm++, flg = true;
        else
          continue;
      }
    }
    for (int i = hd[u]; ~i; i = g[i].nxt) {
      int v = g[i].v, w = g[i].w + tm;
      if (w < dis[v]) {
        dis[v] = w;
        Q.push(make_pair(-dis[v], v));
      }
    }
  }
}
int main() {
  memset(hd, -1, sizeof(hd));
  memset(dis, 0x3f, sizeof(dis));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    AddEdge(u, v, w);
    AddEdge(v, u, w);
  }
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int t;
      scanf("%d", &t);
      tr[i].push_back(t);
    }
  }
  Dijkstra();
  if (dis[n] == dis[n + 1])
    printf("-1");
  else
    printf("%d", dis[n]);
  return 0;
}
