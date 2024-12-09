#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int g[50][50];
int MAX;
int f[50];
bool dfs(int *adj, int pos, int cnt) {
  int tmp[50];
  if (pos == 0) {
    if (cnt > MAX) {
      MAX = cnt;
      return true;
    }
    return false;
  }
  int id = 0;
  for (int i = 0; i < pos; i++) {
    if (cnt + pos - i <= MAX) return false;
    if (cnt + f[adj[i]] <= MAX) return false;
    id = 0;
    for (int j = i + 1; j < pos; j++)
      if (g[adj[i]][adj[j]]) tmp[id++] = adj[j];
    if (dfs(tmp, id, cnt + 1)) return true;
  }
  return false;
}
int solve(int n) {
  MAX = 0;
  int pos = 0;
  int adj[50];
  for (int i = n - 1; i >= 0; i--) {
    pos = 0;
    for (int j = i + 1; j < n; j++) {
      if (g[i][j]) adj[pos++] = j;
    }
    dfs(adj, pos, 1);
    f[i] = MAX;
  }
  return MAX;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
  int t = solve(n);
  double ans = 0.5 * k * k * (t - 1) / t;
  printf("%.8lf\n", ans);
  return 0;
}
