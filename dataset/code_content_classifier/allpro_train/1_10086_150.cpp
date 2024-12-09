#include <bits/stdc++.h>
using namespace std;
const int MaxE = 2e6;
const int MaxN = 1e5;
int n, m;
int all, last[MaxN + 5], pre[2 * MaxN + 5], other[2 * MaxN + 5];
int fa[MaxN + 5], a[MaxN + 5], dep[MaxN + 5];
int prime[MaxE + 5], tot;
bool flag[MaxE + 5];
int T[MaxE + 5];
struct Point {
  int w, p;
} ans[MaxN + 5];
void Get_Prime() {
  flag[1] = 1;
  tot = 0;
  for (int i = 2; i <= MaxE; i++) {
    if (flag[i] == 0) prime[++tot] = i;
    for (int j = 1; j <= tot; j++) {
      if (prime[j] * i > MaxE) break;
      flag[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
void Build(int x, int y) {
  pre[++all] = last[x];
  last[x] = all;
  other[all] = y;
}
void Dfs(int x, int y) {
  fa[x] = y;
  dep[x] = dep[y] + 1;
  int q = 0;
  int w = a[x];
  int r[105], p[105];
  for (int i = 1; i <= tot; i++) {
    if (w % prime[i] == 0) {
      p[++q] = prime[i];
      while (w % prime[i] == 0) w /= prime[i];
    }
    if (prime[i] * prime[i] > w) break;
  }
  if (w != 1) p[++q] = w;
  ans[x].w = 0;
  ans[x].p = 0;
  for (int i = 1; i <= q; i++)
    if (ans[x].w < dep[T[p[i]]]) ans[x].w = dep[T[p[i]]], ans[x].p = T[p[i]];
  for (int i = 1; i <= q; i++) {
    r[i] = T[p[i]];
    T[p[i]] = x;
  }
  int ed = last[x], dr;
  while (ed != -1) {
    dr = other[ed];
    if (dr != y) Dfs(dr, x);
    ed = pre[ed];
  }
  for (int i = 1; i <= q; i++) T[p[i]] = r[i];
}
int main() {
  Get_Prime();
  all = -1;
  memset(last, -1, sizeof(last));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Build(u, v);
    Build(v, u);
  }
  memset(T, 0, sizeof(T));
  dep[0] = 0;
  Dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int flag;
    scanf("%d", &flag);
    if (flag == 1) {
      int v;
      scanf("%d", &v);
      if (ans[v].p != 0)
        printf("%d\n", ans[v].p);
      else
        printf("-1\n");
    } else {
      int v, w;
      scanf("%d%d", &v, &w);
      a[v] = w;
      Dfs(1, 0);
    }
  }
}
