#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  static char c;
  static int f;
  for (c = getchar(), f = 1; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c & 15);
  x *= f;
}
template <typename T>
void write(T x) {
  static char q[65];
  int cnt = 0;
  if (x < 0) putchar('-'), x = -x;
  q[++cnt] = x % 10, x /= 10;
  while (x) q[++cnt] = x % 10, x /= 10;
  while (cnt) putchar(q[cnt--] + '0');
}
const int mod = 1000000007, maxn = 100005;
int mo(const int x) { return x >= mod ? x - mod : x; }
int power(int a, int x) {
  int re = 1;
  while (x) {
    if (x & 1) re = 1ll * re * a % mod;
    a = 1ll * a * a % mod, x >>= 1;
  }
  return re;
}
struct Edge {
  int v, nt;
  Edge(int v = 0, int nt = 0) : v(v), nt(nt) {}
} e[maxn * 2];
int hd[maxn], num;
void qwq(int u, int v) { e[++num] = Edge(v, hd[u]), hd[u] = num; }
int sz[maxn], ha[maxn], pri[maxn];
void dfs0(int u, int fa) {
  sz[u] = 1;
  ha[u] = 0;
  for (int i = hd[u]; i; i = e[i].nt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs0(v, u);
    sz[u] += sz[v];
    ha[u] = mo(ha[u] + ha[v]);
  }
  ha[u] = mo(1ll * ha[u] * sz[u] % mod + pri[sz[u]]);
}
int I[maxn][4];
void dfs1(int u, int fa) {
  int hu = ha[u], su = sz[u];
  for (int i = hd[u]; i; i = e[i].nt) {
    int v = e[i].v;
    if (v == fa) continue;
    I[v][0] = ha[u];
    I[v][1] = ha[v];
    ha[u] =
        mo(mod - ha[v] +
           1ll * mo(mod - pri[sz[u]] + ha[u]) * power(sz[u], mod - 2) % mod);
    sz[u] -= sz[v];
    ha[u] = mo(1ll * ha[u] * sz[u] % mod + pri[sz[u]]);
    ha[v] = 1ll * mo(mod - pri[sz[v]] + ha[v]) * power(sz[v], mod - 2) % mod;
    sz[v] += sz[u];
    ha[v] = mo(1ll * mo(ha[v] + ha[u]) * sz[v] % mod + pri[sz[v]]);
    I[v][2] = ha[u];
    I[v][3] = ha[v];
    dfs1(v, u);
    ha[u] = hu, sz[u] = su;
  }
}
int ox[maxn * 5], sum[maxn * 5], cnt;
int no, mx, ans;
void add(int pos) { no += !(sum[pos]++); }
void del(int pos) { no -= !(--sum[pos]); }
void dfs2(int u, int fa) {
  if (fa) {
    del(lower_bound(ox, ox + cnt, I[u][0]) - ox);
    del(lower_bound(ox, ox + cnt, I[u][1]) - ox);
    add(lower_bound(ox, ox + cnt, I[u][2]) - ox);
    add(lower_bound(ox, ox + cnt, I[u][3]) - ox);
  }
  if (no > mx) mx = no, ans = u;
  for (int i = hd[u]; i; i = e[i].nt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs2(v, u);
  }
  if (fa) {
    add(lower_bound(ox, ox + cnt, I[u][0]) - ox);
    add(lower_bound(ox, ox + cnt, I[u][1]) - ox);
    del(lower_bound(ox, ox + cnt, I[u][2]) - ox);
    del(lower_bound(ox, ox + cnt, I[u][3]) - ox);
  }
}
int cp[maxn];
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) pri[i] = 1ll * i * i % mod;
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    qwq(u, v);
    qwq(v, u);
  }
  dfs0(1, 0);
  for (int i = 1; i <= n; ++i) ox[cnt++] = cp[i] = ha[i];
  dfs1(1, 0);
  for (int i = 1; i <= n; ++i)
    for (int t = 0; t < 4; ++t) ox[cnt++] = I[i][t];
  sort(ox, ox + cnt);
  cnt = unique(ox, ox + cnt) - ox;
  for (int i = 1; i <= n; ++i) add(lower_bound(ox, ox + cnt, cp[i]) - ox);
  dfs2(1, 0);
  write(ans), putchar('\n');
  return 0;
}
