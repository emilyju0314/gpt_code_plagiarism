#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma target("sse", "sse1")
using namespace std;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int n, t[100000], dp[100000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--)
    if (t[i] == t[i + 1])
      dp[i] = dp[i + 1] + 1;
    else
      dp[i] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i + dp[i];
    if (dp[j] >= dp[i]) ans = max(ans, dp[i] * 2);
  }
  cout << ans;
  return 0;
}
