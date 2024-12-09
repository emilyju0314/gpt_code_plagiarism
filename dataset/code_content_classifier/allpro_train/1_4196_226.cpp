#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 5;
int n, m, q;
vector<int> adj[maxN];
int group[maxN], height[maxN], dist[maxN];
bool vis[maxN];
tuple<int, int> dfs(int u, bool svis, int g) {
  vis[u] = 1;
  group[u] = g;
  int best = 0, flag = u;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (!vis[v]) {
      int w, d;
      tie(w, d) = dfs(v, svis, g);
      d++;
      if (d > best) {
        best = d;
        flag = w;
      }
    }
  }
  vis[u] = svis;
  return make_tuple(flag, best);
}
int getGroup(int v) {
  if (v == group[v]) {
    return v;
  }
  v = getGroup(group[v]);
}
void merge(int x, int y, int l) {
  if (height[x] < height[y]) {
    group[x] = y;
    dist[y] = l;
  } else {
    group[y] = x;
    dist[x] = l;
    height[x] += (height[x] == height[y]);
  }
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      int u = get<0>(dfs(i, 0, i));
      int d = get<1>(dfs(u, 1, i));
      dist[i] = d;
    }
  }
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v;
      cin >> v;
      v--;
      v = getGroup(v);
      printf("%d\n", dist[v]);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      x--, y--;
      x = getGroup(x), y = getGroup(y);
      if (x != y) {
        int l1 = dist[x], l2 = dist[y];
        int l = max(l1, l2);
        l = max(l, l1 / 2 + (l1 % 2) + l2 / 2 + (l2 % 2) + 1);
        merge(x, y, l);
      }
    }
  }
}
