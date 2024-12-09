#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int dp[100005];
  for (int i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      dp[i] = 1;
    else
      dp[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    dp[i] += dp[i - 1];
  }
  int mi = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      int temp = n - dp[n - 1];
      mi = min(temp, mi);
    } else {
      int temp = (n - i) - (dp[n - 1] - dp[i - 1]);
      temp += dp[i - 1];
      mi = min(temp, mi);
    }
  }
  mi = min(mi, dp[n - 1]);
  cout << mi;
  return 0;
}
