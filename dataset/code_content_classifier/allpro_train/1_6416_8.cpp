#include <bits/stdc++.h>
using namespace std;
int t1, n, i, j, a[500010], v[500010], mp[500010], ans, m, hh;
int main() {
  scanf("%d", &t1);
  while (t1--) {
    hh++;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      v[a[i]] = 1;
    }
    m = 0;
    ans = 0;
    sort(a + 1, a + n + 1);
    for (i = n; i; i--) {
      if (mp[a[i]] != hh) {
        m++;
        ans += a[i];
        if (m == 3) break;
        for (j = 1; j * j <= a[i]; j++)
          if (a[i] % j == 0) {
            mp[j] = mp[a[i] / j] = hh;
          }
      }
    }
    if (a[n] % 30 == 0 && v[a[n] / 2] && v[a[n] / 3] && v[a[n] / 5])
      ans = max(ans, a[n] / 2 + a[n] / 3 + a[n] / 5);
    printf("%d\n", ans);
    for (i = 1; i <= n; i++) v[a[i]] = 0;
  }
}
