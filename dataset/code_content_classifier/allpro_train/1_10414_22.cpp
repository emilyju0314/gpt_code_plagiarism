#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
long long n, m, dp[5005][5005], ans;
string A, B;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> A >> B;
  A = ' ' + A;
  B = ' ' + B;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
      dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
      if (A[i] == B[j]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
      }
      ans = max(dp[i][j], ans);
    }
  }
  cout << ans << endl;
  return 0;
}
