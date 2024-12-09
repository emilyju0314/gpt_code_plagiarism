#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5, Mod1 = 1e9 + 7, Mod2 = 998244353;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() { return getchar(); }
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
struct HASH {
  int a, b;
  HASH(int a = 0, int b = 0) : a(a), b(b) {}
  inline friend HASH operator+(HASH a, HASH b) {
    return HASH((a.a + b.a) % Mod1, (a.b + b.b) % Mod2);
  }
  inline friend HASH operator-(HASH a, HASH b) {
    return HASH((a.a - b.a + Mod1) % Mod1, (a.b - b.b + Mod2) % Mod2);
  }
  inline friend HASH operator*(HASH a, HASH b) {
    return HASH(1ll * a.a * b.a % Mod1, 1ll * a.b * b.b % Mod2);
  }
  inline friend bool operator==(HASH a, HASH b) {
    return (a.a == b.a) && (a.b == b.b);
  }
} Hash1[MAXN], Hash2[MAXN], Fpow[MAXN], iFpow[MAXN];
inline int Fp(int x, int k, int Mod) {
  int ans = 1;
  for (; k; k >>= 1, x = 1ll * x * x % Mod)
    if (k & 1) ans = 1ll * ans * x % Mod;
  return ans;
}
int n, m, tim, fa[MAXN], dep[MAXN], sz[MAXN], w[MAXN], dfn[MAXN], tr[MAXN],
    top[MAXN];
char s[MAXN];
vector<int> G[MAXN];
void dfs(int x, int f) {
  fa[x] = f, dep[x] = dep[f] + 1, sz[x] = 1,
  Hash1[x] = Hash1[fa[x]] + Fpow[dep[x] - 1] * HASH(s[x], s[x]),
  Hash2[x] = Hash2[fa[x]] * HASH(131, 131) + HASH(s[x], s[x]);
  for (auto y : G[x])
    if (y != f) dfs(y, x), sz[x] += sz[y], sz[y] > sz[w[x]] ? w[x] = y : 0;
}
void dfs1(int x, int tp) {
  top[x] = tp, tr[dfn[x] = ++tim] = x;
  if (w[x]) dfs1(w[x], tp);
  for (auto y : G[x])
    if (y != fa[x] && y != w[x]) dfs1(y, y);
}
inline int lca(int x, int y) {
  for (; top[x] != top[y]; x = fa[top[x]])
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
  return dep[x] < dep[y] ? x : y;
}
inline int kth(int x, int k) {
  for (; k > dep[x] - dep[top[x]];
       k -= dep[x] - dep[top[x]] + 1, x = fa[top[x]])
    ;
  return tr[dfn[x] - k];
}
inline HASH Get(int x, int y, int z, int k) {
  if (!k) return HASH(0, 0);
  if (k <= dep[x] - dep[z] + 1) {
    int t = kth(x, k);
    return (Hash1[x] - Hash1[t]) * iFpow[dep[t]];
  } else {
    k -= dep[x] - dep[z] + 1;
    int t = kth(y, dep[y] - (dep[z] + k));
    HASH p1 = (Hash1[x] - Hash1[fa[z]]) * iFpow[dep[fa[z]]],
         p2 = (Hash2[t] - Hash2[z] * Fpow[k]);
    return p1 * Fpow[k] + p2;
  }
}
int main() {
  n = read(), Fpow[0] = iFpow[0] = HASH(1, 1), scanf("%s", s + 1);
  for (int i = (1); i <= (n); i++) {
    int a = 131, b = Fp(131, Mod1 - 2, Mod1), c = Fp(131, Mod2 - 2, Mod2);
    Fpow[i] = Fpow[i - 1] * HASH(a, a), iFpow[i] = iFpow[i - 1] * HASH(b, c);
  }
  for (int i = (1); i <= (n - 1); i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0), dfs1(1, 0);
  for (int m = read(); m--;) {
    int a = read(), b = read(), c = read(), d = read(), x = lca(a, b),
        y = lca(c, d), l = 0,
        r = min(dep[a] + dep[b] - 2 * dep[x] + 1,
                dep[c] + dep[d] - 2 * dep[y] + 1),
        ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      HASH t1 = Get(a, b, x, mid), t2 = Get(c, d, y, mid);
      if (t1 == t2)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
