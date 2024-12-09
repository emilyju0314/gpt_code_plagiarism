#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 7;
const long long MOD = 1e9 + 7;
int dp[MAXN];
int a[MAXN];
int main() {
  memset(dp, 0, sizeof(dp));
  int n, ans = -1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], dp[a[i]] = dp[a[i] - 1] + 1;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
  cout << n - ans << endl;
  return 0;
}
