#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k;
vector<pair<int, int> > g[N];
int st[N][10][10];
int a[10][10][10][10];
int ans;
int t[10];
void dfs(int u) {
  if (u == k + 1) {
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k; j++) {
        if (a[i][t[i]][j][t[j]] == 0) return;
      }
    }
    ans++;
    return;
  }
  for (int i = 1; i <= u; i++) {
    t[u] = i;
    dfs(u + 1);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back({w, v});
  }
  for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      st[g[i][j].second][g[i].size()][j + 1]++;
    }
  }
  memset(a, 1, sizeof(a));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      if (st[g[i][j].second][g[i].size()][j + 1]) {
        for (int x = 1; x <= k; x++) {
          for (int y = 1; y <= k; y++) {
            if (st[g[i][j].second][x][y]) {
              if (x ^ g[i].size()) {
                a[g[i].size()][j + 1][x][y] = 0;
              } else if (st[g[i][j].second][x][y] > 1) {
                a[g[i].size()][j + 1][x][y] = 0;
              }
            }
          }
        }
      }
    }
  }
  ans = 0;
  dfs(1);
  cout << ans << '\n';
}
