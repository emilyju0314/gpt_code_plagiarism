#include <bits/stdc++.h>
using namespace std;
inline void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, u, v;
const int N = (int)(2e5) + 5;
vector<int> adj[N];
int a[N];
long long int h[N], dp[N];
long long int ans = 0;
long long int f = 0;
void dfs(int u, int p) {
  h[u] = h[p] + 1;
  f += (h[u] * a[u]);
  dp[u] = a[u];
  for (auto it : adj[u]) {
    if (it == p) continue;
    dfs(it, u);
    dp[u] += dp[it];
  }
}
void dfs1(int u, int p) {
  ans = max(ans, f);
  for (auto it : adj[u]) {
    if (it == p) continue;
    f -= dp[it];
    dp[u] -= dp[it];
    f += dp[u];
    dp[it] += dp[u];
    dfs1(it, u);
    dp[it] -= dp[u];
    f -= dp[u];
    dp[u] += dp[it];
    f += dp[it];
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  h[0] = -1;
  dfs(1, 0);
  ans = max(ans, f);
  dfs1(1, 0);
  cout << ans << endl;
}
int main() {
  fast();
  solve();
}
