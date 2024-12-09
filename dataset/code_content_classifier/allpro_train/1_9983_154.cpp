#include <bits/stdc++.h>
using namespace std;
long long dp[71][71][36][71];
long long n, m, k;
long long tocal(long long num) {
  if (num % k != 0)
    return -1e9;
  else
    return 0;
}
long long vals[71][71];
long long calc(long long i, long long j, long long take, long long has) {
  if (i >= n) {
    return tocal(has);
  }
  if (j == m || take >= m / 2) {
    long long num = -1e9;
    if (has == 0) num = 0;
    return max(calc(i + 1, 0, 0, has), num);
  }
  if (dp[i][j][take][has] != -1) {
    return dp[i][j][take][has];
  }
  long long ret = -1e9;
  if (has == 0) ret = 0;
  if (take < m / 2)
    ret =
        max(ret, calc(i, j + 1, take + 1, (has + vals[i][j]) % k) + vals[i][j]);
  ret = max(calc(i, j + 1, take, has), ret);
  return dp[i][j][take][has] = ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> vals[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << calc(0, 0, 0, 0);
  return 0;
}
