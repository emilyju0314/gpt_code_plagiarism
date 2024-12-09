#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7, mod = 1e9 + 7;
int n;
double a[MAXN], b[MAXN], suma, sumb;
vector<int> edge[MAXN];
int siz[MAXN];
void dfs1(int now = 1, int fa = 0) {
  siz[now] = 1;
  for (auto v : edge[now]) {
    if (v == fa) continue;
    dfs1(v, now);
    siz[now] += siz[v];
  }
}
double ans, Sum, nowsum;
void dfs2(int now = 1, int fa = 0) {
  nowsum += (siz[now] - 1) * b[now];
  ans += (Sum + nowsum - (n - 1) * b[now]) * a[now];
  for (auto v : edge[now]) {
    if (v == fa) continue;
    nowsum -= (n - siz[v] - 1) * b[now];
    dfs2(v, now);
    nowsum += (n - siz[v] - 1) * b[now];
  }
  nowsum -= (siz[now] - 1) * b[now];
}
int main() {
  scanf("%d", &n);
  for (int i = 1, i2, i3; i < n; i++)
    scanf("%d%d", &i2, &i3), edge[i2].push_back(i3), edge[i3].push_back(i2);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", a + i, b + i), suma += a[i], sumb += b[i];
  for (int i = 1; i <= n; i++) a[i] /= suma, b[i] /= sumb;
  dfs1();
  Sum = n - 1;
  for (int i = 1; i <= n; i++) Sum -= (siz[i] - 1) * b[i];
  dfs2();
  printf("%0.9lf", ans);
}
