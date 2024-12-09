#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int d[N][N], vis[N];
long long ans[N];
int main() {
  int n, x[N];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &d[i][j]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    x[i]--;
  }
  reverse(x, x + n);
  for (int k = 0; k < n; k++) {
    vis[x[k]] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (vis[i] && vis[j]) ans[n - k - 1] += d[i][j];
  }
  for (int i = 0; i < n; i++) printf("%I64d ", ans[i]);
  return 0;
}
