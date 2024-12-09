#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long out;
long long c[2000013];
long long fac[2000013];
long long ob_fac[2000013];
long long gov = 0;
long long step(long long a, long long n) {
  gov++;
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  if (n % 2 == 0) {
    long long k = step(a, n / 2);
    k *= k;
    k %= mod;
    return k;
  }
  long long k = step(a, n / 2);
  return ((k * k) % mod * a) % mod;
}
int main() {
  long long n;
  cin >> n;
  fac[0] = 1;
  ob_fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    ob_fac[i] = step(fac[i], mod - 2);
  }
  for (int i = n; i <= n * 2; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  for (int i = 0; i <= n; i++) {
    c[i] = (((fac[n + i] * ob_fac[i]) % mod) * ob_fac[n]) % mod;
  }
  long long out = 0, sum = 0;
  out = step(2, n + 1) - 1;
  sum = step(2, n);
  for (int i = 0; i <= n; i++) {
    sum = sum * 2 - 2 * c[i];
    sum = (sum + mod) % mod;
    out += sum;
    out = (out + mod) % mod;
  }
  cout << out;
  return 0;
}
