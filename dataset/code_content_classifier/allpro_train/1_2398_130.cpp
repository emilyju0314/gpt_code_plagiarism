#include <bits/stdc++.h>
using namespace std;
template <typename t>
inline void read(t &x) {
  x = 0;
  t f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
const int N = 5e5 + 5;
const int inf = 1 << 30;
const int mod = 1e9 + 7;
int n, m, a[N], sum[N], ans[N], fa[N], sz[N];
int pw[N], ipw[N], pre[N], jud[N], qian[N];
vector<pair<int, int> > g[N];
inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }
inline int query(int l, int r) {
  int tmp = sub(sum[l], mul(sub(pre[r - 1], pre[l - 1]), ipw[l]));
  return mul(tmp, ipw[r - l]);
}
void init() {
  pw[0] = ipw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = 2 * pw[i - 1] % mod;
    ipw[i] = (long long)(mod + 1) / 2 * ipw[i - 1] % mod;
    pre[i] = add(pre[i - 1], mul((a[i] % mod + mod) % mod, pw[i]));
  }
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if ((sz[x] > 30 && jud[y] > 0) ||
      (((long long)jud[y] << sz[x]) + jud[x] > inf)) {
    jud[x] = inf;
  } else
    jud[x] += jud[y] << sz[x];
  sum[x] = add(sum[x], mul(pw[sz[x]], sum[y]));
  sz[x] += sz[y];
  fa[y] = x;
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    fa[i] = i, sz[i] = 1;
  }
  init();
  for (int i = 1, l, r; i <= m; ++i) {
    read(l), read(r);
    g[r].push_back(pair<int, int>(l, i));
  }
  for (int i = 1, tmp; i <= n; ++i) {
    tmp = i;
    jud[tmp] = a[tmp];
    sum[tmp] = (a[tmp] % mod + mod) % mod;
    qian[tmp] = add(qian[find(tmp - 1)], sum[tmp]);
    while (tmp != 1) {
      if (jud[find(tmp)] < 0) break;
      merge(tmp - 1, tmp);
      tmp = find(tmp);
      qian[tmp] = add(qian[find(tmp - 1)], sum[tmp]);
    }
    for (int j = 0; j < (int)g[i].size(); ++j) {
      int l = g[i][j].first;
      int res = 0;
      res = sub(qian[find(i)], qian[find(l)]);
      res = mul(res, 2);
      res = add(res, query(find(l), l));
      ans[g[i][j].second] = res;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
