#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = 1e9 + 10;
int n;
int a[maxn];
int dp[4100][4100];
int Next[4100][4100];
int R[maxn];
int id[maxn];
int dfs(int x, int y) {
  int &res = dp[x][y];
  if (~res) return res;
  res = 1;
  int z = Next[x][y];
  if (z == -1) return res;
  return res = dfs(y, z) + 1;
}
void Init() {
  memset(id, -1, sizeof(id));
  for (int i = n; i >= 1; i--) {
    if (id[a[i]] == -1) {
      id[a[i]] = i;
      for (int j = i + 1; j <= n; j++) Next[i][j] = -1;
    } else {
      R[i] = id[a[i]];
      id[a[i]] = i;
      int k = R[i];
      for (int j = i + 1; j <= n; j++) {
        while (R[k] != k && k <= j) k = R[k];
        if (k <= j)
          Next[i][j] = -1;
        else
          Next[i][j] = k;
      }
    }
  }
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    Init();
    int ans = 2;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans = max(ans, dfs(i, j) + 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
