#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
int fst[(400000 + 10)], vv[(800000 + 10)], nxt[(800000 + 10)], e;
void init() {
  memset(fst, -1, sizeof fst);
  e = 0;
}
void add(int u, int v) { vv[e] = v, nxt[e] = fst[u], fst[u] = e++; }
int dis[(400000 + 10)];
void dfs(int u, int p) {
  dis[u] = dis[p] + 1;
  for (int i = fst[u]; ~i; i = nxt[i]) {
    int v = vv[i];
    if (v == p) continue;
    dfs(v, u);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int u, v;
  init();
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  int mx = 0;
  for (int i = 1; i <= n; ++i)
    if (dis[i] > mx) u = i, mx = dis[i];
  dfs(u, 0);
  mx = 0;
  for (int i = 1; i <= n; ++i)
    if (dis[i] > mx) mx = dis[i];
  printf("%d\n", mx - 1);
}
