#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int X = 19;
set<pair<int, int> > edges;
set<int> adj[N];
vector<int> fadj[N];
int dep[N], par[N][X];
void dfs(int v, int p) {
  dep[v] = dep[p] + 1;
  par[v][0] = p;
  for (int i = 1; i < X; i++) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (auto it : fadj[v]) {
    if (it == p) continue;
    dfs(it, v);
  }
}
int __lca(int a, int b) {
  if (dep[b] > dep[a]) swap(a, b);
  for (int i = X - 1; i >= 0; i--) {
    if (dep[a] - (1 << i) >= dep[b]) {
      a = par[a][i];
    }
  }
  if (a == b) return a;
  for (int i = X - 1; i >= 0; i--) {
    if (par[a][i] != par[b][i]) {
      a = par[a][i], b = par[b][i];
    }
  }
  return par[a][0];
}
int dist(int a, int b) { return dep[a] + dep[b] - 2 * dep[__lca(a, b)]; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    edges.insert(make_pair(a, b));
    adj[a].insert(b), adj[b].insert(a);
  }
  int kc = n;
  while (edges.size()) {
    auto it = *edges.begin();
    int a = it.first, b = it.second;
    if (adj[b].size() > adj[a].size()) swap(a, b);
    vector<int> com;
    com.push_back(a), com.push_back(b);
    for (auto it : adj[b]) {
      if (adj[a].find(it) != adj[a].end()) com.push_back(it);
    }
    sort(com.begin(), com.end());
    for (int i = 0; i < (int)com.size(); i++) {
      for (int j = i + 1; j < (int)com.size(); j++) {
        edges.erase(make_pair(com[i], com[j]));
      }
    }
    kc++;
    for (auto it : com) {
      fadj[it].push_back(kc);
      fadj[kc].push_back(it);
    }
  }
  dfs(1, 0);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << dist(a, b) / 2 << "\n";
  }
  return 0;
}
