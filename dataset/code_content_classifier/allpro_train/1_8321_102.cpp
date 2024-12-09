#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int Max[N];
int Par[N], Sz[N];
int Find(int u) { return u == Par[u] ? u : Par[u] = Find(Par[u]); }
void Merge(int u, int v, int w) {
  if (Sz[u] > Sz[v]) swap(u, v);
  Par[u] = v;
  Sz[v] += Sz[u];
  Max[v] = max({Max[v], Max[u], w});
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edges.push_back({w, {u, v}});
  }
  sort(edges.begin(), edges.end());
  for (int u = 1; u <= n; u++) Par[u] = u, Sz[u] = 1;
  int Answer = 0;
  for (int i = 0; i < m; i++) {
    int j = i;
    vector<pair<int, pair<int, int>>> cur;
    while (j < m && edges[i].first == edges[j].first) {
      int u = Find(edges[j].second.first);
      int v = Find(edges[j].second.second);
      if (u == v) {
        if (Max[u] >= edges[j].first) Answer += Max[u] - edges[j].first + 1;
      } else
        cur.push_back(edges[j]);
      j++;
    }
    i = j - 1;
    for (auto e : cur) {
      int u = Find(e.second.first);
      int v = Find(e.second.second);
      int w = e.first;
      if (u == v) {
        if (Max[u] >= w) Answer += Max[u] - w + 1;
        continue;
      }
      Merge(u, v, w);
    }
  }
  printf("%d\n", Answer);
  return 0;
}
