#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, block;
int col[maxn], cnt[maxn * 10], ans[maxn];
int dfn, st[maxn], en[maxn];
struct node {
  int u, v, nxt;
} e[2 * maxn];
int tot, head[maxn], val[maxn], l, r;
void init() {
  tot = 0;
  memset((head), -1, sizeof(head));
  dfn = 0;
}
void add_edge(int u, int v) {
  e[tot].v = v;
  e[tot].nxt = head[u];
  head[u] = tot++;
}
void dfs(int u, int fa) {
  st[u] = ++dfn;
  val[dfn] = col[u];
  for (int i = head[u]; ~i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
  }
  en[u] = dfn;
}
int bit[maxn];
int lowbit(int x) { return x & -x; }
void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += lowbit(i);
  }
}
int getsum(int i) {
  int sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= lowbit(i);
  }
  return sum;
}
struct query {
  int l, r, id, k;
  bool operator<(const query &a) const {
    if (l / block != a.l / block) return l / block < a.l / block;
    return r < a.r;
  }
} q[maxn];
void _add(int i) {
  if (cnt[i] > 0) add(cnt[i], -1);
  cnt[i]++;
  add(cnt[i], 1);
}
void del(int i) {
  add(cnt[i], -1);
  cnt[i]--;
  if (cnt[i] > 0) add(cnt[i], 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &col[i]);
  }
  init();
  block = sqrt(n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, -1);
  for (int i = 1; i <= m; i++) {
    int v, k;
    scanf("%d%d", &v, &k);
    q[i].id = i;
    q[i].l = st[v];
    q[i].r = en[v];
    q[i].k = k;
  }
  sort(q + 1, q + 1 + m);
  l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    while (r < q[i].r) _add(val[++r]);
    while (r > q[i].r) del(val[r--]);
    while (l < q[i].l) del(val[l++]);
    while (l > q[i].l) _add(val[--l]);
    if (q[i].k > n)
      ans[q[i].id] = 0;
    else
      ans[q[i].id] = getsum(n) - getsum(q[i].k - 1);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
