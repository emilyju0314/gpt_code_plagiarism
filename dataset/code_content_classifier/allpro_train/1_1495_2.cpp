#include <bits/stdc++.h>
int cnt = 0;
long long f[200005], g[200005], tmp[200005];
int in[200005], out[200005];
int t[200005], a[200005], vis[200005];
int h[200005], to[400005], ver[400005];
inline bool cmp(int x, int y) { return x > y; }
inline void swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}
inline void add(int x, int y) {
  to[++cnt] = y;
  ver[cnt] = h[x];
  h[x] = cnt;
}
inline int read() {
  register int x = 0, f = 1;
  register char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline void dfs(int x, int fa = 0) {
  vis[x] = 1;
  int num = 0;
  long long cur = 0;
  for (register int i = h[x]; i; i = ver[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);
  }
  for (register int i = h[x]; i; i = ver[i]) {
    int y = to[i];
    if (y == fa) continue;
    tmp[++num] = g[y] - f[y];
    cur += f[y];
  }
  std::sort(tmp + 1, tmp + 1 + num, cmp);
  for (register int i = 0; i <= num; ++i) {
    cur += tmp[i];
    if (fa) {
      f[x] =
          ((f[x]) >
                   (((out[x] + i + 1) < (in[x] + num - i) ? (out[x] + i + 1)
                                                          : (in[x] + num - i)) *
                        (long long)t[x] +
                    cur)
               ? (f[x])
               : (((out[x] + i + 1) < (in[x] + num - i) ? (out[x] + i + 1)
                                                        : (in[x] + num - i)) *
                      (long long)t[x] +
                  cur));
      g[x] = ((g[x]) > (((out[x] + i) < (in[x] + num - i + 1)
                             ? (out[x] + i)
                             : (in[x] + num - i + 1)) *
                            (long long)t[x] +
                        cur)
                  ? (g[x])
                  : (((out[x] + i) < (in[x] + num - i + 1)
                          ? (out[x] + i)
                          : (in[x] + num - i + 1)) *
                         (long long)t[x] +
                     cur));
    } else
      f[x] = ((f[x]) > (((out[x] + i) < (in[x] + num - i) ? (out[x] + i)
                                                          : (in[x] + num - i)) *
                            (long long)t[x] +
                        cur)
                  ? (f[x])
                  : (((out[x] + i) < (in[x] + num - i) ? (out[x] + i)
                                                       : (in[x] + num - i)) *
                         (long long)t[x] +
                     cur));
  }
}
int main() {
  int n = read();
  long long ans = 0;
  for (register int i = 1; i <= n; ++i) t[i] = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  for (register int i = 1; i < n; ++i) {
    int x = read(), y = read();
    ans += t[x] + t[y];
    if (a[x] == a[y]) {
      add(x, y);
      add(y, x);
    } else {
      if (a[x] > a[y]) swap(x, y);
      ++in[x];
      ++out[y];
    }
  }
  for (register int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
      ans -= f[i];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
