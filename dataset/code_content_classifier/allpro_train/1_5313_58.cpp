#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
char L[100010], R[100010];
long long ans;
long long dp[100010][10];
long long solve(char st[]) {
  long long sz = strlen(st);
  long long f = 0, s1 = 0, s2 = 0, a1 = 0, a2 = 0, k = 0;
  for (long long i = 0; i < sz; i++) {
    f = (100 * f + 100 * s1 + 220 * s2 + 70 * (a2 + mod - a1) % mod +
         56 * (k - 1)) %
        mod;
    s1 = (200 * s1 + 220 * s2 + 65 * (k - 1)) % mod;
    s2 = (20 * s2 + 11 * (k - 1)) % mod;
    if (st[i] == '7') {
      f = (f + ((a2 * 10 + 4) % mod) * ((a2 * 10 + 7) % mod)) % mod;
      s1 = (s1 + ((a2 * 10 + 4) % mod) * ((a2 * 10 + 4) % mod)) % mod;
      s2 = (s2 + a2 * 10 + 4) % mod;
    }
    a2 = (a2 * 10 + st[i] - '0') % mod;
    a1 = (a1 * 10 + 4) % mod;
    k = ((k - 1) * 2 + ((st[i] == '4') ? 1 : 2)) % mod;
  }
  return f;
}
signed main() {
  cin >> L >> R;
  ans -= solve(L);
  ans += solve(R);
  ans %= mod;
  while (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
