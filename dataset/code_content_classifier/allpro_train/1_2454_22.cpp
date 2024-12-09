#include <bits/stdc++.h>
template <typename T>
inline void ckmax(T& x, T y) {
  x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
  x = (y < x ? y : x);
}
using namespace std;
const long long inf = 0x7f7f7f7f;
const double Pi = acos(-1);
const long long mod = 998244353;
const long double eps = 1e-8;
inline long long fpow(long long a, long long b = mod - 2, long long p = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
const long long N = 4e5 + 10;
long long n, _n, L, R, ansu, ansv;
long long val[N];
long long siz[N];
long long vis[N], cxy = 50;
long long dis[N], dep[N], que[N], fa[N], cnt[N], rev[N], ljt[N];
long long M;
long long g[N], gg[N];
vector<pair<long long, long long> > e[N];
long long bfs(long long G) {
  long long st = 1, en = 0;
  que[++en] = G;
  fa[G] = 0;
  for (; st <= en; st++) {
    long long u = que[st];
    for (auto qwq : e[u]) {
      long long v = qwq.first;
      if (vis[v] == cxy) continue;
      if (v != fa[u])
        fa[v] = u, que[++en] = v, dep[v] = dep[u] + 1,
        cnt[v] = cnt[u] + (qwq.second < val[M] ? -1 : 1);
    }
  }
  return en;
}
long long find_gra(long long G) {
  long long Mn = inf, Mnpos;
  long long en = bfs(G);
  for (long long t = (en), tE = (1); t >= tE; t--) {
    long long u = que[t];
    long long mx = 0;
    siz[u] = 1;
    for (auto qwq : e[u]) {
      long long v = qwq.first;
      if (vis[v] == cxy || v == fa[u]) continue;
      siz[u] += siz[v];
      ckmax(mx, siz[v]);
    }
    ckmax(mx, en - siz[u]);
    if (mx < Mn) Mn = mx, Mnpos = u;
  }
  return Mnpos;
}
long long calc(long long u) {
  long long en = bfs(u);
  for (long long i = (1), iE = (en); i <= iE; i++)
    if (rev[dep[que[i]]] < cnt[que[i]])
      rev[dep[que[i]]] = cnt[que[i]], gg[dep[que[i]]] = que[i];
  long long ok = 0, bg = 1, ed = 0;
  for (long long i = en, j = 0; i; i--) {
    long long ql = L - i, qr = R - i;
    if (ql > _n) break;
    ckmax(j, ql);
    for (; j <= qr && j <= _n; j++) {
      for (; bg <= ed && dis[j] > dis[ljt[ed]]; ed--)
        ;
      ljt[++ed] = j;
    }
    for (; bg <= ed && ljt[bg] < ql; bg++)
      ;
    if (bg <= ed && dis[ljt[bg]] + rev[i] >= 0) {
      ansu = g[ljt[bg]], ansv = gg[i], ok = 1;
      break;
    }
  }
  _n = max(_n, en);
  for (long long i = (1), iE = (en); i <= iE; i++) {
    if (rev[i] > dis[i]) dis[i] = rev[i], g[i] = gg[i];
    rev[i] = -inf;
  }
  return ok;
}
long long solve(long long u) {
  long long G = find_gra(u);
  dep[G] = cnt[G] = 0;
  long long en = bfs(G);
  vis[G] = cxy;
  dis[0] = _n = 0;
  g[0] = G;
  for (long long i = (1), iE = (en); i <= iE; i++) dis[i] = rev[i] = -inf;
  for (auto qwq : e[G]) {
    long long v = qwq.first;
    if (vis[v] == cxy) continue;
    if (calc(v)) return 1;
  }
  for (auto qwq : e[G]) {
    long long v = qwq.first;
    if (vis[v] == cxy) continue;
    if (solve(v)) return 1;
  }
  return 0;
}
inline long long check() { return solve(1); }
signed main() {
  n = read(), L = read(), R = read();
  for (long long i = (1), iE = (n - 1); i <= iE; i++) {
    long long u = read(), v = read();
    val[i] = read();
    e[u].push_back(make_pair(v, val[i])), e[v].push_back(make_pair(u, val[i]));
  }
  sort(val + 1, val + n);
  long long l = 1, r = n - 1;
  while (l <= r) {
    M = (l + r) >> 1;
    cxy--;
    if (check())
      l = M + 1;
    else
      r = M - 1;
  }
  M = r;
  cxy--;
  check();
  printf("%lld %lld\n", ansu, ansv);
}
