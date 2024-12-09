#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to;
  int used;
};
edge e[600100];
vector<vector<int> > g;
int was[100100];
vector<int> top;
int sz;
void dfs1(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int i = (0); i < (g[v].size()); ++i) {
    int k = g[v][i];
    if (e[k ^ 1].used == 0) {
      e[k].used = 1;
      dfs1(e[k].to);
    }
  }
}
void dfs2(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int i = (0); i < (g[v].size()); ++i) {
    int k = g[v][i];
    if (e[k].used) dfs2(e[k].to);
  }
  top.push_back(v);
}
void dfs3(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int i = (0); i < (g[v].size()); ++i) {
    int k = g[v][i];
    if (e[k].used == 0) dfs3(e[k].to);
  }
}
int main() {
  sz = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  for (int i = (0); i < (m); ++i) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    edge e1 = {v2, 0};
    g[v1].push_back(sz);
    e[sz++] = e1;
    e1.to = v1;
    g[v2].push_back(sz);
    e[sz++] = e1;
  }
  dfs1(0);
  memset(was, 0, sizeof(was));
  for (int i = (0); i < (n); ++i)
    if (was[i] == 0) dfs2(i);
  memset(was, 0, sizeof(was));
  int cnt = 0;
  for (int i = (int)top.size() - 1; i >= 0; --i) {
    int v = top[i];
    if (was[v] == 0) {
      cnt++;
      dfs3(v);
    }
  }
  if (cnt > 1) {
    printf("0\n");
    return 0;
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (g[i].size()); ++j)
      if (e[g[i][j]].used) printf("%d %d\n", i + 1, e[g[i][j]].to + 1);
  return 0;
}
