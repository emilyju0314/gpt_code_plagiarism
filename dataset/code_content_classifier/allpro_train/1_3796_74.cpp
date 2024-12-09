#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 1;

int n, m;
int a[N];
bool vis[N];
vector<int> adj[N];

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> m;
  set<pair<int, int>> s;
  for (int i = 1, v, k; i <= m; i++) {
    cin >> v >> k;
    a[v] = k;
    s.insert({-a[v], v});
  }
  while (!s.empty()) {
    int k = -s.begin()->first, v = s.begin()->second;
    s.erase(s.begin());
    if (vis[v]) continue;
    vis[v] = 1;
    for (auto& u : adj[v]) {
      if (vis[u] || s.find({-a[u], u}) != s.end()) continue;
      a[u] = k - 1;
      s.insert({-a[u], u});
    }
  }
  memset(vis, 0, sizeof vis);
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (auto& u : adj[v]) {
      if (abs(a[u] - a[v]) != 1) {
        return cout << "No", 0;
      }
      q.push(u);
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
  }
}