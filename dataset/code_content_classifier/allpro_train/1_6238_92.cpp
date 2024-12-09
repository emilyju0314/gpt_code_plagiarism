#include <bits/stdc++.h>
#pragma GCC optimize(3)
const double Pi = 3.14159265;
const int N = 5e6 + 10;
const int M = 1e5 + 10;
const unsigned long long base = 163;
const int INF = 0x3f3f3f3f;
const int mod = 192600817;
const double eps = 1e-10;
const double pi = acos(-1);
using namespace std;
int n, m, d;
char s[M][52];
int ans[N];
vector<int> E[N];
int u[M], v[M];
void add(int u, int v) { E[u].push_back(v); }
int sta[N], stasize = 0;
int low[N], dfn[N];
int com[N], sz = 0;
int vis[N];
int step = 0;
pair<int, int> getp(int x) { return pair<int, int>{x / d + 1, x % d}; }
pair<int, int> p;
void dfs(int u) {
  dfn[u] = low[u] = ++step;
  vis[u] = 1;
  sta[stasize++] = u;
  for (auto v : E[u]) {
    if (!vis[v])
      dfs(v), low[u] = min(low[u], low[v]);
    else if (vis[v] == 1)
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    int k;
    sz++;
    do {
      k = sta[--stasize];
      p = getp(k);
      vis[k] = 2;
      com[k] = sz;
    } while (k != u);
  }
}
void tarjan() { dfs(0); }
int getid(int x, int t) { return (x - 1) * d + t; }
void sma() {
  for (int i = 0; i < n * d; i++) E[i].clear(), E[i].shrink_to_fit();
  int z, p;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < d; ++j) {
      z = getid(u[i], j), p = getid(v[i], (j + 1) % d);
      if (com[z] == com[p] || !com[z] || !com[p]) continue;
      add(com[z], com[p]);
    }
  }
  unordered_set<int> ss;
  for (int i = 1; i <= n; i++) {
    ss.clear();
    for (int j = 0; j < d; j++) {
      if (s[i][j] != '1') continue;
      int c = com[getid(i, j)];
      if (!c) continue;
      ss.insert(c);
    }
    for (auto x : ss) ans[x]++;
  }
}
int DFS(int u) {
  if (vis[u] != -1) return vis[u];
  vis[u] = 0;
  for (auto v : E[u]) {
    vis[u] = max(vis[u], DFS(v));
  }
  vis[u] += ans[u];
  return vis[u];
}
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    for (int j = 0; j < d; ++j) {
      add(getid(u[i], j), getid(v[i], (j + 1) % d));
    }
  }
  for (int i = 1; i <= n; ++i) scanf("%s", s[i]);
  tarjan();
  sma();
  memset(vis, -1, sizeof(vis));
  printf("%d\n", DFS(com[0]));
  return 0;
}
