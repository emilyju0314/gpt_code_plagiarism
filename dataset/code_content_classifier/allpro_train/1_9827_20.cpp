#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int MOD = 1e9 + 7;
const int S = 1024;
int n, m, t, k;
int tst;
int a[N];
int target;
int memo[N][S][2];
int dp(int i, int sum, int ok) {
  if (i >= n) return (sum >= target) | ok;
  if (memo[i][sum][ok] != -1) return memo[i][sum][ok];
  int res = 0;
  if (a[i] == 2 || a[i] == 0) {
    if (sum & 1)
      res += dp(i + 1, 2, (sum >= target) | ok);
    else
      res += dp(i + 1, min(sum + 2, S), (sum + 2 >= target) | ok);
    res %= MOD;
  }
  if (a[i] == 1 || a[i] == 0) {
    res += dp(i + 1, min(sum + 1, S), (sum + 1 >= target) | ok);
    res %= MOD;
  }
  return memo[i][sum][ok] = res % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    a[i] >>= 1;
  }
  target = (1 << (k - 1));
  memset(memo, -1, sizeof(memo));
  cout << dp(0, 0, 0);
}
