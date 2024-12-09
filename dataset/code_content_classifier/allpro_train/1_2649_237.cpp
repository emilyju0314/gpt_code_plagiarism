#include <bits/stdc++.h>
using namespace std;
const int Len = 1e3 + 5;
vector<int> pos[15];
int dp[Len][1 << 10], num[15], n, color[Len], Ans = -1;
int check(int mid) {
  memset(num, 0, sizeof num);
  memset(dp, -1, sizeof dp);
  dp[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << 8); j++) {
      if (dp[i][j] == -1) continue;
      for (int k = 0; k < 8; k++) {
        if (j & (1 << k)) continue;
        int idx = num[k + 1] + mid - 1;
        if (idx >= pos[k + 1].size()) continue;
        dp[pos[k + 1][idx]][j ^ (1 << k)] =
            max(dp[i][j], dp[pos[k + 1][idx]][j ^ (1 << k)]);
        if (idx + 1 >= pos[k + 1].size()) continue;
        dp[pos[k + 1][idx + 1]][j ^ (1 << k)] =
            max(dp[pos[k + 1][idx + 1]][j ^ (1 << k)], dp[i][j] + 1);
      }
    }
    num[color[i]]++;
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i][(1 << 8) - 1]);
  if (ans == -1) return -1;
  return ans * (mid + 1) + (8 - ans) * mid;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &color[i]);
    pos[color[i]].push_back(i);
  }
  int l = 1, r = n / 8;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid) != -1)
      l = mid;
    else
      r = mid;
  }
  Ans = max(check(l), check(r));
  if (Ans == -1) {
    Ans = 0;
    for (int i = 1; i <= 8; i++)
      if (pos[i].size()) Ans++;
  }
  printf("%d\n", Ans);
  return 0;
}
