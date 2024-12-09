#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int s, in, ex;
    cin >> s >> in >> ex;
    long long int d = s - in;
    long long int ans = 0;
    if (s + ex <= in)
      cout << 0 << '\n';
    else {
      long long int x1 = ((ex + in - s) / 2) + 1;
      if (in + ex < s) x1 = 0;
      cout << max((long long int)0, ex - x1 + 1) << '\n';
    }
  }
  return 0;
}
long long int fast_power(long long int base, long long int power,
                         long long int MOD) {
  long long int result = 1;
  while (power > 0) {
    if (power & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return result;
}
