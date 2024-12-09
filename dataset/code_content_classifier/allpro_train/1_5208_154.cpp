#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 1e6 + 5;
const long long MAX2 = 11;
const long long MOD = 998244353;
const long long MOD2 = 1000000006;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
long long n, k, ans, cnt[MAX], p[MAX], sm, inv, nv, z;
inline long long pw(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  nv = pw(n, MOD - 2);
  nv = nv * nv % MOD;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    inv = nv * pw(k, MOD - 2) % MOD;
    for (int j = 1; j <= k; ++j) {
      cin >> z;
      p[z] += inv;
      ++cnt[z];
    }
  }
  for (int i = 1; i <= 1000000; ++i) ans = (ans + cnt[i] * (p[i] % MOD)) % MOD;
  cout << ans << '\n';
  return 0;
}
