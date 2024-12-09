#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
bool mp[maxn][maxn];
int cnt = 0, n, vis[maxn];
char s[maxn];
bool dfs(int u, int pre) {
  vis[u] = 1;
  for (int i = 1; i <= n; i++) {
    if (mp[u][i]) {
      if (pre != -1 && mp[i][pre]) {
        printf("%d %d %d\n", pre, u, i);
        return true;
      }
      if (!vis[i] && dfs(i, u)) return true;
    }
  }
  return false;
}
int main() {
  memset(mp, 0, sizeof(mp));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++)
      if (s[j] == '1') mp[i][j] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i] && dfs(i, -1)) {
      return 0;
    }
  printf("-1\n");
}
