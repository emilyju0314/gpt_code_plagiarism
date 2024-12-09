#include <bits/stdc++.h>
using namespace std;
const int maxp = 31;
const long double EPS = 1e-18;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
const int N = 3e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long d, mod;
    cin >> d >> mod;
    int bit[31] = {};
    bit[0] = 1;
    int sum = 1, i;
    for (i = 1; i < 31; i++) {
      bit[i] = bit[i - 1] * 2;
      sum += bit[i];
      if (sum > d) {
        bit[i] -= sum - d;
        break;
      }
    }
    {}
    for (i = 0; i < 31; i++) {
      bit[i] %= mod;
    }
    long long dp[31][31];
    long long ans = 0;
    for (i = 0; i < 31; i++) {
      long long sum = 0;
      if (i == 0) sum = 1;
      for (int j = 0; j < 31; j++) {
        dp[i][j] = (bit[j] * sum) % mod;
        ans = (ans + dp[i][j]) % mod;
        if (i > 0) sum = (sum + dp[i - 1][j]) % mod;
      }
    }
    cout << ans << '\n';
  }
}
