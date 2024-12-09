#include <bits/stdc++.h>
using namespace std;
const long long maxn = 505, inf = 2e18;
long long n, a[maxn], dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long k = 0; k < n; k++) {
    for (long long i = 0; i + k < n; i++) {
      if (k == 0)
        dp[i][i] = 1;
      else if (k == 1) {
        if (a[i] == a[i + 1])
          dp[i][i + k] = 1;
        else
          dp[i][i + k] = 2;
      } else {
        dp[i][i + k] = k + 1;
        if (a[i] == a[i + k]) dp[i][i + k] = dp[i + 1][i + k - 1];
        for (long long j = i; j < i + k; j++)
          dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}
