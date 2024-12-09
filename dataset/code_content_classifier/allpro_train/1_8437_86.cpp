#include <bits/stdc++.h>
using namespace std;
int n;
int c[4005], r[4005];
int a[4005], n0;
vector<int> v[4005];
int f[4005][4005], g[4005][4005], h[4005][4005];
void dfs(int i, int j) {
  if (g[i][j]) printf("%d ", g[i][j]);
  if (i == h[i][j] || j == h[i][j]) return;
  dfs(i, h[i][j]), dfs(h[i][j], j);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &c[i], &r[i]), a[++n0] = c[i] + r[i], a[++n0] = c[i] - r[i];
  sort(a + 1, a + 1 + n0);
  n0 = unique(a + 1, a + 1 + n0) - (a + 1);
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(a + 1, a + 1 + n0, c[i] - r[i]) - a,
        y = lower_bound(a + 1, a + 1 + n0, c[i] + r[i]) - a;
    v[x].push_back(y), g[x][y] = i;
  }
  for (int i = 1; i <= n0; i++) sort(v[i].begin(), v[i].end());
  for (int l = 1; l <= n0; l++) {
    for (int i = 1; i + l - 1 <= n0; i++) {
      int sum = f[i + 1][i + l - 1] + (g[i][i + l - 1] > 0);
      h[i][i + l - 1] = i + 1;
      for (int j = 0; j < v[i].size() && v[i][j] <= i + l - 1; j++) {
        if (sum <
            f[i][v[i][j]] + f[v[i][j]][i + l - 1] + (g[i][i + l - 1] > 0)) {
          sum = f[i][v[i][j]] + f[v[i][j]][i + l - 1] + (g[i][i + l - 1] > 0);
          h[i][i + l - 1] = v[i][j];
        }
      }
      f[i][i + l - 1] = sum;
    }
  }
  printf("%d\n", f[1][n0]);
  dfs(1, n0);
}
