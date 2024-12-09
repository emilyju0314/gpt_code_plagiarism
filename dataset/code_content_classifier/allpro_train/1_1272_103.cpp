#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 22;
const int xm = 2e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const long double eps = 1e-15;
const int mod = 1e9 + 7;
const int base = 257;
int n, k, t, a[xn][xn], last[xn], b[xn], ps[xn][xm], ans, MSK;
long long dp[1 << xn];
string S;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> t >> S;
  for (int i = 0; i < k; ++i) cin >> b[i];
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j) cin >> a[i][j];
  S = '.' + S;
  for (int i = 0; i < k; ++i)
    for (int j = 1; j <= n; ++j) ps[i][j] = ps[i][j - 1] + (S[j] - 'A' == i);
  for (int i = 1; i <= n; ++i) {
    int x = S[i] - 'A';
    MSK |= (1 << x);
    for (int j = 0; j < k; ++j) {
      int y = last[j];
      if (y < last[x] || !y) continue;
      int mask = 0;
      for (int p = 0; p < k; ++p)
        if (ps[p][i - 1] - ps[p][y]) mask += (1 << p);
      dp[mask] += a[j][x];
      dp[mask ^ (1 << x)] -= a[j][x];
      if (x == j) continue;
      dp[mask ^ (1 << j)] -= a[j][x];
      dp[mask ^ (1 << x) ^ (1 << j)] += a[j][x];
    }
    last[x] = i;
  }
  for (int bit = 0; bit < k; ++bit)
    for (int mask = 0; mask < (1 << k); ++mask)
      if ((mask & (1 << bit))) dp[mask] += dp[mask ^ (1 << bit)];
  for (int mask = 0; mask + 1 < (1 << k) && mask < MSK; ++mask) {
    if (MSK < (mask | MSK)) continue;
    for (int bit = 0; bit < k; ++bit)
      if ((mask & (1 << bit))) dp[mask] += b[bit];
    ans += (dp[mask] <= t);
  }
  cout << ans << '\n';
  return 0;
}
