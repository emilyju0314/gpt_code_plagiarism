#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 155, M = N * N / 2;
const long long INF = 2e9;
long long a[N];
long long dp[2][N][M];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, k, s;
  cin >> n >> k >> s;
  s = min(s, n * (n - 1) / 2);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<long long, long long>> before, after;
  for (long long i = 0; i < k; i++) {
    before.push_back(make_pair(k - i, a[i]));
  }
  for (long long i = k; i < n; i++) {
    after.push_back(make_pair(i - k, a[i]));
  }
  auto build = [&](long long ind) {
    vector<pair<long long, long long>> cur = (ind == 0 ? before : after);
    for (long long i = 0; i < N; i++) {
      for (long long j = 0; j < M; j++) {
        dp[ind][i][j] = (ind == 0 ? -INF : INF);
      }
    }
    dp[ind][0][0] = 0;
    for (auto it : cur) {
      long long d, val;
      tie(d, val) = it;
      for (long long i = N - 1; i > 0; i--) {
        for (long long j = d; j < M; j++) {
          if (ind == 0) {
            dp[ind][i][j] = max(dp[ind][i][j], dp[ind][i - 1][j - d] + val);
          } else {
            dp[ind][i][j] = min(dp[ind][i][j], dp[ind][i - 1][j - d] + val);
          }
        }
        for (long long j = 1; j < M; j++) {
          if (ind == 0) {
            dp[ind][i][j] = max(dp[ind][i][j], dp[ind][i][j - 1]);
          } else {
            dp[ind][i][j] = min(dp[ind][i][j], dp[ind][i][j - 1]);
          }
        }
      }
    }
  };
  build(0);
  build(1);
  long long sum = accumulate(a, a + k, 0);
  long long ans = sum;
  for (long long i = 1;
       i <= min((long long)after.size(), (long long)before.size()); i++) {
    long long cur = INF;
    for (long long j = 0; j <= s; j++) {
      long long val = sum - dp[0][i][j] + dp[1][i][s - j];
      cur = min(cur, val);
    }
    ans = min(ans, (long long)cur);
  }
  cout << ans << '\n';
}
