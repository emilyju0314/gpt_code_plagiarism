#include <bits/stdc++.h>
using namespace std;
struct edge {
  int go, next;
} e[200005];
int n, m, a[100005], isleaf[100005], f[100005], ljb[100005], cnt;
void dfs(int x, int ff) {
  if (a[x])
    f[x] = f[ff] + 1;
  else
    f[x] = 0;
  for (int i = ljb[x]; i; i = e[i].next)
    if (e[i].go != ff) dfs(e[i].go, x);
}
void dd(int x, int ff) {
  f[x] = max(f[x], f[ff]);
  isleaf[x] = 1;
  for (int i = ljb[x]; i; i = e[i].next)
    if (e[i].go != ff) {
      dd(e[i].go, x);
      isleaf[x] = 0;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[++cnt].go = y;
    e[cnt].next = ljb[x];
    ljb[x] = cnt;
    e[++cnt].go = x;
    e[cnt].next = ljb[y];
    ljb[y] = cnt;
  }
  dfs(1, 0);
  dd(1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (isleaf[i] && f[i] <= m) ans++;
  printf("%d", ans);
}
