#include <bits/stdc++.h>
using namespace std;
long long d, k, a, b, t;
int main() {
  while (scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t) == 5) {
    long long tmp = k * a - k * b + t;
    if (d <= k) {
      printf("%I64d\n", d * a);
      continue;
    }
    if (tmp > 0) {
      long long cnt = (d * b - t) / tmp;
      if ((d * b - t) % tmp >= 0)
        cnt = 1;
      else
        cnt = abs(cnt) + 1;
      printf("%I64d\n", tmp * cnt + d * b - t);
    } else if (tmp < 0) {
      long long cnt = d / k;
      long long ans = tmp * cnt + d * b - t;
      if (d % k) {
        ans = min(ans, (k * a + t) * cnt + (d % k) * a);
      }
      printf("%I64d\n", ans);
    } else {
      long long cnt = d / k;
      long long ans = min(tmp * cnt + d * b - t, d * b);
      if (d % k) {
        ans = min(ans, (k * a + t) * cnt + (d % k) * a);
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
