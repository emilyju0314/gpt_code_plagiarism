#include <bits/stdc++.h>
using namespace std;
long long const M = 2e5 + 10, M2 = 1e3 + 10, mod = 1e9 + 7, inf = 1e18 + 10;
long long n, m, a[M], b[M], ans = 0;
void check(long long x) {
  long long t = (x * (x - 1)) / 2;
  t *= n;
  for (long long i = 1; i <= n; i++) {
    long long tmp = (i * x);
    tmp += t;
    b[i] = tmp;
    if (a[i] < b[i]) return;
  }
  long long last = n * x;
  pair<long long, long long> mn = make_pair(inf, inf);
  long long dif = m - last;
  if (dif == 0) {
    long long sum = 0;
    for (long long j = 1; j <= n; j++) sum += b[j];
    ans = max(ans, sum);
    return;
  }
  for (long long i = n; i >= 1; i--) {
    long long f = (a[i] - b[i]) / dif;
    if (mn.first > f) mn.first = f, mn.second = i;
  }
  mn.first = min(mn.first, x);
  for (long long i = 1; i <= n; i++) b[i] += (dif * (mn.first - 1));
  for (long long j = n; j > mn.second; j--) b[j] += dif;
  for (long long j = mn.second; j >= 1; j--) {
    dif = min(dif, a[j] - b[j]);
    b[j] += dif;
  }
  if (mn.first != x)
    for (long long j = n; j >= 1; j--) {
      dif = min(dif, a[j] - b[j]);
      b[j] += dif;
    }
  if (mn.first < (x - 1))
    for (long long j = n; j >= 1; j--) dif = min(dif, a[j] - b[j]), b[j] += dif;
  long long all = 0;
  for (long long j = 1; j <= n; j++) all += b[j];
  ans = max(ans, all);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= m / n; i++) check(i);
  cout << ans;
}
