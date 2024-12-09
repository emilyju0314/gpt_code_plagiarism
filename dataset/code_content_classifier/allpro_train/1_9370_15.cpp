#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
long long n, m, p;
struct re {
  long long au;
  long long b[10];
} a[maxn];
long long f[maxn][260];
bool cmp(re a, re b) { return a.au > b.au; }
bool check(long long num, long long k) {
  long long ans = 0;
  for (long long i = k; i; i -= (i & (-i))) ans++;
  if (num - ans <= p)
    return 1;
  else
    return 0;
}
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> p;
  for (long long i = (1); i <= (n); ++i) cin >> a[i].au;
  for (long long i = (1); i <= (n); ++i)
    for (long long j = (0); j <= (m - 1); ++j) cin >> a[i].b[j];
  sort(a + 1, a + 1 + n, cmp);
  long long MAX = (1 << (m)) - 1;
  for (long long i = (0); i <= (n); ++i) {
    for (long long j = (0); j <= (MAX); ++j) f[i][j] = -1e18;
  }
  f[0][0] = 0;
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (0); j <= (MAX); ++j) {
      f[i][j] = max(f[i][j], f[i - 1][j]);
      for (long long k = (0); k <= (m - 1); ++k)
        if (((1 << k) & j)) {
          f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << k)] + a[i].b[k]);
        }
      if (check(i, j)) f[i][j] = max(f[i][j], f[i - 1][j] + a[i].au);
    }
  }
  cout << (f[n][MAX]) << '\n';
}
