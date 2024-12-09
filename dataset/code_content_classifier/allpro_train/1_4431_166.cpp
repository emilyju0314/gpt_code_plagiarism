#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
int w[105][105], v[105], vis[105], ans[105];
struct node {
  int v, id;
  bool operator<(const node x) const { return v > x.v; }
};
node add[105][105];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &w[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) v[i] += w[j][i];
  for (int i = 1; i <= n; ++i) v[i] = v[n] - v[i];
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j < n; ++j)
      add[j][i].v = w[i][n] - w[i][j], add[j][i].id = i;
  for (int i = 1; i < n; ++i) sort(add[i] + 1, add[i] + m + 1);
  int num = inf, now;
  for (int i = 1; i < n; ++i) {
    now = 0;
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= m; ++j) {
      if (v[i] > 0) {
        vis[++now] = add[i][j].id;
        v[i] -= add[i][j].v;
      } else
        break;
    }
    if (now < num) {
      num = now;
      for (int i = 1; i <= num; ++i) ans[i] = vis[i];
    }
  }
  printf("%d\n", num);
  if (num) {
    for (int i = 1; i < num; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[num]);
  }
  return 0;
}
