#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, x, maxx, ma = 0, ans = 0;
    scanf("%lld", &n);
    scanf("%lld", &x);
    maxx = x;
    for (long long i = 1; i < n; i++) {
      scanf("%lld", &x);
      if (x > maxx) maxx = x;
      if ((maxx - x) > ma) ma = maxx - x;
    }
    while (ma) {
      ma >>= 1;
      ans++;
    }
    printf("%lld\n", ans);
  }
}
