#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[200015];
vector<vector<long long int>> dp;
long long int n, ans, k;
void dfs(long long int cur, long long int par) {
  dp[cur][0] = 1;
  for (auto x : adj[cur]) {
    if (x == par) continue;
    dfs(x, cur);
    for (long long int i = 1; i <= k; ++i) dp[cur][i] += dp[x][i - 1];
  }
  long long int c = 0;
  ans += dp[cur][k];
  for (auto x : adj[cur]) {
    if (x == par) continue;
    for (long long int i = 0; i < k - 1; ++i) {
      long long int mi = (dp[cur][k - i - 1] - dp[x][k - i - 2]);
      c += (dp[x][i] * mi);
    }
  }
  ans += c / 2;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> k;
  dp.resize(n + 1);
  for (long long int i = 1; i <= n; ++i) dp[i].resize(k + 1, 0);
  for (long long int i = 1; i < n; ++i) {
    long long int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  cout << ans << "\n";
}
