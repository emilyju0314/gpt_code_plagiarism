#include <bits/stdc++.h>
using namespace std;
long long int cmb(long long int n, long long int r) {
  if (n < r) {
    return 0;
  }
  long long int i, pdt = 1;
  r = max(r, n - r);
  for (i = 1; i <= n - r; i++) {
    pdt *= (r + i);
    pdt /= i;
  }
  return pdt;
}
void solve() {
  long long int n, i, m, mx = INT_MIN, mn = INT_MAX, k, c = 0, j, d = 0, t = 0,
                         sm = 0, pdt = 1;
  cin >> n;
  long long int ss;
  long long int z;
  cin >> ss;
  vector<long long int> ar;
  k = n;
  while (k > 0) {
    t++;
    k /= 10;
  }
  vector<long long int> dp(t, 0);
  for (i = 1; i <= t - 1; i++) {
    d = (pow(10, t - i) - 1);
    dp[i] = ss / d;
    z = 9;
    dp[i] = min(z, dp[i]);
    ss -= dp[i] * d;
  }
  if (ss < 0) {
    ss = 0;
  }
  for (i = t - 1; i > 0; i--) {
    if (ss == 0) {
      break;
    }
    d = pow(10, t - i) - 1;
    c = (ss / d) + 1;
    z = 9 - dp[i];
    c = min(z, c);
    if (c > 0) {
      for (j = i + 1; j <= t - 1; j++) {
        dp[j] = 0;
      }
    }
    dp[i] += c;
    ss -= c * d;
    if (ss < 0) {
      ss = 0;
    }
  }
  if (ss > 0) {
    dp[0] = 1;
  }
  for (i = 0; i <= t - 1; i++) {
    sm = sm * 10;
    sm += dp[i];
  }
  sm *= 10;
  if (n - sm + 1 < 0) {
    cout << 0 << endl;
    return;
  }
  cout << n - sm + 1 << endl;
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
