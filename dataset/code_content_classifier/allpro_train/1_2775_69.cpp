#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int head[N], cnt, t[N], x[N];
long long f[N], dp_mx[N], dp_sec[N], T;
long long num[N << 2], sum[N << 2];
struct edge {
  int next, to, w;
} e[N << 1];
void add(int u, int v, int w) {
  e[++cnt].next = head[u];
  e[cnt].to = v;
  e[cnt].w = w;
  head[u] = cnt;
}
void update(int l, int r, int x, int val, int rt) {
  if (l == r) {
    num[rt] += val;
    sum[rt] += l * 1ll * val;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    update(l, mid, x, val, (rt << 1));
  else
    update(mid + 1, r, x, val, (rt << 1 | 1));
  sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)];
  num[rt] = num[(rt << 1)] + num[(rt << 1 | 1)];
}
long long query(int l, int r, long long val, int rt) {
  if (l == r) return val / l;
  int mid = l + r >> 1;
  if (val > sum[(rt << 1)])
    return num[(rt << 1)] +
           query(mid + 1, r, val - sum[(rt << 1)], (rt << 1 | 1));
  else
    return query(l, mid, val, (rt << 1));
}
void dfs(int u, long long dep) {
  update(1, 1000000, t[u], x[u], 1);
  long long p = 0;
  if (sum[1] <= T - 2 * dep)
    p = num[1];
  else
    p = query(1, 1000000, T - 2 * dep, 1);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    dfs(v, dep + e[i].w);
    if (f[v] > dp_sec[u]) dp_sec[u] = f[v];
    if (dp_sec[u] > dp_mx[u]) swap(dp_sec[u], dp_mx[u]);
  }
  f[u] = max(p, dp_sec[u]);
  dp_mx[u] = max(p, dp_mx[u]);
  update(1, 1000000, t[u], -x[u], 1);
}
int main() {
  int n;
  scanf("%d %lld", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 2; i <= n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(a, i, b);
  }
  dfs(1, 0);
  printf("%lld\n", dp_mx[1]);
}
