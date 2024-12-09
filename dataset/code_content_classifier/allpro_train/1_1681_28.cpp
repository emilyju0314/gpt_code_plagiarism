#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
string a[N];
int dp[1 << 24];
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int mask = 0;
    for (int j = 0; j < 3; ++j) mask |= (1 << (a[i][j] - 'a'));
    dp[mask]++;
  }
  for (int j = 0; j < 24; ++j) {
    for (int i = 0; i < 1 << 24; ++i) {
      if ((i >> j) & 1) dp[i] += dp[i ^ (1 << j)];
    }
  }
  for (int i = 0; i < 1 << 24; ++i) {
    ans ^= ((n - dp[i]) * (n - dp[i]));
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
