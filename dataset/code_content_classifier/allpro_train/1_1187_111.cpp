#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int mod = 1e9 + 7;
int n, m, k, x;
vector<int> adj[100005];
long long ans = 0;
long long dp[100005][3][12];
int add(int x, int y) {
  long long z = 0LL;
  z = z + x + y;
  return z % mod;
}
int mul(int x, int y) {
  long long z = 1LL;
  z = z * x * y;
  return z % mod;
}
void solve(int root, int parent) {
  dp[root][0][0] = k - 1;
  dp[root][2][0] = m - k;
  dp[root][1][1] = 1;
  if (parent != -1 && adj[root].size() == 1) return;
  for (auto child : adj[root]) {
    if (child == parent) continue;
    solve(child, root);
    long long a[12], b[12], c[12];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= i; j++) {
        a[i] = add(a[i], mul(dp[root][0][i - j],
                             add(dp[child][0][j],
                                 add(dp[child][2][j], dp[child][1][j]))));
        b[i] = add(b[i], mul(dp[root][1][i - j], dp[child][0][j]));
        c[i] = add(c[i], mul(dp[root][2][i - j],
                             add(dp[child][0][j], dp[child][2][j])));
      }
    }
    for (int i = 0; i <= x; i++) {
      dp[root][0][i] = a[i];
      dp[root][1][i] = b[i];
      dp[root][2][i] = c[i];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  cin >> k >> x;
  solve(1, -1);
  for (int i = 0; i <= x; i++)
    ans = add(ans, add(dp[1][0][i], add(dp[1][1][i], dp[1][2][i])));
  cout << ans << endl;
}
