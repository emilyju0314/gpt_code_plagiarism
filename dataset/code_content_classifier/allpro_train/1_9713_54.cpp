#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long z = 1000000000;
const long long N = 1e5 + 1;
const long long INF = 1e18;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
long long powe(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long t = powe(x, y / 2);
  t = (t * t) % mod;
  if (y % 2 == 1) t = (t * x) % mod;
  return t;
}
long long n, m, k, t;
vector<long long> a, dp;
vector<string> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp.resize(n);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    dp[i] = a[i] - k;
    long long sum = a[i];
    if (i > 0) {
      for (long long j = i - 1; j >= 0 && i - j <= m; j--) {
        dp[i] = max(dp[i], dp[j] + sum - k);
        sum += a[j];
      }
    }
    if (i < m) {
      dp[i] = max(dp[i], sum - k);
    }
    dp[i] = max(dp[i], 0ll);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
