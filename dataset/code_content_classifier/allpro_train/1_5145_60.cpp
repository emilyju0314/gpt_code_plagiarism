#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 1e6 + 5, LG = 19, MOD = 998244353;
const int SQ = 225;
const long double EPS = 1e-7;
int x, k;
double p, dp[205][205];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> k >> p;
  p /= 100.0;
  for (int i = 0; i < k + 1; i++) {
    dp[0][i] = __builtin_ctz(x + i);
  }
  for (int i = 1; i < k + 1; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (j * 2 <= k) dp[i][j + j] += (dp[i - 1][j] + 1) * p;
      if (j - 1 >= 0) dp[i][j - 1] += (dp[i - 1][j]) * (1.0 - p);
    }
  }
  cout << fixed << setprecision(6) << dp[k][0] << '\n';
  return 0;
}
