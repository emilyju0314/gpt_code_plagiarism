#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int maxm = 1000001;
int dp[maxn * maxn][10], mp[maxn][maxn];
int used[maxn][maxn];
int a[10], b[10];
char str[maxm];
int n, m, q;
vector<int> start;
int id(int x, int y) { return x * m + y; }
void dfs(int x, int y) {
  if (used[x][y]) return;
  used[x][y] = 1;
  int u = id(x, y);
  int k = mp[x][y];
  dp[u][k] = u;
  int nx = x + a[k], ny = y + b[k];
  if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
    int v = id(nx, ny);
    dfs(nx, ny);
    for (int i = 0; i < 10; i++) {
      if (i != k) {
        dp[u][i] = dp[v][i];
      }
    }
  }
}
bool check(char *str) {
  int len = strlen(str);
  for (auto s : start) {
    int u = s;
    for (int i = 0; i < len; i++) {
      int c = str[i] - '0';
      u = dp[u][c];
      if (u == -1) break;
    }
    if (u != -1) return true;
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      mp[i][j] = c - '0';
    }
  }
  for (int i = 0; i < 10; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  memset(used, 0, sizeof(used));
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        start.push_back(id(i, j));
        dfs(i, j);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%s", str);
    if (check(str)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
