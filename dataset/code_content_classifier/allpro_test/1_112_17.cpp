#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 400005, K = 97;
int n, m, q, i, j, len, x, y, g[N], v[N << 1], w[N << 1], nxt[N << 1], ed;
int f[N], c[N], d[N], son[N], sz[N], top[N], loc[N], locrev[N], dfn, seq[N];
int cp, at[M], pool[M];
char tmp[M];
int ce, cb, ans[N], G[M], V[N << 1], NXT[N << 1], ED, bit[N];
struct E {
  int l, r, len;
  E() {}
  E(int _l, int _r) { l = _l, r = _r; }
} e[K], b[K], que[N];
namespace SA {
const int N = 800015, M = 19;
int n, rk[N], sa[N], height[N], tmp[N], cnt[N], s[N];
int Log[N], f[M][N >> 1];
void suffixarray(int n) {
  int i, j, k;
  n++;
  for (i = 0; i < n; i++) cnt[rk[i] = s[i]]++;
  for (i = 1; i < N; i++) cnt[i] += cnt[i - 1];
  for (i = 0; i < n; i++) sa[--cnt[rk[i]]] = i;
  for (k = 1; k <= n; k <<= 1) {
    for (i = 0; i < n; i++) {
      j = sa[i] - k;
      if (j < 0) j += n;
      tmp[cnt[rk[j]]++] = j;
    }
    sa[tmp[cnt[0] = 0]] = j = 0;
    for (i = 1; i < n; i++) {
      if (rk[tmp[i]] != rk[tmp[i - 1]] || rk[tmp[i] + k] != rk[tmp[i - 1] + k])
        cnt[++j] = i;
      sa[tmp[i]] = j;
    }
    memcpy(rk, sa, n * sizeof(int));
    memcpy(sa, tmp, n * sizeof(int));
    if (j >= n - 1) break;
  }
  for (j = rk[height[i = k = 0] = 0]; i < n - 1; i++, k++)
    while (~k && s[i] != s[sa[j - 1] + k]) height[j] = k--, j = rk[sa[j] + 1];
}
void init(int _n) {
  int i, j;
  n = _n;
  for (i = 0; i < n; i++) s[i] = pool[i];
  suffixarray(n);
  for (i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (j = 2; j <= n; j++) f[0][j] = height[j];
  for (i = 1; i < M; i++)
    for (j = 1; j + (1 << i) - 1 <= n; j++)
      f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
}
inline int lcp(int x, int y) {
  if (x == y) return n - x;
  x = rk[x], y = rk[y];
  if (x > y) swap(x, y);
  int k = Log[y - x];
  return min(f[k][x + 1], f[k][y - (1 << k) + 1]);
}
inline bool smaller(int x) {
  x = sa[x];
  for (int i = 1; i <= ce; i++) {
    int A = n - x, B = e[i].len, t = min(min(A, B), lcp(x, e[i].l));
    if (t < A && t < B) return s[x + t] < s[e[i].l + t];
    if (t == A && t == B) return i < ce;
    if (t < B) return 1;
    x += B;
  }
  return 0;
}
inline bool match(int x) {
  x = sa[x];
  for (int i = 1; i <= ce; i++) {
    int A = n - x, B = e[i].len, t = min(min(A, B), lcp(x, e[i].l));
    if (t < B) return 0;
    if (t == A) return i == ce;
    x += B;
  }
  return 1;
}
}  // namespace SA
inline void add(int x, int y, int z) {
  v[++ed] = y;
  w[ed] = z;
  nxt[ed] = g[x];
  g[x] = ed;
}
void dfs(int x, int y) {
  sz[x] = 1;
  for (int i = g[x]; i; i = nxt[i]) {
    int u = v[i];
    if (u == y) continue;
    f[u] = x;
    d[u] = d[x] + 1;
    c[u] = w[i];
    dfs(u, x);
    sz[x] += sz[u];
    if (sz[u] > sz[son[x]]) son[x] = u;
  }
}
void dfs2(int x, int y) {
  top[x] = y;
  seq[++dfn] = x;
  if (son[x]) dfs2(son[x], y);
  for (int i = g[x]; i; i = nxt[i])
    if (v[i] != f[x] && v[i] != son[x]) dfs2(v[i], v[i]);
}
inline int findpos() {
  int l = 1, r = cp, mid, t = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (SA::smaller(mid))
      l = (t = mid) + 1;
    else
      r = mid - 1;
  }
  return t;
}
inline int findl(int r) {
  int l = 1, mid, t = r + 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (SA::match(mid))
      r = (t = mid) - 1;
    else
      l = mid + 1;
  }
  return t;
}
inline int findr(int l) {
  int r = cp, mid, t = l - 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (SA::match(mid))
      l = (t = mid) + 1;
    else
      r = mid - 1;
  }
  return t;
}
inline void ADD(int x, int y) {
  V[++ED] = y;
  NXT[ED] = G[x];
  G[x] = ED;
}
inline void modify(int x) {
  for (; x <= m; x += x & -x) bit[x]++;
}
inline int ask(int x) {
  int t = 0;
  for (; x; x -= x & -x) t += bit[x];
  return t;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i < n; i++) {
    char s[9];
    scanf("%d%d%s", &x, &y, s);
    add(x, y, s[0]);
    add(y, x, s[0]);
  }
  for (i = 1; i <= m; i++) {
    scanf("%s", tmp);
    len = strlen(tmp);
    for (j = 0; j < len; j++) {
      at[cp] = i;
      pool[cp++] = tmp[j];
    }
    pool[cp++] = ((int)('z')) + i;
  }
  c[1] = 'a';
  dfs(1, 0);
  dfs2(1, 1);
  for (i = 1; i <= dfn; i++) {
    x = seq[i];
    loc[x] = cp;
    pool[cp++] = c[x];
  }
  for (i = dfn; i; i--) {
    x = seq[i];
    locrev[x] = cp;
    pool[cp++] = c[x];
  }
  SA::init(cp);
  for (i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &x, &y, &que[i].l, &que[i].r);
    ce = cb = 0;
    while (top[x] != top[y]) {
      if (d[top[x]] > d[top[y]]) {
        e[++ce] = E(locrev[x], locrev[top[x]]);
        x = f[top[x]];
      } else {
        b[++cb] = E(loc[top[y]], loc[y]);
        y = f[top[y]];
      }
    }
    if (d[x] < d[y]) e[++ce] = E(loc[x] + 1, loc[y]);
    if (d[x] > d[y]) e[++ce] = E(locrev[x], locrev[y] - 1);
    for (j = cb; j; j--) e[++ce] = b[j];
    for (j = 1; j <= ce; j++) e[j].len = e[j].r - e[j].l + 1;
    x = findpos();
    int l = findl(x), r = findr(x + 1);
    if (l <= r) {
      ADD(l - 1, -i);
      ADD(r, i);
    }
  }
  for (i = 1; i <= cp; i++) {
    x = SA::sa[i];
    if (at[x]) modify(at[x]);
    for (j = G[i]; j; j = NXT[j]) {
      x = y = V[j];
      if (y < 0) y = -y;
      int tmp = ask(que[y].r) - ask(que[y].l - 1);
      if (x > 0)
        ans[y] += tmp;
      else
        ans[y] -= tmp;
    }
  }
  for (i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
