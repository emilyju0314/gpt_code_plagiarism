#include <bits/stdc++.h>
const int M = 2005;
const int MOD = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long T, n, ans, pre[M][M << 1], suf[M][M << 1];
char s[M], t[M];
void add(long long &x, long long y) { x = (x + y) % MOD; }
long long Abs(long long x) { return x > 0 ? x : -x; }
long long match(char c, long long x) { return c == '?' || c == x + '0'; }
void work() {
  n = read();
  scanf("%s%s", s + 1, t + 1);
  for (long long i = 1; i <= n; i++) {
    if (s[i] != '?' && i % 2) s[i] = ((s[i] - '0') ^ 1) + '0';
    if (t[i] != '?' && i % 2) t[i] = ((t[i] - '0') ^ 1) + '0';
  }
  for (long long i = 0; i <= n + 1; i++)
    for (long long j = -n; j <= n; j++) pre[i][j + M] = suf[i][j + M] = 0;
  pre[0][0 + M] = suf[n + 1][0 + M] = 1;
  ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = -n; j <= n; j++)
      for (long long x = 0; x < 2; x++)
        for (long long y = 0; y < 2; y++)
          if (match(s[i], x) && match(t[i], y))
            add(pre[i][j + x - y + M], pre[i - 1][j + M]);
  for (long long i = n; i >= 1; i--)
    for (long long j = -n; j <= n; j++)
      for (long long x = 0; x < 2; x++)
        for (long long y = 0; y < 2; y++)
          if (match(s[i], x) && match(t[i], y))
            add(suf[i][j + x - y + M], suf[i + 1][j + M]);
  for (long long i = 1; i <= n; i++)
    for (long long j = -n; j <= n; j++)
      add(ans, pre[i][j + M] * suf[i + 1][-j + M] % MOD * Abs(j));
  printf("%d\n", ans);
}
signed main() {
  T = read();
  while (T--) work();
}
