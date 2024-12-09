#include <bits/stdc++.h>
using namespace std;
int a[102];
int main() {
  int n, m, k, i, ans = 1e9;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = m - 1; i > 0; i--) {
    if (a[i] != 0 && a[i] <= k && ans > (m - i) * 10) ans = (m - i) * 10;
  }
  for (i = m + 1; i <= n; i++) {
    if (a[i] != 0 && a[i] <= k && ans > (i - m) * 10) ans = (i - m) * 10;
  }
  printf("%d", ans);
}
