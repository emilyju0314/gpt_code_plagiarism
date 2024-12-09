#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j, k, x[102], y[102], l, m, ans;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
  }
  ans = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      m = x[i] * y[i] + x[j] * y[j];
      k = x[i] + x[j];
      l = max(y[i], y[j]);
      if (max(k, l) <= max(a, b) && min(k, l) <= min(a, b)) {
        ans = max(ans, m);
        continue;
      }
      k = max(x[i], x[j]);
      l = (y[i] + y[j]);
      if (max(k, l) <= max(a, b) && min(k, l) <= min(a, b)) {
        ans = max(ans, m);
        continue;
      }
      k = max(x[i], y[j]);
      l = (y[i] + x[j]);
      if (max(k, l) <= max(a, b) && min(k, l) <= min(a, b)) {
        ans = max(ans, m);
        continue;
      }
      k = max(y[i], x[j]);
      l = (x[i] + y[j]);
      if (max(k, l) <= max(a, b) && min(k, l) <= min(a, b)) {
        ans = max(ans, m);
        continue;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
