#include <bits/stdc++.h>
using namespace std;
char s[5555], t[5555];
int dp[5555][5555];
const int e5 = 5555;
const int mod = (int)1e9 + 7;
int main(void) {
  gets(s);
  gets(t);
  for (int i = 0; i < e5; i++)
    for (int j = i; j < e5; j++) dp[i][j] = dp[j][i] = 0;
  int ans = 0;
  for (int i = 0; s[i]; i++)
    for (int j = 0; t[j]; j++) {
      dp[i][j + 1] += dp[i][j];
      dp[i][j + 1] %= mod;
      if (s[i] == t[j]) {
        dp[i][j]++;
        dp[i][j] %= mod;
        ans = (ans + dp[i][j]) % mod;
        dp[i + 1][j + 1] = dp[i][j];
      }
    }
  printf("%d", ans);
  return 0;
}
