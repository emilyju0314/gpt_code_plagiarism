#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> g[maxn], B[maxn];
set<int> L[maxn];
long long b[maxn], s[maxn], ans;
int v[maxn], d[maxn];
inline void fun(int x, int y) {
  ans -= b[x] * s[x] + b[y] * s[y];
  b[x] -= 1, s[x] += 1;
  b[y] += 1, s[y] -= 1;
  ans += b[x] * s[x] + b[y] * s[y];
}
int main() {
  int n, m, q;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) v[i] = i;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
    d[u] += 1, d[v] += 1;
    if (u > v)
      s[u] += 1, b[v] += 1;
    else
      s[v] += 1, b[u] += 1;
  }
  for (int i = 1; i <= n; ++i) ans += b[i] * s[i];
  printf("%lld\n", ans);
  int thre = 100;
  for (int i = 1; i <= n; ++i)
    for (int j : g[i])
      if (d[j] > thre) B[i].push_back(j);
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x;
    scanf("%d", &x);
    if (d[x] <= thre || v[x] == x) {
      for (int y : g[x])
        if (v[y] > v[x]) fun(x, y);
      if (d[x] <= thre)
        for (int y : B[x]) L[y].insert(x);
    } else {
      for (int y : L[x])
        if (v[y] > v[x]) fun(x, y);
      L[x].clear();
      for (int y : B[x])
        if (v[y] > v[x]) fun(x, y);
    }
    v[x] = n + i;
    printf("%lld\n", ans);
  }
  return 0;
}
