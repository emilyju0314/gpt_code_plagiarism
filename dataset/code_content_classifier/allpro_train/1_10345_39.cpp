#include <bits/stdc++.h>
using namespace std;
long long dp[55][10];
char s[60];
int main() {
  scanf("%s", s);
  int n, m, j, i;
  n = strlen(s);
  for (i = 0; i < 10; i++) dp[0][i] = 1;
  for (i = 1; i < n; i++) {
    int t = s[i] - '0';
    for (j = 0; j < 10; j++) {
      int r = (t + j) / 2;
      int c = (t + j + 1) / 2;
      dp[i][r] += dp[i - 1][j];
      if (r != c) dp[i][c] += dp[i - 1][j];
    }
  }
  long long flag = 0;
  for (i = 1; i < n; i++) {
    int t = s[i] - '0';
    int r = s[i - 1] - '0';
    if (t != (t + r) / 2 && t != (t + r + 1) / 2) {
      flag = 1;
      break;
    }
  }
  long long ans;
  ans = -1 + flag;
  for (i = 0; i < 10; i++) ans += dp[n - 1][i];
  cout << ans << endl;
  return 0;
}
