#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int g[N], num[N], low[N], lv[N], p[N][18], n, m, k, x, y;
vector<int> a[N], b[N];
stack<int> s;
void DFS(int par, int x) {
  static int c = 0;
  num[x] = low[x] = ++c;
  p[x][0] = par;
  s.push(x);
  for (auto y : a[x])
    if (y != par) {
      if (!num[y]) {
        DFS(x, y);
        low[x] = min(low[x], low[y]);
      } else
        low[x] = min(low[x], num[y]);
    }
  if (low[x] == num[x]) {
    g[x] = ++m;
    while (s.top() != x) {
      g[s.top()] = m;
      s.pop();
    }
    s.pop();
  }
}
void DFS2(int x) {
  lv[x] = lv[p[x][0]] + 1;
  for (auto y : b[x]) {
    p[y][0] = x;
    DFS2(y);
  }
}
int LCA(int x, int y) {
  if (lv[x] < lv[y]) swap(x, y);
  int D = lv[x] - lv[y];
  for (auto i = 0; i <= int(log2(m)); i++)
    if (D & (1 << i)) x = p[x][i];
  if (x == y) return x;
  for (auto i = int(log2(lv[x])); i >= 0; i--)
    if (p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
  return p[x][0];
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  m = 0;
  DFS(0, 1);
  for (auto i = 1; i <= n; i++)
    if (low[i] == num[i]) b[g[p[i][0]]].push_back(g[i]);
  queue<int> q;
  q.push(g[1]);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    lv[x] = lv[p[x][0]] + 1;
    for (auto y : b[x]) {
      p[y][0] = x;
      q.push(y);
    }
  }
  for (auto i = 1; i <= int(log2(m)); i++)
    for (auto j = 1; j <= m; j++) p[j][i] = p[p[j][i - 1]][i - 1];
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d", &x, &y);
    x = g[x], y = g[y];
    int z = LCA(x, y);
    printf("%d\n", lv[x] + lv[y] - 2 * lv[z]);
  }
}
