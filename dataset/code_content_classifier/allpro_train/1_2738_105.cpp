#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long mpow(long long a, long long b) {
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long dp[65][35][1850];
long long p[65];
long long win[65];
bool cmp(long long x, long long y) { return win[x] < win[y]; }
void solve() {
  long long m;
  cin >> m;
  long long a[m + 1];
  for (long long i = 0; i < m; i++) {
    cin >> a[i + 1];
  }
  sort(a + 1, a + m + 1);
  for (long long i = 0; i < 65; i++) {
    for (long long j = 0; j < 35; j++) {
      for (long long k = 0; k < 1850; k++) dp[i][j][k] = -1;
    }
  }
  dp[0][0][0] = 1;
  for (long long i = 1; i < 62; i++) {
    for (long long j = 1; j < m + 1; j++) {
      for (long long k = (i * (i - 1)) / 2; k < 1850; k++) {
        if (k - a[j] < ((i - 2) * (i - 1)) / 2) continue;
        if (dp[i - 1][j - 1][k - a[j]] != -1) {
          dp[i][j][k] = j - 1;
        } else if (dp[i - 1][j][k - a[j]] != -1) {
          dp[i][j][k] = j;
        }
      }
    }
  }
  long long n = -1;
  for (long long i = m; i < 62; i++) {
    if (dp[i][m][(i * (i - 1)) / 2] != -1) {
      n = i;
      break;
    }
  }
  if (n == -1) {
    cout << "=("
         << "\n";
    return;
  }
  long long tot = (n * (n - 1)) / 2;
  long long j = m;
  for (long long i = n; i >= 1; i--) {
    long long in = dp[i][j][tot];
    win[i] = a[j];
    tot -= a[j];
    j = in;
  }
  long long ans[n + 1][n + 1];
  for (long long i = 0; i < n + 1; i++) ans[i][i] = 0;
  for (long long i = 1; i < n + 1; i++) p[i] = i;
  for (long long i = 1; i < n + 1; i++) {
    sort(p + i, p + n + 1, cmp);
    long long temp = win[p[i]];
    for (long long j = i + 1; j < n + 1; j++) {
      if (temp) {
        ans[p[j]][p[i]] = 0;
        ans[p[i]][p[j]] = 1;
        temp--;
      } else {
        ans[p[j]][p[i]] = 1;
        ans[p[i]][p[j]] = 0;
        win[p[j]]--;
      }
    }
  }
  cout << n << "\n";
  for (long long i = 1; i < n + 1; i++) {
    long long coun = 0;
    for (long long j = 1; j < n + 1; j++) {
      if (ans[i][j] == 1) coun++;
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
