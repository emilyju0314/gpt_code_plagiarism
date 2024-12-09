#include <bits/stdc++.h>
using namespace std;
const int maxn = 210000;
const int inf = 1 << 30;
const long long mod = 1e9 + 7;
int head[maxn * 2], nxt[maxn * 2], to[maxn * 2];
int vis[maxn], p;
int L[maxn], R[maxn];
int pos, sz, n, k, cur;
long long sum = 1, ans = 0, inv[maxn];
struct {
  int n, m, x[maxn], y[maxn], size;
  long long sum[maxn * 4], add[maxn * 4], val[maxn];
  void build(int size) {
    this->n = size;
    this->size = 0;
    for (m = 1; m <= n; m <<= 1)
      ;
    memset(sum, 0, sizeof(long long) * (m + n + 1));
    memset(add, 0, sizeof(long long) * (m + n + 1));
  }
  void update(int s, int t, long long v, bool insertion = true) {
    if (insertion) {
      x[size] = s;
      y[size] = t;
      val[size] = v;
      ++size;
    }
    int A = 0, lc = 0, rc = 0, len = 1;
    for (s += m - 1, t += m + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1) {
      if (~s & 1) add[s ^ 1] += v, lc += len;
      if (t & 1) add[t ^ 1] += v, rc += len;
      sum[s >> 1] += v * lc, sum[t >> 1] += v * rc;
    }
    for (lc += rc; s; s >>= 1) sum[s >> 1] += v * lc;
  }
  long long query(int s, int t) {
    int lc = 0, rc = 0, len = 1;
    long long ans = 0;
    for (s += m - 1, t += m + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1) {
      if (s & 1 ^ 1) ans += sum[s ^ 1] + len * add[s ^ 1], lc += len;
      if (t & 1) ans += sum[t ^ 1] + len * add[t ^ 1], rc += len;
      ans += add[s >> 1] * lc;
      ans += add[t >> 1] * rc;
    }
    for (lc += rc, s >>= 1; s; s >>= 1) ans += add[s] * lc;
    return ans % mod;
  }
} tree, base;
long long pow_mod(long long a, long long n, long long p) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return ans;
}
long long inverse(long long a) { return pow_mod(a, mod - 2, mod); }
void insert(int u, int v) {
  nxt[++cur] = head[u];
  head[u] = cur;
  to[cur] = v;
}
int dfs0(int u, int fa) {
  int tot = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa && !vis[v]) tot += dfs0(v, u);
  }
  return tot;
}
int dfs1(int u, int fa, int cnt) {
  int tot = 1, num = 0;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa && !vis[v]) {
      int result = dfs1(v, u, cnt);
      tot += result;
      num = max(num, result);
    }
  }
  num = max(num, cnt - tot);
  if (num < sz) {
    sz = num;
    pos = u;
  }
  return tot;
}
long long dfs2(int u, int fa, int dep) {
  long long res = tree.query(L[u], R[u]) * inv[u] % mod;
  res += base.query(L[u], R[u]) * dep % mod * inv[u] % mod;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa && !vis[v]) {
      res += dfs2(v, u, dep + 1);
    }
  }
  return res % mod;
}
void dfs3(int u, int fa, long long dep) {
  tree.update(L[u], R[u], dep * sum % mod * inv[u] % mod);
  base.update(L[u], R[u], sum * inv[u] % mod);
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa && !vis[v]) {
      dfs3(v, u, dep + 1);
    }
  }
}
long long calc(int root) {
  if (tree.size > 10000)
    tree.build(100002);
  else {
    for (int i = 0; i < tree.size; ++i)
      tree.update(tree.x[i], tree.y[i], -tree.val[i], false);
    tree.size = 0;
  }
  if (base.size > 10000)
    base.build(100002);
  else {
    for (int i = 0; i < base.size; ++i)
      base.update(base.x[i], base.y[i], -base.val[i], false);
    base.size = 0;
  }
  long long res = 0;
  for (int i = head[root]; i; i = nxt[i]) {
    int v = to[i];
    if (!vis[v]) {
      res += dfs2(v, root, 1);
      dfs3(v, root, 1);
    }
  }
  res += tree.query(L[root], R[root]) * inv[root];
  return res % mod;
}
void solve(int u, int cnt) {
  sz = inf;
  dfs1(u, -1, cnt);
  int root = pos;
  vis[root] = 1;
  ans += calc(root);
  ans %= mod;
  for (int i = head[root]; i; i = nxt[i]) {
    int v = to[i];
    if (!vis[v]) {
      int tot = dfs0(v, -1);
      solve(v, tot);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &L[i], &R[i]);
    sum = (R[i] - L[i] + 1) * sum % mod;
    inv[i] = inverse(R[i] - L[i] + 1);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    insert(u, v);
    insert(v, u);
  }
  tree.build(100002);
  base.build(100002);
  solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
