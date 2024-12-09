#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
long long fib[90], n;
pair<long long, long long> dp(long long p, long long n, long long d) {
  if (n <= 0) return {0, 0};
  if (n == 1) return {p == 2, p == 1};
  long long mid = fib[n - 1];
  if (p <= mid) {
    auto [x, y] = dp(p, n - 1, 2);
    return {x, min({x + d, x + 1 + (n - 1) / 2, y + 1 + (n - 1) / 2})};
  } else {
    auto [x, y] = dp(p - mid, n - 2, d + 1);
    return {min(x + 1, y + d), y};
  }
}
long long calc(long long x, long long y, long long n, long long d) {
  if (x == 1 && y == fib[n]) return min(d, n + 1 >> 1);
  long long mid = fib[n - 1];
  if (y <= mid) return calc(x, y, n - 1, 2);
  if (x > mid) return calc(x - mid, y - mid, n - 2, d + 1);
  auto [lx, ly] = dp(x, n - 1, 2);
  auto [rx, ry] = dp(y - mid, n - 2, d + 1);
  return min({lx + rx + 1, lx + ry + d, ly + rx + 1});
}
void doit() {
  long long x, y;
  read(x);
  read(y);
  if (x > y) swap(x, y);
  write(calc(x, y, n, n + 1 >> 1));
  puts("");
}
signed main() {
  long long t;
  read(t);
  read(n);
  n = min(n, 80ll);
  fib[0] = 1;
  fib[1] = 2;
  for (long long i = 2; i <= n; i++) fib[i] = fib[i - 2] + fib[i - 1];
  while (t--) doit();
}
