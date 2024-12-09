#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
unsigned long long dp[15][15];
void DP() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] == 0) continue;
      dp[i + 1][j + 1] += dp[i][j] * 2;
      dp[i + 1][j] += dp[i][j] * 8;
    }
  }
}
int slove(int n, int m) {
  int bit[20], len = 0;
  while (n) {
    bit[len++] = n % 10;
    n /= 10;
  }
  int cnt = 0, tot = 0;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 0; j < bit[i]; j++) {
      if (j == 4 || j == 7) {
        if (tot != m) cnt += dp[i][m - tot - 1];
      } else
        cnt += dp[i][m - tot];
    }
    if (bit[i] == 4 || bit[i] == 7) tot++;
    if (tot > m) break;
  }
  if (tot == m) cnt++;
  if (m == 0) cnt--;
  return cnt;
}
int n;
int cnt[10], t[10];
unsigned long long ans = 0;
void dfs(int idx, int now, int limit, unsigned long long ret) {
  if (idx == 6) {
    ans = (ans + ret) % 1000000007;
    return;
  }
  for (int i = 0; i < 10; i++) {
    if (i + now >= limit) break;
    if (t[i] == 0) continue;
    t[i]--;
    dfs(idx + 1, now + i, limit, ret * (t[i] + 1) % 1000000007);
    t[i]++;
  }
}
int main() {
  DP();
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < 10; i++) {
      cnt[i] = slove(n, i);
    }
    ans = 0;
    for (int i = 1; i < 10; i++) {
      if (cnt[i] == 0) continue;
      memcpy(t, cnt, sizeof(cnt));
      t[i]--;
      dfs(0, 0, i, cnt[i] % 1000000007);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
