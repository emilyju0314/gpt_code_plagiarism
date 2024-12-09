#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10000, OO = 1e9 + 100, M = 998244353, P = 6151,
                SQ = 120, lg = 22;
long long tv[N << 2], tvr[N << 2], sum[N << 2], sumr[N << 2], n, a[N << 2];
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long cnt = pw(x, y / 2);
  cnt = (cnt * cnt) % M;
  if (y % 2 == 1) cnt = (cnt * x) % M;
  return cnt;
}
void upd(long long c, long long b, long long e, long long l) {
  if (l < b || e <= l) return;
  if (e - b == 1) {
    sum[c] = (sum[c] + tv[l]) % M;
    sumr[c] = (sumr[c] + tv[n - l - 1]) % M;
    return;
  }
  long long mid = (b + e) >> 1;
  upd(c << 1, b, mid, l);
  upd(c << 1 | 1, mid, e, l);
  sum[c] = sum[c << 1] + sum[c << 1 | 1];
  sumr[c] = sumr[c << 1] + sumr[c << 1 | 1];
}
long long query(long long c, long long b, long long e, long long l, long long r,
                bool t) {
  if (r <= b || e <= l) return 0;
  if (l <= b && e <= r) {
    if (t == true)
      return sum[c];
    else
      return sumr[c];
  }
  long long mid = (b + e) >> 1;
  return (query(c << 1, b, mid, l, r, t) + query(c << 1 | 1, mid, e, l, r, t)) %
         M;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  tv[0] = 1;
  for (long long i = 1; i <= n; i++) tv[i] = (tv[i - 1] * P) % M;
  tvr[n] = pw(tv[n], M - 2);
  for (long long i = n - 1; i >= 0; i--) tvr[i] = (tvr[i + 1] * P) % M;
  for (long long i = 0; i < n; i++) upd(1, 0, n, i);
  for (long long i = 1; i < n; i++) {
    upd(1, 0, n, a[i - 1]);
    long long mn = min(a[i], n - a[i] - 1);
    long long a1 = query(1, 0, n, a[i] - mn, a[i], true),
              a2 = query(1, 0, n, a[i] + 1, a[i] + mn + 1, false);
    a1 = (a1 * tvr[a[i] - mn]) % M;
    long long fn = n - a[i] - 2;
    a2 = (a2 * tvr[fn - mn + 1]) % M;
    if (a1 != a2) return cout << "YES", 0;
  }
  cout << "NO" << endl;
  return 0;
}
