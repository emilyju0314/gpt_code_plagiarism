#include <bits/stdc++.h>
using namespace std;
vector<long long> G[35];
long long f[35][10];
long long dx[10] = {0, 1, 0, -1};
long long dy[10] = {1, 0, -1, 0};
bool vis[35];
void dfs(long long z, long long x, long long y, long long len, long long jj) {
  f[z][0] = x;
  f[z][1] = y;
  long long i, j = 0, zz, xx, yy;
  for (i = 0; i < G[z].size(); i++) {
    zz = G[z][i];
    if (vis[zz]) {
      vis[zz] = false;
      if (j == jj) j++;
      xx = x + dx[j] * len;
      yy = y + dy[j] * len;
      dfs(zz, xx, yy, len / 2, (j + 2) % 4);
      j++;
    }
  }
}
int main() {
  long long n;
  while (scanf("%I64d", &n) != EOF) {
    long long i, j, zt = 0, a, b;
    for (i = 1; i <= n; i++) G[i].clear();
    for (i = 0; i < n - 1; i++) {
      scanf("%I64d %I64d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
      if (G[a].size() > 4) zt = 1;
      if (G[b].size() > 4) zt = 1;
    }
    if (zt)
      printf("NO\n");
    else {
      printf("YES\n");
      memset(vis, true, sizeof(vis));
      vis[1] = false;
      dfs(1, 0, 0, 1 << 30, -1);
      for (i = 1; i <= n; i++) {
        printf("%I64d %I64d\n", f[i][0], f[i][1]);
      }
    }
  }
}
