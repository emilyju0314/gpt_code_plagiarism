#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + (s - '0');
    s = getchar();
  }
  return x * f;
}
const int jzm = 1000000007;
int n, m, i, j, s, o, k;
int tp[100005], x[100005], y[100005];
vector<int> g[100005];
int d[100005], f[100005][20];
bool v[100005];
void dfs(int x, int fa) {
  d[x] = d[fa] + 1;
  f[x][0] = fa;
  for (int i = 1; i <= 17; i++) {
    f[x][i] = f[f[x][i - 1]][i - 1];
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != fa) {
      dfs(g[x][i], x);
    }
  }
  return;
}
int lca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  if (d[a] > d[b]) {
    for (int i = 17; i >= 0; i--) {
      if (d[f[a][i]] >= d[b]) a = f[a][i];
    }
  }
  if (a == b) return a;
  for (int i = 17; i >= 0; i--) {
    if (f[a][i] ^ f[b][i]) {
      a = f[a][i], b = f[b][i];
    }
  }
  return f[a][0];
}
int fa[100005];
int findf(int x) { return fa[x] == x ? x : (fa[x] = findf(fa[x])); }
void unionSet(int a, int b) {
  int u = findf(a), v = findf(b);
  fa[u] = v;
  return;
}
int p[100005], rt[100005];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    tp[i] = read();
    if (tp[i] == 2)
      x[i] = read();
    else
      x[i] = read(), y[i] = read();
    if (tp[i] == 1) {
      g[y[i]].push_back(x[i]);
      v[x[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    if (!v[i]) {
      dfs(i, 0);
    }
  }
  int fil = 0;
  for (int i = 1; i <= m; i++) {
    if (tp[i] == 1) {
      unionSet(x[i], y[i]);
    } else if (tp[i] == 2) {
      p[++fil] = x[i];
      rt[fil] = findf(x[i]);
    } else {
      if (lca(x[i], p[y[i]]) == x[i] && lca(x[i], rt[y[i]]) == rt[y[i]]) {
        printf("YES\n");
      } else
        printf("NO\n");
    }
  }
  return 0;
}
