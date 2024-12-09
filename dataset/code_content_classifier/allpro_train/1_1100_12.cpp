#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1500000001;
const int maxn = 3e5 + 7;
const double pi = acos(-1.0);
const int v2 = (mod + 1) / 2;
const double eps = 1e-7;
int n, m, l[maxn], r[maxn], cnt, maxl[maxn], pos[maxn], dep[maxn], vis[maxn],
    father[maxn];
long long sum[maxn];
vector<int> g[maxn];
void dfs(int now, int fa, int num) {
  vis[now] = 1, father[now] = fa, dep[now] = num;
  for (int i = 0; i < g[now].size(); i++) {
    int to = g[now][i];
    if (!vis[to])
      dfs(to, now, num + 1);
    else if (to != fa && dep[to] < dep[now]) {
      cnt++;
      for (int j = now;; j = father[j]) {
        l[cnt] = min(l[cnt], j), r[cnt] = max(r[cnt], j);
        if (j == to) break;
      }
    }
  }
}
void init() {
  memset(maxl, 0, sizeof(maxl));
  for (int i = 0; i <= cnt; i++) {
    maxl[r[i]] = max(maxl[r[i]], l[i]);
  }
  for (int i = 1; i <= n; i++) {
    maxl[i] = max(maxl[i], maxl[i - 1]);
  }
  for (int i = n; i > maxl[n]; i--) pos[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = maxl[i]; j > maxl[i - 1]; j--) pos[j] = i;
  }
  sum[0] = 0;
  for (int i = 0; i <= n; i++) {
    sum[i] = sum[i - 1] + 1ll * (i - maxl[i]);
  }
}
long long solve(int a, int b) {
  int p = pos[--a];
  if (p <= a) {
    return sum[b] - sum[a];
  } else if (p > a && p <= b)
    return sum[b] - sum[p - 1] + 1ll * (p - a - 1) * (p - a) / 2;
  else
    return 1ll * (b - a + 1) * (b - a) / 2;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) vis[i] = 0, l[i] = n + 1, r[i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cnt = -1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, -1, 0);
  }
  init();
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", solve(a, b));
  }
  return 0;
}
