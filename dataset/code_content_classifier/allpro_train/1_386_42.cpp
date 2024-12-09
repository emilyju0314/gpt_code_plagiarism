#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e16;
long long n, a[100100], d[400100], Ans;
inline void update(long long le, long long ri, long long wh, long long pl,
                   long long k) {
  if (le == ri) {
    d[wh] = k;
    return;
  }
  long long mid = (le + ri) >> 1;
  if (mid >= pl)
    update(le, mid, wh << 1, pl, k);
  else
    update(mid + 1, ri, wh << 1 | 1, pl, k);
  d[wh] = min(d[wh << 1], d[wh << 1 | 1]);
}
inline long long q(long long le, long long ri, long long wh, long long x,
                   long long y) {
  if (le >= x && ri <= y) return d[wh];
  long long mid = (le + ri) >> 1, ans = inf;
  if (mid >= x) ans = min(ans, q(le, mid, wh << 1, x, y));
  if (mid < y) ans = min(ans, q(mid + 1, ri, wh << 1 | 1, x, y));
  return ans;
}
signed main() {
  long long i, j, k;
  scanf("%lld", &n);
  for (i = 1; i < n; i++) scanf("%lld", &a[i]);
  for (i = 0; i <= 4 * n; i++) d[i] = inf;
  update(1, n, 1, n, n);
  for (i = n - 1; i > 0; i--) {
    long long wh = q(1, n, 1, i + 1, a[i]) + n - i - a[i];
    Ans += wh;
    update(1, n, 1, i, wh + i);
  }
  cout << Ans << "\n";
  return 0;
}
