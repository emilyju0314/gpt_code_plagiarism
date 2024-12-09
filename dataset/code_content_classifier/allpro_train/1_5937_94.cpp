#include <bits/stdc++.h>
using namespace std;
const int N = 505000;
int n, a[N], b[N];
pair<int, int> t[N << 2];
void build(int p, int l, int r) {
  if (l == r) {
    t[p] = make_pair(b[l], l);
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  t[p] = max(t[p << 1], t[p << 1 | 1]);
}
void update(int p, int l, int r, int pos) {
  if (l == r) {
    t[p] = make_pair(0, l);
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(p << 1, l, mid, pos);
  else
    update(p << 1 | 1, mid + 1, r, pos);
  t[p] = max(t[p << 1], t[p << 1 | 1]);
}
pair<int, int> query(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) return t[p];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(p << 1, l, mid, L, R);
  else if (L > mid)
    return query(p << 1 | 1, mid + 1, r, L, R);
  else
    return max(query(p << 1, l, mid, L, R),
               query(p << 1 | 1, mid + 1, r, L, R));
}
int tot, l[N], p[N];
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  update(1, 1, n, u);
  if (b[u] != n + 1 && !vis[b[u]]) dfs(b[u]);
  if (a[u] > 1) {
    while (true) {
      pair<int, int> now = query(1, 1, n, 1, a[u] - 1);
      if (now.first > u && !vis[now.second])
        dfs(now.second);
      else
        break;
    }
  }
  l[++tot] = u;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != -1)
      b[a[i]] = i;
    else
      a[i] = n + 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!b[i]) b[i] = n + 1;
  build(1, 1, n);
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
  tot = 0;
  for (int i = 1; i <= n; ++i) p[l[i]] = ++tot;
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  return 0;
}
