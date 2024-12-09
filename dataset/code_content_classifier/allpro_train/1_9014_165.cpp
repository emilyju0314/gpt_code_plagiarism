#include <bits/stdc++.h>
using namespace std;
long long dp[55];
int main() {
  long long j = 1;
  for (int i = 2; i <= 52; i++) {
    dp[i] = j;
    j *= 2;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    if (a == b) {
      printf("1 %lld\n", a);
      continue;
    }
    bool ok = 0;
    for (int i = 2; i <= 50; i++) {
      if (dp[i] * 1.0 * a >= 1e18) break;
      long long val = b - dp[i] * a;
      long long lo = dp[i], hi = m * dp[i];
      if (m * 1.0 * dp[i] >= 1e18) hi = 1e18;
      int k = i;
      if (lo <= val && val <= hi) {
        printf("%d %lld ", i, a);
        long long sum = a;
        for (int j = 2; j <= i - 1; j++) {
          long long low = 1, hii = m, res = 0;
          k--;
          lo = dp[k];
          while (low <= hii) {
            long long mid = (low + hii) / 2;
            long long lost = mid * dp[i - j + 1];
            if (mid * 1.0 * dp[i - j + 1] >= 1e18) lost = 1e18;
            if (lo <= val - lost) {
              res = mid, low = mid + 1;
            } else
              hii = mid - 1;
          }
          long long lost = res * dp[i - j + 1];
          val -= lost;
          printf("%lld ", sum + res);
          sum += sum;
          sum += res;
        }
        printf("%lld\n", b);
        ok = 1;
        break;
      }
    }
    if (!ok) printf("-1\n");
  }
}
