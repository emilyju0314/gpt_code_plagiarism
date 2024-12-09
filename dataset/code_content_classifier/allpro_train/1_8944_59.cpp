#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[2][N];
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int k;
  cin >> k;
  if (k == 0) {
    if (s1 == s2)
      puts("1");
    else
      puts("0");
    return 0;
  }
  int n = s1.length();
  memset((dp), (0), sizeof(dp));
  dp[0][1] = 1;
  int o = 0;
  for (int i = 1; i <= k; i++) {
    o ^= 1;
    memset((dp[o]), (0), sizeof(dp[o]));
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += dp[o ^ 1][j];
      if (sum >= INF) sum -= INF;
    }
    for (int j = 1; j <= n; j++) {
      int &tmp = dp[o][j] = sum - dp[o ^ 1][j];
      if (tmp < 0) tmp += INF;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s1.substr(i - 1) + s1.substr(0, i - 1) == s2) {
      ans += dp[o][i];
    }
  }
  printf("%lld\n", ans % INF);
  return 0;
}
