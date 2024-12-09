#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  constexpr int mod = 1e9 + 7;
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1, 1), dpnxt(n + 1, 0);
  dp[0] = 0;
  for (int j = 1; j < k; ++j) {
    for (int x = 1; x <= n; ++x) {
      for (int y = x; y <= n; y += x) {
        dpnxt[x] += dp[y];
        if (dpnxt[x] >= mod) dpnxt[x] -= mod;
      }
    }
    fill(begin(dp), end(dp), 0), swap(dp, dpnxt);
  }
  int res = 0;
  for (int x = 1; x <= n; ++x) {
    res += dp[x];
    if (res >= mod) res -= mod;
  }
  cout << res << '\n';
  exit(0);
}
