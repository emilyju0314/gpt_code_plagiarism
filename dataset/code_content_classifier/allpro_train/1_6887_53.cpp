#include <bits/stdc++.h>
using namespace std;
typedef const long long& cll;
typedef const int& ci;
long long c0, c1, n;
long long gcd(cll a, cll b) { return b ? gcd(b, a % b) : a; }
long long lls[31];
long long comb(cll a, ci b) {
  long long s = 1, x, g;
  for (int i = 0; ++i <= b; lls[i] = i)
    ;
  for (int i = -1; ++i < b;) {
    x = a + b - i;
    for (long long j = 0; ++j <= b;) {
      g = gcd(lls[j], x);
      x /= g;
      lls[j] /= g;
    }
    if (x > 2147483647 / s) return 2147483647;
    s *= x;
  }
  return s;
}
bool check(cll x) {
  long long tmp = x / c0 + x / c1 + 1;
  if (tmp > n) return 1;
  for (int i = 0; ++i <= 26;) {
    for (long long j = i - 1; (++j) * c0 + i * c1 <= x;)
      if ((tmp += comb(j, i)) > n) return 1;
    for (long long j = i; (++j) * c1 + i * c0 <= x;)
      if ((tmp += comb(j, i)) > n) return 1;
  }
  return 0;
}
void work(cll x, long long& tmp, long long& ans) {
  tmp = x / c0 + x / c1 + 1;
  ans = ((x / c0) * (x / c0 + 1) * c0 + (x / c1) * (x / c1 + 1) * c1) >> 1;
  long long c;
  for (int i = 0; ++i <= 26;) {
    for (long long j = i - 1; (++j) * c0 + i * c1 <= x;
         ans += c * (j * c0 + i * c1))
      tmp += (c = comb(j, i));
    for (long long j = i; (++j) * c1 + i * c0 <= x;
         ans += c * (j * c1 + i * c0))
      tmp += (c = comb(j, i));
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &c0, &c1);
  --n, c0 > c1 && (swap(c0, c1), 1);
  if (!c0) {
    printf("%lld\n", n * c1);
    return 0;
  }
  long long l = 0, r = c1 * 26, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  long long c, s;
  work(l - 1, c, s);
  s += (n - c) * l + n * (c0 + c1);
  printf("%lld\n", s);
  return 0;
}
