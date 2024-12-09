#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
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
const long long N = 3e5 + 5;
long long w[N], f[N][20][2][2], fx[2], fy[2], d[N], lg, n, h[N], en, fa[N][20];
struct edge {
  long long n, v, w1, w2;
} e[N << 1];
void add(long long x, long long y, long long a, long long b) {
  e[++en] = (edge){h[x], y, a, b};
  h[x] = en;
}
void dfs1(long long x, long long fa) {
  ::fa[x][0] = fa;
  d[x] = d[fa] + 1;
  for (long long i = h[x]; i; i = e[i].n) {
    long long y = e[i].v, w1 = e[i].w1, w2 = e[i].w2;
    if (y == fa) continue;
    dfs1(y, x);
    w[x] = min(w[x], w[y] + w1 + w2);
  }
}
void dfs2(long long x, long long fa) {
  for (long long i = h[x]; i; i = e[i].n) {
    long long y = e[i].v, w1 = e[i].w1, w2 = e[i].w2;
    if (y == fa) continue;
    w[y] = min(w[y], w[x] + w1 + w2);
    dfs2(y, x);
  }
}
void dfs(long long x, long long fa) {
  for (long long i = h[x]; i; i = e[i].n) {
    long long y = e[i].v, w1 = e[i].w1, w2 = e[i].w2;
    if (y == fa) continue;
    dfs(y, x);
    f[y][0][0][0] = min(w1, w[y] + w2 + w[x]);
    f[y][0][0][1] = min(w[y] + w2, w1 + w[x]);
    f[y][0][1][0] = min(w[y] + w1, w2 + w[x]);
    f[y][0][1][1] = min(w2, w[x] + w1 + w[y]);
  }
}
long long lca(long long x, long long y) {
  if (d[x] < d[y]) swap(x, y);
  for (long long i = lg; ~i; i--)
    if (d[y] <= d[fa[x][i]]) x = fa[x][i];
  if (x == y) return x;
  for (long long i = lg; ~i; i--)
    if (fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
void doit() {
  long long x, y, opx, opy, lca;
  opx = read(x) + 1 & 1;
  opy = read(y) + 1 & 1;
  x = x + 1 >> 1, y = y + 1 >> 1;
  lca = ::lca(x, y);
  fx[opx] = fy[opy] = 0;
  fx[!opx] = w[x];
  fy[!opy] = w[y];
  for (long long i = lg; ~i; i--)
    if (d[fa[x][i]] >= d[lca]) {
      long long w0 = fx[0], w1 = fx[1];
      fx[0] = min(w0 + f[x][i][0][0], w1 + f[x][i][1][0]);
      fx[1] = min(w0 + f[x][i][0][1], w1 + f[x][i][1][1]);
      x = fa[x][i];
    }
  for (long long i = lg; ~i; i--)
    if (d[fa[y][i]] >= d[lca]) {
      long long w0 = fy[0], w1 = fy[1];
      fy[0] = min(w0 + f[y][i][0][0], w1 + f[y][i][1][0]);
      fy[1] = min(w0 + f[y][i][0][1], w1 + f[y][i][1][1]);
      y = fa[y][i];
    }
  write(min(fx[0] + fy[0], fx[1] + fy[1]));
  puts("");
}
signed main() {
  memset(f, 31, sizeof f);
  lg = log2(read(n));
  for (long long i = 1; i <= n; i++) read(w[i]);
  for (long long i = 1, x, y, a, b; i < n; i++)
    read(x, y, a, b), add(x, y, a, b), add(y, x, a, b);
  dfs1(1, 0);
  dfs2(1, 0);
  dfs(1, 0);
  for (long long i = 1; i <= lg; i++)
    for (long long x = 1; x <= n; x++) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
      f[x][i][0][0] = min(f[x][i - 1][0][0] + f[fa[x][i - 1]][i - 1][0][0],
                          f[x][i - 1][0][1] + f[fa[x][i - 1]][i - 1][1][0]);
      f[x][i][0][1] = min(f[x][i - 1][0][0] + f[fa[x][i - 1]][i - 1][0][1],
                          f[x][i - 1][0][1] + f[fa[x][i - 1]][i - 1][1][1]);
      f[x][i][1][0] = min(f[x][i - 1][1][0] + f[fa[x][i - 1]][i - 1][0][0],
                          f[x][i - 1][1][1] + f[fa[x][i - 1]][i - 1][1][0]);
      f[x][i][1][1] = min(f[x][i - 1][1][0] + f[fa[x][i - 1]][i - 1][0][1],
                          f[x][i - 1][1][1] + f[fa[x][i - 1]][i - 1][1][1]);
    }
  long long t;
  read(t);
  while (t--) doit();
}
