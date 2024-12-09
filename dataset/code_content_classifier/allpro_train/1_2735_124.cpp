#include <bits/stdc++.h>
template <class _Tp = int>
_Tp read() {
  _Tp w = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) w = (w << 3) + (w << 1) + (ch ^ 48), ch = getchar();
  return f ? -w : w;
}
const int kMaxN = 5e2 + 5;
int n, m;
std::bitset<kMaxN> dp[65][2][kMaxN], can_reach, hold;
int main() {
  n = read(), m = read();
  for (int i = 1, u, v, w; i <= m; i++) {
    u = read(), v = read(), w = read();
    dp[0][w][u][v] = true;
  }
  for (int i = 1; i <= 63; i++) {
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) {
        if (dp[i - 1][0][j][k]) dp[i][0][j] |= dp[i - 1][1][k];
        if (dp[i - 1][1][j][k]) dp[i][1][j] |= dp[i - 1][0][k];
      }
  }
  long long ans = 0, stats = 0;
  can_reach[1] = true;
  for (int i = 63; i >= 0; i--) {
    hold.reset();
    for (int j = 1; j <= n; j++)
      if (can_reach[j]) hold |= dp[i][stats][j];
    if (hold.count()) {
      stats ^= 1;
      can_reach = hold;
      ans += (1ll << i);
    }
  }
  if (ans > 1e18) ans = -1;
  printf("%lld\n", ans);
}
