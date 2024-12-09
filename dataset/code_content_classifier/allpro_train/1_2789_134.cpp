#include <bits/stdc++.h>
using namespace std;
const long double epsilon = 1e-9;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
bool comp(long long a, long long b) { return (a > b); }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void foo(vector<long long> &a) {
  if (a[0] >= 1) return;
  a[0] = 1;
  for (long long i = 1; i < (long long)(a).size(); i++) {
    if (a[i] > a[i - 1]) continue;
    a[i] = a[i - 1] + 1;
  }
}
void runcase() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a.begin(), a.end());
  vector<vector<long long>> dp(n + 1, vector<long long>(2 * n, INF));
  dp[0][0] = 0;
  for (long long i = 0; i < n + 1; i++) {
    for (long long j = 0; j < 2 * n - 1; j++) {
      if (dp[i][j] < INF) {
        if (i < n)
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - j));
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
      }
    }
  }
  cout << dp[n][2 * n - 1] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    runcase();
  }
  return 0;
}
