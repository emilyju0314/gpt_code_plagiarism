#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int INF = 1e8;
int n, m, cnt, d[N], p[N];
map<int, bool> c[N];
vector<int> adj[N];
void Input() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    c[u][v] = c[v][u] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 2; i <= n; i++) d[i] = INF;
}
bool BFS() {
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v : adj[u]) {
      if (d[v] != INF) continue;
      p[v] = u, d[v] = d[u] + 1;
      Q.push(v);
    }
  }
  if (d[n] > 4) return false;
  return true;
}
pair<int, int> Get(int u) {
  for (int v1 : adj[u]) {
    if (v1 == 1) continue;
    for (int v2 : adj[v1]) {
      if (v2 == u || v2 == 1) continue;
      if (!c[u][v2]) return make_pair(v1, v2);
    }
  }
  return make_pair(-1, -1);
}
void Solve() {
  if (BFS()) {
    int u = n;
    vector<int> tmp;
    while (u != 0) {
      tmp.push_back(u);
      u = p[u];
    }
    cout << d[n] << '\n';
    for (int i = tmp.size() - 1; i >= 0; i--) cout << tmp[i] << " ";
    return;
  }
  for (int i = 2; i <= n; i++) {
    if (d[i] == 2) {
      cout << 4 << '\n'
           << 1 << " " << p[i] << " " << i << " " << 1 << " " << n << '\n';
      return;
    }
  }
  for (int u : adj[1]) {
    if (adj[u].size() > 1 && adj[u].size() < adj[1].size()) {
      pair<int, int> res = Get(u);
      if (res.first == -1) continue;
      cout << 5 << '\n';
      cout << 1 << " " << u << " " << res.first << " " << res.second << " " << u
           << " " << n << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Input();
  Solve();
  return 0;
}
