#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool prime[1000001];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int p = 2; p * p <= 1000000; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 1000000; i += p) prime[i] = false;
    }
  }
}
void solve() {
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  long long dp[1001] = {0};
  dp[1] = x;
  for (int i = 2; i <= 1000; i++) {
    dp[i] = min(dp[i - 1] + x, min(dp[i - 2] + 2 * x, dp[i - 2] + y));
  }
  char a[n][m];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        sum += dp[c];
        c = 0;
      } else {
        c++;
      }
    }
    sum += dp[c];
  }
  cout << sum << endl;
}
int main() {
  fast();
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
