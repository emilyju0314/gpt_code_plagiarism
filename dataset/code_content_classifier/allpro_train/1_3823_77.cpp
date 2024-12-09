#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
long long t, n, a[300005], b[300005], f[300005][3];
inline void out(register long long x) {
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  out(x / 10);
  putchar(x % 10 + '0');
  return;
}
signed main() {
  cin >> t;
  memset(f, 0x7f, sizeof(f));
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) a[i] = read(), b[i] = read();
    f[1][0] = 0, f[1][1] = f[1][2] = b[1];
    for (long long i = 1; i <= n; i++)
      for (long long j = 0; j < 3; j++)
        for (long long k = 0; k < 3; k++) {
          if (a[i] + j == a[i - 1] + k) continue;
          f[i][j] = min(f[i][j], f[i - 1][k] + j * b[i]);
        }
    long long ans = min(min(f[n][0], f[n][1]), f[n][2]);
    out(ans), putchar('\n');
    for (long long i = 1; i <= n; i++) f[i][0] = f[i][1] = f[i][2] = 9e18;
  }
}
