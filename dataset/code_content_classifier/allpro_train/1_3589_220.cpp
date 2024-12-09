#include <bits/stdc++.h>
using namespace std;
int func(long long n, long long k, long long p1, long long p2) {
  if (n % 3 != 0) return 0;
  long long x2, x3, x1, d1, d2;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 || j == 0) continue;
      d1 = i * p1;
      d2 = j * p2;
      x2 = (k - d1 + d2) / 3;
      if ((k - d1 + d2) % 3 != 0) continue;
      if (x2 >= 0 && x2 <= k) {
        x1 = d1 + x2;
        x3 = x2 - d2;
        if (x3 >= 0 && x3 <= k && x1 >= 0 && x1 <= k) {
          if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3) return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  long long tc;
  scanf("%I64d", &tc);
  while (tc--) {
    long long n, k, d1, d2;
    scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
    if (func(n, k, d1, d2))
      printf("yes\n");
    else
      printf("no\n");
  }
}
