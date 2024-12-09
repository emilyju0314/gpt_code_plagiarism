#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long modp(long long a, long long b) {
  if (b == 0) return 1;
  long long u = modp(a, b / 2);
  u = (u * u) % mod;
  if (b & 1) return (a * u) % mod;
  return u;
}
long long numcon(string s) {
  long long ans = 0;
  reverse(s.begin(), s.end());
  long long n = s.length();
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') continue;
    ans += modp(2, i);
    ans %= mod;
  }
  return ans;
}
int32_t main() {
  string s;
  cin >> s;
  long long n = s.length();
  long long ans = numcon(s);
  long long base = modp(2, n - 1);
  ans *= base;
  ans %= mod;
  cout << ans;
}
