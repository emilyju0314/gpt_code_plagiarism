#include <bits/stdc++.h>
using namespace std;
long long dp[600][600], n, m, mod;
long long rec(int i, int x, int y) {
  if (i == n) {
    if (x == 0 && y == 0)
      return 1;
    else
      return 0;
  }
  if (dp[x][y] != -1) return dp[x][y];
  long long ans = 0;
  if (x > 1) ans += rec(i + 1, x - 2, y + 2) * (x * (x - 1)) / 2;
  ans = ans % mod;
  if (x >= 1 && y >= 1) ans += rec(i + 1, x - 1, y) * (x * y);
  ans = ans % mod;
  if (y > 1) ans += rec(i + 1, x, y - 2) * (y * (y - 1)) / 2;
  ans = ans % mod;
  return dp[x][y] = ans % mod;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> mod;
  string s[m];
  for (int i = 0; i < m; i++) cin >> s[i];
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) cnt += (s[j][i] - '0');
    if (cnt == 1) y++;
    if (cnt == 0) x++;
  }
  cout << rec(m, x, y);
  return 0;
}
