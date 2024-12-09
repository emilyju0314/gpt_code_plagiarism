#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int c[103][103];
long long int dp[103][103];
long a[100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= 9; i++) cin >> a[i];
  for (int i = a[9]; i <= n; i++) dp[i][9] = 1;
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    c[i][i] = 1;
    c[i][0] = 1;
  }
  for (int i = 8; i >= 1; i--) {
    for (int j = a[i]; j <= n; j++) {
      for (int k = a[i]; k <= j; k++) {
        long long int h = dp[j - k][i + 1] * c[j][k];
        h = h % mod;
        dp[j][i] = dp[j][i] + h;
        dp[j][i] = dp[j][i] % mod;
      }
    }
  }
  for (int j = a[0] + 1; j <= n; j++) {
    for (int k = a[0]; k < j; k++) {
      long long int h = dp[j - k][1] * c[j - 1][k];
      h = h % mod;
      dp[j][0] = dp[j][0] + h;
      dp[j][0] = dp[j][0] % mod;
    }
  }
  long long ans = 0;
  for (long i = 0; i <= n; i++) {
    ans = ans + dp[i][0];
    ans = ans % mod;
  }
  cout << ans << endl;
}
