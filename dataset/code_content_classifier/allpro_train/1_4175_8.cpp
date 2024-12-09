#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 100;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
vector<int> g[N], p, q[N];
int vis[N], d[N];
int a[N], n;
void dfs(int x) {
  vis[x] = 1;
  for (int to : g[x])
    if (!vis[to]) dfs(to);
}
void go(int x) {
  int k = (x & 1 ? x + 1 : x - 1);
  while (q[a[k]].size()) {
    int to = q[a[k]].back();
    q[a[k]].pop_back();
    if (vis[to]) continue;
    int kk = (to & 1 ? to + 1 : to - 1);
    vis[to] = vis[kk] = 1;
    go(to);
    p.push_back(kk);
    p.push_back(to);
  }
}
bool check(int x) {
  int st = (1 << x) - 1;
  for (int i = 0; i <= st; i++) g[i].clear(), vis[i] = 0, d[i] = 0;
  for (int i = 1; i <= n; i++) {
    int u = a[i * 2 - 1] & st, v = a[i * 2] & st;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u]++, d[v]++;
  }
  dfs(a[1] & st);
  for (int i = 0; i <= st; i++) {
    if (d[i] > 0 && !vis[i]) return 0;
    if (vis[i] && d[i] & 1) return 0;
  }
  return 1;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i * 2 - 1] = read();
    a[i * 2] = read();
  }
  int ans = 0;
  for (int i = 0; i <= 20; i++) {
    if (check(i)) {
      ans = i;
    } else
      break;
  }
  int st = (1 << ans) - 1;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    vis[2 * i - 1] = vis[2 * i] = 0;
    int u = (a[i * 2 - 1] &= st), v = (a[i * 2] &= st);
    q[u].push_back(2 * i - 1);
    q[v].push_back(2 * i);
  }
  go(1);
  for (int now : p) printf("%d ", now);
}
