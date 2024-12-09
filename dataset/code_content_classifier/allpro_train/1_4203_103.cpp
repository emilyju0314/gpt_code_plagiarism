#include <bits/stdc++.h>
using namespace std;
int n, m, inv[1000000 + 2], ans = 0, f[1000000 + 3];
void read(int &x) {
  char ch;
  bool ok;
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
int fp(int x, int y) {
  int ansi = 1;
  while (y) {
    if (y % 2) ansi = 1ll * ansi * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    y /= 2;
  }
  return ansi;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m + 2; ++i) f[i] = (f[i - 1] + fp(i, m)) % 1000000007;
  if (n <= m + 2) {
    printf("%d\n", f[n]);
    return 0;
  }
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= m + 1; ++i)
    inv[i] =
        1ll * (1000000007 - 1000000007 / i) * inv[1000000007 % i] % 1000000007;
  for (int i = 2; i <= m + 1; ++i)
    inv[i] = 1ll * inv[i - 1] * inv[i] % 1000000007;
  for (int i = 1; i <= m + 2; ++i)
    ans = (ans +
           1ll * f[i] * fp(n - i, 1000000007 - 2) % 1000000007 * inv[i - 1] %
               1000000007 * fp(-1, m + 2 - i) % 1000000007 * inv[m + 2 - i] %
               1000000007 +
           1000000007) %
          1000000007;
  for (int i = 1; i <= m + 2; ++i)
    ans = 1ll * (n - i) % 1000000007 * ans % 1000000007;
  printf("%d\n", ans);
  return 0;
}
