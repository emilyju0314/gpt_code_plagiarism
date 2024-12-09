#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, k;
  scanf("%I64d%I64d%I64d%I64d", &n, &l, &r, &k);
  r -= l - 1;
  if (r <= 0) r += n;
  l = 1;
  int lim = (int)sqrt(k);
  if (n <= lim) {
    long long ans = n, k1, L, R;
    while (ans >= 0) {
      k1 = k % (ans + n);
      if (r == n) k1 = min(k, n + ans);
      L = ans >= (k1 + 1) / 2 ? (k1 + 1) / 2 : k1 - ans;
      R = n - ans >= k1 ? k1 : (k1 - (n - ans) + 1) / 2 + (n - ans);
      if (L <= r && r <= R)
        break;
      else
        ans--;
    }
    if (ans < 0)
      puts("-1");
    else
      printf("%I64d\n", ans);
  } else {
    long long m = k / n, ans = -1, L1, L2, R1, R2;
    if (r <= k && k <= r * 2)
      ans = max(ans, k == r * 2 ? n : (n - r) + (k - r + 1));
    for (int i = 1; i <= m; i++) {
      L1 = (k - r * 2 + i - 1) / i - n;
      R1 = (k - r) / i - n;
      L2 = (k + n - r + i) / (i + 1) - n;
      R2 = (k + (n - r) * 2 + 1) / (i + 1) - n;
      if (max(L1, L2) <= min(R1, R2)) ans = max(ans, min(R1, R2));
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
