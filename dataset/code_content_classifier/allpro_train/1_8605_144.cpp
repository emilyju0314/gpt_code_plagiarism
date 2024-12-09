#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct Edge {
  int u, v;
  Edge* next;
} E[MAXN], *tot, *head[MAXN];
int deg[MAXN], vis[MAXN], dis[MAXN];
void init() { tot = E; }
void Add(int u, int v) {
  tot->u = u;
  tot->v = v;
  tot->next = head[u];
  head[u] = tot++;
}
int SPFA() {
  int s, t;
  cin >> s >> t;
  memset(dis, 0x3f, sizeof(dis));
  dis[t] = 0;
  deque<int> DQ;
  DQ.push_back(t);
  while (!DQ.empty()) {
    int u = DQ.front();
    DQ.pop_front();
    if (vis[u]) continue;
    vis[u] = 1;
    if (u == s) return dis[s];
    for (Edge* p = head[u]; p; p = p->next) {
      --deg[p->v];
      int w = deg[p->v] > 0;
      if (dis[p->v] > dis[u] + w) {
        dis[p->v] = dis[u] + w;
        if (w)
          DQ.push_back(p->v);
        else
          DQ.push_front(p->v);
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  init();
  while (m--) {
    cin >> u >> v;
    ++deg[u];
    Add(v, u);
  }
  cout << SPFA() << endl;
  return 0;
}
