#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long arr[1000100], dp[10000200];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, m;
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    dp[arr[i]] = arr[i];
  }
  for (j = 0; j < 22; j++) {
    for (i = 0; i < (1 << 22); i++) {
      if (dp[i] != -1) {
        dp[i | (1 << j)] = dp[i];
      }
    }
  }
  for (i = 0; i < n; i++) cout << dp[~arr[i] & (1 << 22) - 1] << " ";
}
