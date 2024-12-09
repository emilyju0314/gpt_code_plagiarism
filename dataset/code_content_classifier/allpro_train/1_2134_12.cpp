#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 23;
vector<int> g[100000 + 23];
int p[100000 + 23][21];
int d[100000 + 23];
int vis[100000 + 23];
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v] == 0) {
      d[v] = d[u] + 1;
      p[v][0] = u;
      for (int j = 1; j <= 20; j++) {
        p[v][j] = p[p[v][j - 1]][j - 1];
      }
      dfs(v);
    }
  }
  return;
}
int f(int u, int v) {
  d[0] = -1;
  if (d[u] < d[v]) swap(u, v);
  if (d[u] != d[v]) {
    for (int i = 20; i >= 0; i--) {
      if (d[p[u][i]] >= d[v]) {
        u = p[u][i];
      }
    }
  }
  if (u == v) return v;
  for (int j = 20; j >= 0; j--) {
    if (p[u][j] != p[v][j]) {
      u = p[u][j];
      v = p[v][j];
    }
  }
  return p[u][0];
}
int find(int x, int y, int z) {
  int xz = f(x, z);
  int yz = f(y, z);
  if (xz == yz) {
    int xy = f(x, y);
    return abs(d[xy] - d[xz]) + 1 + abs(d[xz] - d[z]);
  } else {
    if (d[xz] > d[yz]) {
      return abs(d[z] - d[xz]) + 1;
    } else {
      return abs(d[z] - d[yz]) + 1;
    }
  }
}
int main() {
  int n;
  cin >> n;
  int q;
  cin >> q;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    ans = max(ans, find(x, y, z));
    ans = max(ans, find(x, z, y));
    ans = max(ans, find(y, z, x));
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}
