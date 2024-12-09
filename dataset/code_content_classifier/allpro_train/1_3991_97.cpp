#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct edge {
  int u, v, c, idx;
  bool operator<(const edge &o) const { return c > o.c; }
};
vector<edge> edges;
vector<int> g[N], sorted_vertices, final_order;
int color[N], pos[N];
bool toposort(int n);
bool dfs(int u);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.push_back({u, v, c, i});
  }
  sort(edges.begin(), edges.end());
  edges.push_back({-1, -1, 0, m + 1});
  int lo = 1, hi = m;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 0; i < mid; ++i) {
      g[edges[i].u].push_back(edges[i].v);
    }
    if (!toposort(n)) {
      hi = mid - 1;
    } else {
      final_order = sorted_vertices;
      lo = mid + 1;
    }
  }
  int first_reverse = lo - 1;
  long long ans = edges[first_reverse].c;
  for (int i = 0; i < n; ++i) {
    pos[final_order[i]] = i;
  }
  vector<int> reversed;
  for (int i = first_reverse; i < m; ++i) {
    if (pos[edges[i].u] < pos[edges[i].v]) {
      reversed.push_back(edges[i].idx);
    }
  }
  cout << ans << ' ' << reversed.size() << endl;
  for (auto &i : reversed) {
    cout << i << ' ';
  }
  cout << endl;
}
bool toposort(int n) {
  memset(color, 0, sizeof(color));
  sorted_vertices.clear();
  for (int i = 1; i <= n; ++i) {
    if (!color[i] and !dfs(i)) {
      return false;
    }
  }
  return true;
}
bool dfs(int u) {
  color[u] = 1;
  for (auto &v : g[u]) {
    if (color[v] == 1) {
      return false;
    } else if (color[v] == 0 and !dfs(v)) {
      return false;
    }
  }
  color[u] = 2;
  sorted_vertices.push_back(u);
  return true;
}
