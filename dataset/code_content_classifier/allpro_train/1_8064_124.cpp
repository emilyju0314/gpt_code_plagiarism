#include <bits/stdc++.h>
using namespace std;
long long int dp[200005], f[200005];
string s;
int main() {
  int n, k, i, j, x;
  cin >> n >> k;
  cin >> s;
  f[n + 1] = n + n + 1;
  for (i = n; i >= 1; i--) {
    if (s[i - 1] == '1')
      f[i] = i;
    else
      f[i] = f[i + 1];
  }
  for (i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + i;
    x = f[max(1, i - k)];
    if (x <= i + k) dp[i] = min(dp[i], dp[max(1, x - k) - 1] + x);
  }
  cout << dp[n];
  return 0;
}
