#include <bits/stdc++.h>
using namespace std;
const int N = 500 * 1000 + 20, inf = 1e9;
int n, m, h[N], par[N], col[N];
bool is_val[N], ok;
vector<int> adj[N], ans;
void bfs(int root, bool flag = false, int c = -1) {
  queue<int> q;
  q.push(root);
  h[root] = 0;
  col[root] = c;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto u : adj[v])
      if (h[u] == inf && (flag ? adj[u].size() % 3 == 2 : true)) {
        h[u] = h[v] + 1;
        col[u] = c;
        par[u] = v;
        q.push(u);
      }
  }
}
bool have_0_vertex() {
  if (n == 1) return ok = false;
  for (int i = 0; i < n; i++)
    if (adj[i].size() % 3 == 0) {
      ans.push_back(i);
      return true;
    }
  return false;
}
bool have_121_path() {
  if (!ok) return false;
  for (int i = 0; i < n; i++)
    if (adj[i].size() % 3 == 1 && h[i] == inf) bfs(i);
  int v = -1;
  for (int i = 0; i < n; i++)
    if (adj[i].size() % 3 == 1 && h[i])
      if (v == -1 || h[i] < h[v]) v = i;
  if (v == -1) return false;
  if (h[v] == n - 1) return ok = false;
  while (~v) {
    ans.push_back(v);
    v = par[v];
  }
  return true;
}
bool have_2_cycle() {
  if (!ok) return false;
  fill(h, h + n, inf);
  fill(par, par + n, -1);
  for (int i = 0; i < n; i++)
    if (adj[i].size() % 3 == 2 && h[i] == inf) bfs(i, true);
  int v = -1, u = -1;
  for (int i = 0; i < n; i++)
    for (auto j : adj[i])
      if (adj[i].size() % 3 == 2 && h[j] <= h[i] && par[i] != j)
        if (v == -1 || h[v] > h[i] || (h[v] == h[i] && h[j] == h[i] - 1)) {
          v = i;
          u = j;
        }
  if (v == -1) return false;
  if (h[v] > h[u]) {
    ans.push_back(v);
    v = par[v];
  }
  while (true) {
    ans.push_back(v);
    if (v == u) break;
    ans.push_back(u);
    v = par[v];
    u = par[u];
  }
  if (ans.size() == n) {
    ans.clear();
    return ok = false;
  }
  return true;
}
bool have_122_componant() {
  if (!ok) return false;
  int root = -1;
  for (int i = 0; i < n; i++)
    if (adj[i].size() % 3 == 1) root = i;
  int sz = 0;
  fill(h, h + n, inf);
  fill(par, par + n, -1);
  for (auto i : adj[root])
    if (adj[i].size() % 3 == 2 && h[i] == inf) bfs(i, true, sz++);
  if (sz < 2) return false;
  int v[2] = {-1, -1};
  for (int j = 0; j < 2; j++)
    for (auto i : adj[root])
      if (adj[i].size() % 3 == 2 && col[i] == j && h[i])
        if (v[j] == -1 || h[v[j]] > h[i]) v[j] = i;
  for (int i = 0; i < 2; i++)
    while (~v[i]) {
      ans.push_back(v[i]);
      v[i] = par[v[i]];
    }
  ans.push_back(root);
  if (ans.size() == n) {
    ans.clear();
    return ok = false;
  }
  return true;
}
void prepros() {
  ans.clear();
  ok = true;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    h[i] = inf;
    col[i] = par[i] = -1;
    is_val[i] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    prepros();
    for (int i = 0; i < m; i++) {
      int v, u;
      cin >> v >> u;
      adj[--v].push_back(--u);
      adj[u].push_back(v);
    }
    if (have_0_vertex() || have_121_path() || have_2_cycle() ||
        have_122_componant()) {
      for (auto i : ans) is_val[i] = false;
      cout << "Yes\n" << n - ans.size() << "\n";
      for (int i = 0; i < n; i++)
        if (is_val[i]) cout << i + 1 << " ";
      cout << "\n";
    } else
      cout << "No\n";
  }
  return 0;
}
