#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, K = N * 4;
int n, a[N], cnt[K], w[N], k;
long long solve(int l, int r) {
  if (l >= r) return 0ll;
  int mid = l + r >> 1, p = mid, mx = 0;
  long long si = 0, sj = 0, ans = solve(l, mid) + solve(mid + 1, r);
  int len = 0;
  for (register int i = (mid + 1); i <= (r); ++i) {
    mx = max(mx, a[i]);
    si += a[i];
    while (l <= p && a[p] < mx)
      sj += a[p], cnt[sj % k]++, w[++len] = sj % k, p--;
    ans += cnt[((mx - si) % k + k) % k];
  }
  for (register int i = (1); i <= (len); ++i) cnt[w[i]]--;
  len = 0;
  p = mid + 1;
  si = sj = mx = 0;
  for (register int i = (mid); i >= (l); --i) {
    mx = max(mx, a[i]);
    si += a[i];
    while (p <= r && a[p] <= mx)
      sj += a[p], cnt[sj % k]++, w[++len] = sj % k, p++;
    ans += cnt[((mx - si) % k + k) % k];
  }
  for (register int i = (1); i <= (len); ++i) cnt[w[i]]--;
  return ans;
}
signed main() {
  scanf("%d %d", &n, &k);
  for (register int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  printf("%lld\n", solve(1, n));
  return 0;
}
