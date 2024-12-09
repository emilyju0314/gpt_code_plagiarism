#include <bits/stdc++.h>
using namespace std;
bool prime[200005];
void sieve() {
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p < 200005; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i < 200005; i += p) prime[i] = false;
    }
  }
}
long long powmod(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
    }
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, q;
  cin >> n >> m >> q;
  double x = 2 * 1e18;
  long long gccd = (gcd(m, n));
  long long x1 = n / gccd;
  long long x2 = m / gccd;
  while (q--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long sec1, sec2;
    if (a == 1) {
      if (b % x1 == 0) {
        sec1 = (b / x1) - 1;
      } else
        sec1 = (b / x1);
    } else {
      if (b % x2 == 0) {
        sec1 = (b / x2) - 1;
      } else
        sec1 = (b / x2);
    }
    if (c == 1) {
      if (d % x1 == 0) {
        sec2 = (d / x1) - 1;
      } else
        sec2 = (d / x1);
    } else {
      if (d % x2 == 0) {
        sec2 = (d / x2) - 1;
      } else
        sec2 = (d / x2);
    }
    if (sec1 == sec2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
