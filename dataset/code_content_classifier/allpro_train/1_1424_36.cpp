#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e3 + 5;
int n, k, dp[N][N], lmao[N][N];
string s;
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> k;
  cin >> s;
  s = "+" + s;
  dp[0][0] = 1;
  lmao[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int val = 26 - (s[i] - 96);
      dp[i][j] =
          ((1ll * dp[i][j] + 1ll * dp[i - 1][j] * (s[i] - 96) % mod)) % mod;
      int l = i;
      while ((n - i + 1) * (i - l + 1) <= j && l >= 1) {
        dp[i][j] =
            (1ll * dp[i][j] +
             (1ll * lmao[l - 1][j - (n - i + 1) * (i - l + 1)] * val) % mod) %
            mod;
        l--;
      }
      lmao[i][j] = (dp[i][j] - dp[i - 1][j]) % mod;
      lmao[i][j] = (lmao[i][j] + mod) % mod;
    }
  }
  cout << dp[n][k];
}
