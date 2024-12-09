#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long solve(long long* dp, string& s, long long i) {
  if (i == s.size()) {
    return 1;
  }
  if (dp[i] != -1) return dp[i];
  if (i < s.size() - 1) {
    string t = s.substr(i, 2);
    if (t == "uu" || t == "nn") {
      dp[i] = (solve(dp, s, i + 1) + solve(dp, s, i + 2)) % MOD;
    } else {
      dp[i] = solve(dp, s, i + 1);
    }
  } else {
    dp[i] = solve(dp, s, i + 1);
  }
  return dp[i];
}
int32_t main() {
  string str;
  cin >> str;
  long long n = str.size();
  long long dp[n + 1];
  for (long long i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  for (char i : str) {
    if (i == 'w' || i == 'm') {
      cout << 0;
      return 0;
    }
  }
  cout << solve(dp, str, 0) << endl;
}
