#include <bits/stdc++.h>
using namespace std;
int e[25][25];
int vis[50];
int n, k, t, cnt;
void dfs(int pos, int sum, int mid) {
  if (pos > n) {
    cnt++;
    return;
  }
  dfs(pos + 1, sum, mid);
  for (int i = 1; i <= n && cnt < t; i++) {
    if (!vis[i] && e[pos][i] && sum + e[pos][i] <= mid) {
      vis[i] = 1;
      dfs(pos + 1, sum + e[pos][i], mid);
      vis[i] = 0;
    }
  }
}
int main() {
  int x, y, z;
  scanf("%d %d %d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    scanf("%d %d %d", &x, &y, &z);
    e[x][y] = z;
  }
  int l = 0, r = n * 1000, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    dfs(1, 0, mid);
    if (cnt >= t) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
