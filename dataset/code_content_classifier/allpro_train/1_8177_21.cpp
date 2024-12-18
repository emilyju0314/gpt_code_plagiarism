#include <bits/stdc++.h>
using namespace std;
const int max_n = 200010;
int n, m, q;
vector<pair<int, long long> > adj[max_n];
int p[max_n];
long long sz[max_n];
int par[max_n][25];
int d[max_n][25];
int per[max_n];
int l[max_n];
vector<pair<long long, pair<int, int> > > edge;
int find(int v) {
  if (p[v] == v) return v;
  return p[v] = find(p[v]);
}
void uni(int u, int v, long long c) {
  u = find(u);
  v = find(v);
  p[u] = v;
  sz[v] += sz[u] + c;
}
bool cmp(const int &A, const int &B) { return edge[A].first < edge[B].first; }
void dfs(int v, int dad) {
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first;
    int c = adj[v][i].second;
    if (u == dad) continue;
    d[u][0] = c;
    par[u][0] = v;
    l[u] = l[v] + 1;
    dfs(u, v);
  }
}
void init() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 24; j++) par[i][j] = -1;
  dfs(1, 0);
  for (int j = 1; j <= 24; j++)
    for (int i = 1; i <= n; i++) {
      if (par[i][j - 1] != -1) {
        d[i][j] = max(d[i][j - 1], d[par[i][j - 1]][j - 1]);
        par[i][j] = par[par[i][j - 1]][j - 1];
      }
    }
}
int lca(int u, int v) {
  if (l[v] > l[u]) swap(u, v);
  int ans = 0;
  for (int i = 24; i >= 0; i--)
    if (l[u] - (1 << i) >= l[v]) {
      ans = max(ans, d[u][i]);
      u = par[u][i];
    }
  if (u == v) return ans;
  for (int i = 24; i >= 0; i--)
    if (par[u][i] != -1 && par[u][i] != par[v][i]) {
      ans = max(ans, d[v][i]);
      v = par[v][i];
      ans = max(ans, d[u][i]);
      u = par[u][i];
    }
  return max(ans, max(d[u][0], d[v][0]));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    edge.push_back(make_pair(c, make_pair(a, b)));
    per[i] = i;
  }
  sort(per, per + m, cmp);
  int com = n;
  for (int i = 0; i < m; i++) {
    int u = edge[per[i]].second.first;
    int v = edge[per[i]].second.second;
    long long c = edge[per[i]].first;
    if (find(u) != find(v)) {
      uni(u, v, c);
      adj[u].push_back(make_pair(v, c));
      adj[v].push_back(make_pair(u, c));
      com--;
    }
  }
  init();
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    if (com == 3 || (com == 2 && find(u) == find(v)))
      cout << -1 << endl;
    else if (com == 2)
      cout << sz[find(u)] + sz[find(v)] << endl;
    else
      cout << sz[find(u)] - lca(u, v) << endl;
  }
  return 0;
}
