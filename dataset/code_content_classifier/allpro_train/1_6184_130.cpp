#include <bits/stdc++.h>
long long int const MOD = 1000000007;
long long int const N = 1000005;
long long int const LN = 20;
long long int const inf = 8e18;
using namespace std;
long long int n, m, a[N];
long long int dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  dp[1] = 0;
  for (long long int i = 2; i <= n; i++) {
    if (a[i - 1] >= a[i] && a[i - 1] >= a[i - 2])
      dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1] - a[i]);
    if (a[i - 1] <= a[i] && a[i - 1] <= a[i - 2])
      dp[i] = max(dp[i - 1], dp[i - 2] - a[i - 1] + a[i]);
    if (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])
      dp[i] = dp[i - 1] + a[i - 1] - a[i];
    if (a[i - 2] <= a[i - 1] && a[i - 1] <= a[i])
      dp[i] = dp[i - 1] - a[i - 1] + a[i];
  }
  cout << dp[n];
  return 0;
}
