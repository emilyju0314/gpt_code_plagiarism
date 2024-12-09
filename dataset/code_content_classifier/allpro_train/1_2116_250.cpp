#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int p[1111];
long long dp[1111];
signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  dp[1] = 2;
  for (int i = 2; i <= n; i++) {
    dp[i] = 1;
    for (int j = p[i]; j < i; j++) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
    dp[i] = (dp[i] + 1) % MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[i]) % MOD;
  }
  cout << ans;
}
