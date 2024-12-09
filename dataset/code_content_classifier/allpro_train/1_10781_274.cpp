#include <bits/stdc++.h>
using namespace std;
long long n, inf = 1e18, dp[105][105][2], ans;
struct l1 {
  long long x, l;
} s[105];
long long cmp(l1 a, l1 b) { return a.x < b.x; }
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &s[i].x, &s[i].l);
  }
  sort(s + 1, s + n + 1, cmp);
  s[0].x = -inf;
  for (long long i = 0; i <= n; i++) {
    for (long long t = 0; t <= i; t++) {
      for (long long p = 0; p <= 1; p++) {
        ans = max(ans, dp[i][t][p]);
        if (i == n) continue;
        long long mx, id = t, ps = p;
        if (p == 0)
          mx = s[id].x;
        else
          mx = s[id].x + s[id].l;
        for (long long k = i + 1; k <= n; k++) {
          for (long long nep = 0; nep <= 1; nep++) {
            long long sit = 0;
            if (!nep)
              sit = s[k].x;
            else
              sit = s[k].x + s[k].l;
            if (sit > mx) mx = sit, id = k, ps = nep;
            dp[k][id][ps] =
                max(dp[k][id][ps], dp[i][t][p] +
                                       min(s[k].l, sit - s[t].x - p * s[t].l) +
                                       mx - sit);
          }
        }
      }
    }
  }
  printf("%lld", ans);
}
