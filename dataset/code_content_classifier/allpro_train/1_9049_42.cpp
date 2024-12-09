#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];
int dp[2][1000005];
int sum[2][1000005];
long long n, l, k;
int bs(int x) {
  int l = 0, r = n;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    if (b[mid] <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> l >> k) {
    for (int i = (0); i <= (n - 1); i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    long long num = l / n + 1;
    long long ret = l % n;
    k = min(num, k);
    for (int i = (0); i <= (n); i++) sum[0][i] = 1;
    long long ans = 0;
    for (int i = (1); i <= (k); i++) {
      int f = i & 1;
      for (int j = (0); j <= (n - 1); j++) {
        sum[f][j] = dp[f][j] = 0;
      }
      for (int j = (0); j <= (n - 1); j++) {
        int p = bs(a[j]);
        dp[f][j] = sum[1 - f][p];
        sum[f][p] = (sum[f][p] + dp[f][j]) % 1000000007;
        if (j >= ret)
          ans = (ans + (num - i) % 1000000007 * dp[f][j] % 1000000007) %
                1000000007;
        else
          ans = (ans + (num - i + 1) % 1000000007 * dp[f][j] % 1000000007) %
                1000000007;
      }
      for (int j = (1); j <= (n - 1); j++)
        sum[f][j] = (sum[f][j] + sum[f][j - 1]) % 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
