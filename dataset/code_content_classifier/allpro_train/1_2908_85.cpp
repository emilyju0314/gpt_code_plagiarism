#include <bits/stdc++.h>
using namespace std;
const __int128 mod = (1LL << 61) - 1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const __int128 mul = 57497633;
const int mn = 8e3 + 10;
int num[mn][mn];
__int128 hsh[mn], p[mn];
inline __int128 vesh(int l, int r) {
  __int128 v = (hsh[r] - hsh[l] * p[r - l]) % mod;
  if (v < 0) v += mod;
  assert(0 <= v && v <= mod);
  return v;
}
int dp[mn], lg[mn];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  for (int i = 1; i < 10; i++) lg[i] = 1;
  for (int i = 10; i < 100; i++) lg[i] = 2;
  for (int i = 100; i < 1000; i++) lg[i] = 3;
  for (int i = 1000; i < mn; i++) lg[i] = 4;
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  for (int i = 1; i <= n; i++) hsh[i] = (hsh[i - 1] * mul + s[i]) % mod;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * mul % mod;
  for (int i = 1; i <= n; i++) {
    for (int l = 1; l <= i; l++) {
      if (i - 2 * l >= 0 && vesh(i - 2 * l, i - l) == vesh(i - l, i))
        num[i][l] = num[i - l][l] + 1;
      else
        num[i][l] = 1;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int l = 1; l <= i; l++) {
      for (int k = 1; k <= num[i][l]; k++) {
        dp[i] = min(dp[i], lg[k] + l + dp[i - l * k]);
      }
    }
    if (0) cerr << i << ' ' << dp[i] << '\n';
  }
  printf("%d", dp[n]);
}
