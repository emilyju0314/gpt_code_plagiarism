#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &it : a) cin >> it;
  ;
  long long dp[n + 5][5];
  memset(dp, 0, sizeof(dp));
  dp[0][1] = abs(a[0] - a[1]);
  long long ans = dp[0][1];
  for (int i = 1; i < n - 1; i++) {
    dp[i][1] = max(dp[i - 1][0] + abs(a[i] - a[i + 1]), abs(a[i] - a[i + 1]));
    dp[i][0] = dp[i - 1][1] - abs(a[i] - a[i + 1]);
    ans = max({ans, dp[i][1], dp[i][0]});
  }
  cout << ans << '\n';
}
int main() { solve(); }
