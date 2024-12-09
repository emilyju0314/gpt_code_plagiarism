#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17 + 9;
int l;
long long n, m;
vector<int> adj[100009];
vector<int> sccs;
int dfs_low[100009];
int dfs_num[100009];
int vis[100009];
int dfscounter = 1;
vector<int> anses[100009];
vector<pair<long long, long long>> edges;
vector<int> adj2[100009];
long long tp[100009];
int contans = -1;
int timer;
long long res[100009];
vector<int> tin, tout;
vector<vector<int>> up;
long long mult(long long a, long long b) { return a * b % 1000000007; }
long long fastpow(long long a, long long b) {
  long long calc = 1;
  for (; b >= 1LL; b /= 2LL) {
    if ((b & 1LL)) calc = mult(calc, a);
    a = mult(a, a);
  }
  return calc;
}
long long soma(long long a, long long b) {
  if (a + b > 1000000007)
    return a + b - 1000000007;
  else
    return a + b;
}
long long subt(long long a, long long b) {
  if (a - b < 0)
    return a - b + 1000000007;
  else
    return a - b;
}
void dfs(int x, int pai) {
  vis[x] = 1;
  sccs.push_back(x);
  dfs_num[x] = dfs_low[x] = dfscounter++;
  for (auto e : adj[x]) {
    if (dfs_num[e] == 0) {
      dfs(e, x);
    }
    if (pai != e && vis[e] == 1) {
      dfs_low[x] = min(dfs_low[x], dfs_low[e]);
    }
  }
  if (dfs_low[x] == dfs_num[x]) {
    contans++;
    while (1) {
      int vert = sccs.back();
      sccs.pop_back();
      vis[vert] = 0;
      anses[contans].push_back(vert);
      if (vert == x) break;
    }
  }
}
void calc(int v, int p) {
  res[v] += tp[v];
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (int u : adj2[v]) {
    if (u != p) {
      res[u] += res[v];
      calc(u, v);
    }
  }
  tout[v] = ++timer;
}
bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void preprocess(int root) {
  tin.resize(n + 1);
  tout.resize(n + 1);
  timer = 0;
  l = ceil(log2(n + 1));
  up.assign(n + 1, vector<int>(l + 1));
  calc(root, root);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges.push_back({a, b});
  }
  for (int i = 1; i <= n; i++) {
    if (dfs_num[i] == 0) dfs(i, i);
  }
  map<int, int> trad;
  memset(tp, 0, sizeof 100009);
  for (long long i = 0; i < (contans + 1); ++i) {
    if ((long long)(anses[i]).size() > 2) tp[anses[i].back()] = 1;
    for (auto e : anses[i]) {
      trad[e] = anses[i].back();
    }
  }
  memset(vis, -1, sizeof vis);
  for (auto e : edges) {
    if (trad[e.first] != trad[e.second]) {
      adj2[trad[e.first]].push_back(trad[e.second]);
      adj2[trad[e.second]].push_back(trad[e.first]);
    }
  }
  preprocess(trad[1]);
  long long xy = lca(trad[9], trad[10]);
  long long k;
  cin >> k;
  while (k--) {
    long long a, b;
    cin >> a >> b;
    long long x = lca(trad[a], trad[b]);
    cout << fastpow(2, res[trad[a]] + res[trad[b]] - 2 * res[x] + tp[x])
         << '\n';
  }
  return 0;
}
