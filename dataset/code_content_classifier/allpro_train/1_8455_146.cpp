#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int B = 31;
int b[B];
int n, m;
bool mk[N];
int dp[N];
vector<pair<int, int> > e[N];
void push(int x) {
  for (int i = B - 1; i >= 0; i--) {
    if (!b[i] && ((x >> i) & 1)) {
      b[i] = x;
      break;
    } else
      x = min(x, x ^ b[i]);
  }
}
int query(int x) {
  for (int i = B - 1; i >= 0; i--) {
    x = min(x, x ^ b[i]);
  }
  return x;
}
void dfs(int u) {
  mk[u] = true;
  for (auto p : e[u]) {
    int v = p.first;
    if (mk[v]) {
      push(p.second ^ dp[u] ^ dp[v]);
      continue;
    }
    dp[v] = dp[u] ^ p.second;
    dfs(v);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  dfs(1);
  cout << query(dp[1] ^ dp[n]) << '\n';
}
