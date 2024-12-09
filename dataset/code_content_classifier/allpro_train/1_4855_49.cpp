#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
long long m, a, b;
long long cal(long long x, long long a) {
  if (x < 0) return 0;
  long long ret = x / a;
  ret = (ret + 1) * (ret) / 2 * a;
  ret += (x / a + 1) * (x % a + 1);
  return ret;
}
int main() {
  int cases = 1;
  for (int iii = 1; iii <= cases; ++iii) {
    scanf("%lld%lld%lld", &m, &a, &b);
    long long ans = 0;
    long long x = a, y = a;
    while (x) {
      while (x < b) {
        x += a;
        if (x > y) y = x;
      }
      while (x >= b) {
        x -= b;
        if (!x) break;
        if (x < a) {
          if (m >= y - 1) ans += cal(m - x, a) - cal(y - x - 1, a);
        }
      }
    }
    ans += cal(m, a);
    printf("%lld\n", ans);
  }
}
