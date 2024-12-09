#include <bits/stdc++.h>
using namespace std;
long long modulo = (long long)1e15 + 7;
const long long N = (long long)1e5 + 10;
long long fpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % modulo;
    a = (a * a) % modulo;
    b = b >> 1;
  }
  return ans;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  int a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  if (n >= 4 and m >= 4) {
    cout << -1 << '\n';
    return;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (n == 2) {
    long long dp[m][2];
    dp[0][0] = a[0][0] ^ a[1][0];
    dp[0][1] = a[0][0] ^ a[1][0] ^ 1;
    for (long long i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][1] + (a[0][i] ^ a[1][i]);
      dp[i][1] = dp[i - 1][0] + (a[0][i] ^ a[1][i] ^ 1);
    }
    cout << min(dp[m - 1][0], dp[m - 1][1]) << '\n';
    return;
  }
  if (n == 3) {
    long long dp[m][4];
    dp[0][0] = 5;
    dp[0][1] = 5;
    dp[0][2] = 5;
    dp[0][3] = 5;
    long long refer[8] = {0, 1, 2, 3, 3, 2, 1, 0};
    for (long long j = 0; j < 8; j++) {
      long long cost = 0;
      for (long long k = 0; k < 3; k++) {
        if (((j >> k) & 1) ^ a[k][0] ^ 1) {
          cost += 1;
        }
      }
      dp[0][refer[j]] = min(dp[0][refer[j]], cost);
    }
    for (long long i = 1; i < m; i++) {
      dp[i][0] = 5;
      dp[i][1] = 5;
      dp[i][2] = 5;
      dp[i][3] = 5;
      for (long long j = 0; j < 8; j++) {
        long long cost = 0;
        for (long long k = 0; k < 3; k++) {
          if (((j >> k) & 1) ^ a[k][i] ^ 1) {
            cost += 1;
          }
        }
        dp[i][refer[j]] = min(dp[i][refer[j]], cost);
      }
      dp[i][0] += dp[i - 1][2];
      dp[i][1] += dp[i - 1][3];
      dp[i][2] += dp[i - 1][0];
      dp[i][3] += dp[i - 1][1];
    }
    long long ans = dp[m - 1][0];
    ans = min(ans, dp[m - 1][1]);
    ans = min(ans, dp[m - 1][2]);
    ans = min(ans, dp[m - 1][3]);
    cout << ans << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
  return 0;
}
