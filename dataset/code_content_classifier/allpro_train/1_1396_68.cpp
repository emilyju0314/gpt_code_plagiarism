#include <bits/stdc++.h>
using namespace std;
int n, a[500010], root;
vector<int> G[500010];
int fa[20][500010];
long long res;
void DFS(int u) {
  for (int i = 1; i < 20; ++i) fa[i][u] = fa[i - 1][fa[i - 1][u]];
  long long tmp = 0x3f3f3f3f3f3f3f3f;
  int d = 0;
  for (; fa[d][u]; ++d) tmp = min(tmp, 1ll * (d + 1) * a[fa[d][u]] + a[u]);
  tmp = min(tmp, 1ll * (d + 1) * a[root] + a[u]);
  if (u != root) res += tmp;
  for (auto v : G[u])
    if (v != fa[0][u]) {
      fa[0][v] = u;
      DFS(v);
    }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) G[i].clear();
    memset(fa, 0, sizeof fa);
    root = 1;
    res = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[root] > a[i]) root = i;
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    DFS(root);
    printf("%lld\n", res);
  }
  return 0;
}
