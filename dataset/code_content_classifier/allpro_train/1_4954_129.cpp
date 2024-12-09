#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
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
const int N = 2005;
long long f[N], ans, x;
int l[N], r[N], a[N], n, k;
void GG() {
  write(-1);
  exit(0);
}
signed main() {
  read(n, k);
  for (int i = 1; i <= n; i++) read(l[i], r[i], a[i]);
  for (int i = n; i; i--) {
    x = a[i];
    if (r[i] == l[i + 1]) x += f[i + 1];
    f[i] = max(0ll, x - 1ll * (r[i] - l[i]) * k);
    if (f[i] > k) GG();
  }
  x = k;
  for (int i = 1; i <= n; i++) {
    if (x < f[i]) ans += x, x = k;
    ans += a[i];
    x = (x + k - a[i] % k) % k;
  }
  write(ans);
}
