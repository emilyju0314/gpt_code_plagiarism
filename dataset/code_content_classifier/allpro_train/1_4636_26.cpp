#include <bits/stdc++.h>
using namespace std;
double a[21], dp[(1 << 21)];
int calcBits(int x) {
  int res = 0;
  while (x > 0) {
    res += x & 1;
    x >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 1e-3) cnt++;
  }
  k = min(k, cnt);
  dp[0] = 1;
  for (int mask = 1; mask < (1 << n); mask++) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) sum += a[i];
    }
    for (int i = 0; i < n; i++) {
      if (((1 << i) & mask) != 0)
        dp[mask] += dp[mask ^ (1 << i)] * a[i] / (sum + a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    double ans = 1;
    for (int mask = 0; mask < (1 << n); mask++)
      if (calcBits(mask) == k && !(mask & (1 << i))) ans -= dp[mask];
    cout << fixed << setprecision(15) << ans << " ";
  }
  return 0;
}
