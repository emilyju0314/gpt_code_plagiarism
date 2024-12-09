#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5, mo = 998244353;
long long n, ans, l[N], r[N], x[N], y[N], frac[N];
char c[N];
inline long long fast(long long a, long long b, long long mo) {
  register long long sum = 1;
  while (b) {
    if (b & 1) sum = sum * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return sum;
}
inline long long C(long long x, long long y) {
  if (x < 0 || y < 0 || x < y) return 0;
  return frac[x] * fast(frac[y], mo - 2, mo) % mo *
         fast(frac[x - y], mo - 2, mo) % mo;
}
signed main() {
  scanf("%s", c + 1), n = strlen(c + 1);
  frac[0] = 1;
  for (register long long i = 1; i <= N - 1; ++i)
    frac[i] = frac[i - 1] * i % mo;
  for (register long long i = 1; i <= n; ++i)
    l[i] = l[i - 1] + (c[i] == '('), x[i] = x[i - 1] + (c[i] == '?');
  for (register long long i = n; i >= 1; --i)
    r[i] = r[i + 1] + (c[i] == ')'), y[i] = y[i + 1] + (c[i] == '?');
  for (register long long i = 1; i <= n; ++i)
    ans += l[i] * C(x[i] + y[i + 1], y[i + 1] + r[i + 1] - l[i]) % mo +
           x[i] * C(x[i] + y[i + 1] - 1, y[i + 1] - l[i] + r[i + 1] - 1) % mo;
  return printf("%d\n", ans % mo), 0;
}
