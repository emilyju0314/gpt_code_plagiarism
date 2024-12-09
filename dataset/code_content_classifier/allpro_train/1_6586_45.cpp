#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const int N(20), M(1 << 16);
int n, m, a[N], ans[N];
long long Y, f[M];
int main() {
  n = read(), scanf("%lld", &Y), Y -= 2000, m = read();
  for (int i = 1, a, b; i <= m; i++)
    a = read() - 1, b = read() - 1, ::a[b] |= (1 << a);
  for (int i = 0; i < n; i++) ans[i] = -1;
  long long q = 0;
  for (int p = 0; p < n; p++)
    for (ans[p] = 0;; ++ans[p]) {
      if (ans[p] >= n) return puts("The times have changed"), 0;
      int fl = 1;
      for (int i = 0; i < p; i++)
        if (ans[p] == ans[i]) {
          fl = 0;
          break;
        }
      if (!fl) continue;
      std::memset(f, 0, sizeof f), f[0] = 1;
      for (int i = 0; i < (1 << n) - 1; i++)
        if (f[i])
          for (int j = 0, c = __builtin_popcount(i); j < n; j++)
            if ((!(i >> j & 1)) && (ans[j] == -1 || ans[j] == c) &&
                ((a[j] & i) == a[j]))
              f[i | (1 << j)] += f[i];
      if (q + f[(1 << n) - 1] >= Y) break;
      q += f[(1 << n) - 1];
    }
  for (int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
  return 0;
}
