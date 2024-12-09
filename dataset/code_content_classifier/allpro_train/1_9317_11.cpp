#include <bits/stdc++.h>
const int N = 200001;
int i, j, k, n, t, a[N];
int en[N * 2], nxt[N * 2], fa[N];
inline void w(int u) {
  a[u] = -a[u];
  printf("%d ", u);
}
void dfs(int u, int p) {
  int i = fa[u], v;
  for (w(u); i; i = nxt[i])
    if ((v = en[i]) != p) {
      dfs(v, u), w(u);
      if (a[v] < 0) w(v), w(u);
    }
  if (u == 1)
    if (a[u] > 0) w(v = en[fa[u]]), w(u), w(v);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  for (k = 1; k < n; ++k) {
    scanf("%d%d", &i, &j);
    en[++t] = j, nxt[t] = fa[i], fa[i] = t;
    en[++t] = i, nxt[t] = fa[j], fa[j] = t;
  }
  dfs(1, 0);
}
