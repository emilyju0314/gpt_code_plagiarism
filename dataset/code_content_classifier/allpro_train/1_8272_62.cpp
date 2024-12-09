#include <bits/stdc++.h>
const int MAXN = 1e5 + 19;
struct Edge {
  int to, next;
} edge[MAXN << 1];
int head[MAXN], cnt;
inline void add(int from, int to) {
  edge[++cnt].to = to;
  edge[cnt].next = head[from];
  head[from] = cnt;
}
struct Node {
  int ls, rs;
  int max;
  long long sum;
} tr[MAXN << 5];
inline void push_up(int node) {
  tr[node].max = std::max(tr[tr[node].ls].max, tr[tr[node].rs].max);
  tr[node].sum = 0ll;
  if (tr[tr[node].ls].max == tr[node].max) tr[node].sum += tr[tr[node].ls].sum;
  if (tr[tr[node].rs].max == tr[node].max) tr[node].sum += tr[tr[node].rs].sum;
}
int root[MAXN], ind;
void add(int &node, int L, int R, int x) {
  if (!node) node = ++ind;
  if (L == R) {
    tr[node].max = 1;
    tr[node].sum = x;
    return;
  }
  int mid = (L + R) / 2;
  if (x <= mid)
    add(tr[node].ls, L, mid, x);
  else
    add(tr[node].rs, mid + 1, R, x);
  push_up(node);
}
int merge(int x, int y, int L, int R) {
  if (!x || !y) return x + y;
  if (L == R) {
    tr[x].max += tr[y].max;
    return x;
  }
  int mid = (L + R) / 2;
  tr[x].ls = merge(tr[x].ls, tr[y].ls, L, mid);
  tr[x].rs = merge(tr[x].rs, tr[y].rs, mid + 1, R);
  push_up(x);
  return x;
}
int n, c[MAXN];
long long ans[MAXN];
void dfs(int node, int f) {
  add(root[node], 1, n, c[node]);
  for (int i = head[node]; i; i = edge[i].next)
    if (edge[i].to != f) {
      dfs(edge[i].to, node);
      root[node] = merge(root[node], root[edge[i].to], 1, n);
    }
  ans[node] = tr[root[node]].sum;
}
int main() {
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i) std::scanf("%d", c + i);
  for (int i = 2; i <= n; ++i) {
    int x, y;
    std::scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) std::printf("%lld ", ans[i]);
  return 0;
}
