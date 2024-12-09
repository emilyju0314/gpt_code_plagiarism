#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m;
int e[N];
int deg[N];
int dp[N];
vector<int> adj[N];
vector<int> in[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> e[i];
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    deg[v] += 1;
    adj[u].push_back(v);
    in[v].push_back(u);
  }
  queue<int> bfs;
  vector<int> order;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      bfs.push(i);
    }
  }
  while (!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();
    order.push_back(u);
    for (int v : adj[u]) {
      deg[v]--;
      if (deg[v] == 0) {
        bfs.push(v);
      }
    }
  }
  int res = 0;
  for (int it = 0; it < n; it++) {
    int i = order[it];
    dp[i] = e[i];
    for (int j : in[i]) {
      dp[i] = max(dp[i], dp[j]);
      if (!e[j] && e[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res << endl;
}
