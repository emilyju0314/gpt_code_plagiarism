#include <bits/stdc++.h>
using namespace std;
int n, m;
char data[200];
char s[1010][1010];
int dp[1010][1010];
struct arr {
  int x, y;
};
arr huong[4] = {-1, 0, 0, 1, 1, 0, 0, -1};
void init() {
  data['D'] = 0;
  data['I'] = 1;
  data['M'] = 2;
  data['A'] = 3;
}
bool out_table(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) return true;
  return false;
}
bool can_move(int x, int y) {
  int i, j, xt, yt;
  for (i = 0; i < 4; i++) {
    xt = x + huong[i].x;
    yt = y + huong[i].y;
    if (!out_table(xt, yt) && (data[s[x][y]] + 1) % 4 == data[s[xt][yt]])
      return true;
  }
  return false;
}
void dfs(int x, int y) {
  int i, j, xt, yt, maxval;
  if (dp[x][y] != -1) return;
  dp[x][y] = -2;
  maxval = 0;
  for (i = 0; i < 4; i++) {
    xt = x + huong[i].x;
    yt = y + huong[i].y;
    if (!out_table(xt, yt) && (data[s[x][y]] + 1) % 4 == data[s[xt][yt]]) {
      dfs(xt, yt);
      if (dp[xt][yt] < 0)
        return;
      else
        maxval = max(maxval, dp[xt][yt]);
    }
  }
  dp[x][y] = maxval + 1;
}
void solve() {
  int i, j, ans;
  memset(dp, -1, sizeof(dp));
  ans = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (s[i][j] == 'D' && dp[i][j] == -1) {
        dfs(i, j);
        if (dp[i][j] == -2) {
          printf("Poor Inna!\n");
          return;
        }
        ans = max(ans, dp[i][j]);
      }
  ans /= 4;
  if (ans == 0)
    printf("Poor Dima!\n");
  else
    printf("%d\n", ans);
}
void input() {
  int i;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", &s[i]);
  solve();
}
int main() {
  init();
  input();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
