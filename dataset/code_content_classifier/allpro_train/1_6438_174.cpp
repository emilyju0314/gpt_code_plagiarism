#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) ans = (ans << 3) + (ans << 1) + (c ^ 48), c = getchar();
  return ans;
}
int a[4005][4005], dp[4005][4005], p[4005][4005];
inline int calc(int i, int j) { return a[j][j] - a[i][j] - a[j][i] + a[i][i]; }
int main() {
  int n, m;
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = read() + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) p[i][1] = 0, dp[i][1] = calc(0, i);
  for (int j = 2; j <= m; j++) {
    p[n + 1][j] = n;
    for (int i = n; i >= 1; i--)
      for (int k = p[i][j - 1]; k <= p[i + 1][j]; k++)
        if (dp[k][j - 1] + calc(k, i) < dp[i][j]) {
          p[i][j] = k;
          dp[i][j] = dp[k][j - 1] + calc(k, i);
        }
  }
  cout << (dp[n][m] >> 1);
  return 0;
}
