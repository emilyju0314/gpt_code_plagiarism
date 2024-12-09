#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
struct Edge {
  int u, v, nxt;
} edge[(500005) << 1];
int head[maxn], tot, depth[maxn], father[maxn];
bool vis[maxn];
inline void init() {
  memset(head, -1, sizeof(head));
  memset(depth, 0, sizeof(depth));
  tot = 0;
}
inline void addedge(int u, int v) {
  edge[++tot] = {u, v, head[u]};
  head[u] = tot;
}
bool isok = false;
int n, m, k;
vector<int> leaves;
void dfs(int u, int fa, int dep) {
  vis[u] = true;
  father[u] = fa;
  depth[u] = dep;
  if (isok) return;
  if (dep >= (n + k - 1) / k) {
    isok = true;
    cout << "PATH" << '\n';
    cout << dep << '\n';
    while (u) {
      cout << u << ' ';
      u = father[u];
    }
    cout << '\n';
    return;
  }
  bool isleaf = true;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    Edge &e = edge[i];
    if (!vis[e.v]) {
      vis[e.v] = true;
      isleaf = false;
      dfs(e.v, u, dep + 1);
    }
  }
  if (isleaf) leaves.push_back(u);
  return;
}
inline void CreateCircle() {
  cout << "CYCLES" << '\n';
  for (int cnt = 0; cnt < k; ++cnt) {
    int x = 0, y = 0, z = leaves[cnt];
    for (int i = head[z]; ~i; i = edge[i].nxt) {
      if (edge[i].v != father[z]) {
        if (!x)
          x = edge[i].v;
        else
          y = edge[i].v;
      }
    }
    if ((depth[z] - depth[x] + 1) % 3) {
      cout << depth[z] - depth[x] + 1 << '\n';
      for (; cout << z << ' ', z != x; z = father[z])
        ;
      cout << '\n';
    } else if ((depth[z] - depth[y] + 1) % 3) {
      cout << depth[z] - depth[y] + 1 << '\n';
      for (; cout << z << ' ', z != y; z = father[z])
        ;
      cout << '\n';
    } else {
      if (depth[x] < depth[y]) swap(x, y);
      cout << depth[x] - depth[y] + 2 << '\n';
      for (; cout << x << ' ', x != y; x = father[x])
        ;
      cout << z << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    addedge(u, v);
    addedge(v, u);
  }
  dfs(1, 0, 1);
  if (!isok) {
    CreateCircle();
  }
  return 0;
}
