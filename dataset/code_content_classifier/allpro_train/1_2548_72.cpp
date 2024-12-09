#include <bits/stdc++.h>
inline void read(int& r) {
  register char c;
  r = 0;
  do c = getchar();
  while (c < '0' || c > '9');
  do r = r * 10 + c - '0', c = getchar();
  while (c >= '0' && c <= '9');
}
std::pair<int, int> a[100001];
int dp[2][777], l;
int main() {
  int n, m, h, r, x, y, ans = 0;
  read(n), read(m);
  h = (n < sqrt(m * 6) ? n : sqrt(m * 6)), r = n - h;
  while (m--) {
    read(x), read(y);
    if (x <= r)
      ans += 3;
    else
      a[l++] = std::pair<int, int>(y, x);
  }
  bool cur = true, nxt = false;
  int cnt, tmp, p = 0, i, j;
  std::sort(a, a + l);
  dp[0][0] = dp[1][0] = 1048476;
  for (i = 1; i < h; i++) dp[0][i] = 1048576;
  for (i = 1; i <= n; i++) {
    cur ^= 1, nxt ^= 1, cnt = 0;
    tmp = dp[cur][h] + h * (h + 1) / 2 + 2;
    for (j = 1; j <= h; j++) {
      dp[nxt][j] = (dp[cur][j - 1] < tmp ? dp[cur][j - 1] : tmp) + cnt;
      dp[nxt][j] = (dp[nxt][j - 1] < dp[nxt][j] ? dp[nxt][j - 1] : dp[nxt][j]);
      if (a[p] == std::pair<int, int>(i, r + j)) p++, cnt += 3;
      tmp -= h - j + 1;
    }
    dp[nxt][h] =
        (dp[nxt][h] < dp[cur][h] + cnt ? dp[nxt][h] : dp[cur][h] + cnt);
  }
  printf("%d\n", dp[nxt][h] + ans);
}
