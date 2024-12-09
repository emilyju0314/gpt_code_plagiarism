#include <bits/stdc++.h>
using namespace std;
long long dig(long long x) {
  long long k = 0;
  while (x > 0) x /= 10, k++;
  return k;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, w, m, k, l, r, ans = 0;
  cin >> w >> m >> k;
  for (i = 1; w > 0; i *= 10) {
    if (i < m) continue;
    n = dig(m);
    r = min((i - m), (w / (k * n)));
    w -= (r * n * k);
    ans += r;
    m = i;
    if (w < n * k) break;
  }
  cout << ans << "\n";
  return 0;
}
