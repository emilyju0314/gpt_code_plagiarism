#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
void sIO();
int n, m, x, y, a[111111];
vector<vector<int> > g, gr;
bool w1[111111], w2[111111], w[111111];
void dfs1(int v) {
  w1[v] = true;
  w[v] = true;
  int kk = (int)g[v].size(), tto;
  for (int i = 0; i < kk; ++i) {
    tto = g[v][i];
    if (!w[tto]) dfs1(tto);
  }
}
void dfs2(int v) {
  w2[v] = true;
  w[v] = true;
  if (a[v] == 1) return;
  int kk = (int)gr[v].size(), tto;
  for (int i = 0; i < kk; ++i) {
    tto = gr[v][i];
    if (!w[tto]) dfs2(tto);
  }
}
int main() {
  sIO();
  scanf("%d %d", &n, &m);
  g.resize(n + 5);
  gr.resize(n + 5);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    gr[y].push_back(x);
  }
  memset(w1, 0, sizeof(w1));
  memset(w2, 0, sizeof(w2));
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= n; ++i)
    if (a[i] == 1) dfs1(i);
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= n; ++i)
    if (a[i] == 2) dfs2(i);
  for (int i = 1; i <= n; ++i) printf("%d ", w1[i] && w2[i]);
  return 0;
}
void sIO() {}
