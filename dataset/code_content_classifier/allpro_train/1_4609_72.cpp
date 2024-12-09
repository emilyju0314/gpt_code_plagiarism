#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
template <typename num>
inline num ceil(num a, num b) {
  return (a + b - 1) / b;
}
template <typename num>
inline num lcm(num a, num b) {
  return a * (b / __gcd(a, b));
}
template <typename num>
inline num sum(num x) {
  return x * (x + 1) / 2;
}
const int MAXN = 2e5 + 5;
int t[MAXN], x[MAXN], y[MAXN], dp[MAXN], pre[MAXN];
int dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
int r;
int f(int i) {
  if (i == 0) return 0;
  if (~dp[i]) return dp[i];
  int ans = 0;
  for (int j = max(0, i - 2 * r); j < i; ++j) {
    if (dist(i, j) <= t[i] - t[j]) ans = max(ans, 1 + f(j));
  }
  if (i - 2 * r >= 0) ans = max(ans, 1 + pre[i - 2 * r]);
  return dp[i] = (ans ? ans : -oo);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  while (test--) {
    int n;
    cin >> r >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> t[i] >> x[i] >> y[i];
    }
    x[0] = y[0] = 1;
    memset(dp, -1, sizeof dp);
    memset(pre, -1, sizeof pre);
    pre[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = max(ans, f(i));
      pre[i] = dp[i];
      pre[i] = max(pre[i], pre[i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
