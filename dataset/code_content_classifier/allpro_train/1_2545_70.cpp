#include <bits/stdc++.h>
using namespace std;
float PHI = 1.6180339;
const float PI_F = 3.14159265358979f;
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long add(long long x, long long y) {
  x += y;
  if (x >= 1000000007) return x - 1000000007;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + 1000000007;
  return x;
}
long long inv(long long a, long long m = 998244353) {
  return modpow(a, m - 2, m);
}
long long mul(long long a, long long b) { return (long long)a * b % 998244353; }
long long nCrModp(long long n, long long r, long long p) {
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long powmod(long long a, long long b, long long p) {
  long long res = 1;
  while (b)
    if (b & 1)
      res = (res * 1ll * a % p), --b;
    else
      a = (a * 1ll * a % p), b >>= 1;
  return res;
}
long long generator(long long p) {
  long long cnt = 0;
  vector<long long> fact;
  long long phi = p - 1, n = phi;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  if (n > 1) fact.push_back(n);
  for (long long res = 2; res < p; ++res) {
    bool ok = true;
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= powmod(res, phi / fact[i], p) != 1;
    if (ok) cnt += 1;
  }
  return cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cout << fixed << setprecision(12);
  long long p;
  cin >> p;
  if (p == 2)
    cout << "1"
         << "\n";
  else
    cout << generator(p) << "\n";
  return 0;
}
