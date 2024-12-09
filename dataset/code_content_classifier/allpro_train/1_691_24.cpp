#include <bits/stdc++.h>
using namespace std;
const int MAXN = 700 + 5;
int dp[2][MAXN][MAXN];
int gcd[MAXN][MAXN];
int a[MAXN], n;
int calc_gcd(int x, int y) { return (x % y) ? calc_gcd(y, x % y) : y; }
int s_dp(int op, int l, int r) {
  if (dp[op][l][r] != -1) return dp[op][l][r];
  for (int i = l; i <= r; i++)
    if (((op == 0) && ((r == n - 1) || (gcd[i][r + 1] > 1))) ||
        ((op == 1) && ((l == 0) || (gcd[l - 1][i] > 1)))) {
      int left = (i == l) ? 1 : s_dp(0, l, i - 1);
      int right = (i == r) ? 1 : s_dp(1, i + 1, r);
      if (left && right) return dp[op][l][r] = 1;
    }
  return dp[op][l][r] = 0;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      gcd[i][j] = gcd[j][i] = calc_gcd(a[i], a[j]);
  for (int i = 0; i < n; i++) {
    int left = (i == 0) ? 1 : s_dp(0, 0, i - 1);
    int right = (i == n - 1) ? 1 : s_dp(1, i + 1, n - 1);
    if (left && right) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
