#include <bits/stdc++.h>
using namespace std;
long long a, b, ans;
int main() {
  scanf("%lld%lld", &a, &b);
  for (long long i = 1; i <= a + b;) {
    long long n = (a + b) / i, hi = (a + b) / n;
    if (n > a || n > b) {
      i = (a + b) / n + 1;
      continue;
    }
    long long l = ceil(double(a) / (n + 1)), r = a / n;
    long long L = ceil(double(b) / (n + 1)), R = b / n;
    if (l <= r && L <= R) ans += max(0LL, min(hi, r + R) - max(i, l + L) + 1);
    i = hi + 1;
  }
  printf("%lld", ans);
}
