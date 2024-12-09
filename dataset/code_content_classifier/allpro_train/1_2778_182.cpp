#include <bits/stdc++.h>
using namespace std;
const long long mx = 3e5 + 5, mx2 = 20;
long long n, q, dp[mx][mx2], lst[mx2], s[mx], ans[mx];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < mx2; j++) {
      if ((1 << j) & s[i]) {
        dp[i][j] = i;
        long long r = lst[j];
        if (r != 0) {
          for (long long k = 0; k < mx2; k++) {
            dp[i][k] = max(dp[i][k], dp[r][k]);
          }
        }
      }
    }
    for (long long j = 0; j < mx2; j++) {
      if ((1 << j) & s[i]) {
        lst[j] = i;
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    for (long long j = 0; j < mx2; j++) {
      if (dp[r][j] >= l && ((1 << j) & s[l])) {
        ans[i] = 1;
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    if (ans[i] == 1) {
      cout << "Shi" << endl;
    } else {
      cout << "Fou" << endl;
    }
  }
  return 0;
}
