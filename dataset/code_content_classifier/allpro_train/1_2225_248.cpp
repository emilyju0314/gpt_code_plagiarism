#include <bits/stdc++.h>
using namespace std;
stack<int> ans, res;
int dp[23][23], n, m;
void dfs(int x) {
  if (res.size() >= ans.size()) return;
  if (x == n) {
    for (int i = 0; i < n; i++)
      if (dp[x][i] != (1 << n) - 1) return;
    ans = res;
    return;
  }
  memcpy(dp[x + 1], dp[x], sizeof(dp[x]));
  dfs(x + 1);
  for (int i = 0; i < n; i++)
    if (dp[x][x] & (1 << i)) dp[x + 1][i] |= dp[x][x];
  res.push(x + 1);
  dfs(x + 1);
  res.pop();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    ans.push(1);
    dp[0][i - 1] = (1 << i - 1);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    dp[0][--x] |= (1 << --y);
    dp[0][y] |= (1 << x);
  }
  dfs(0);
  printf("%d\n", ans.size());
  while (!ans.empty()) {
    printf("%d\n", ans.top());
    ans.pop();
  }
  return 0;
}
