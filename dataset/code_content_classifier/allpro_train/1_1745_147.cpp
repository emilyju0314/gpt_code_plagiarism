#include <bits/stdc++.h>
using namespace std;
long long modulo(long long base, long long exponent, long long modulus);
long long choose(long long n, long long k);
long long inverse(long long a, long long m);
void build();
void fileio();
long long ncr(long long n, long long r);
const int nax = 1e6 + 10;
const int LG = log2(nax) + 1;
vector<long long> fact(nax);
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    long long x = (a + c - 1) / c;
    long long y = (b + d - 1) / d;
    if (x + y <= k)
      cout << x << " " << y << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
long long ncr(long long n, long long r) {
  if (r > n || r < 0 || n < 0) return 0;
  long long ans = fact[n];
  long long temp = (fact[n - r] * fact[r]) % 1000000007;
  ans = (ans * inverse(temp, 1000000007)) % 1000000007;
  return ans;
}
void fileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void build() {
  fact[0] = 1;
  for (long long i = 1; i < nax; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long modulo(long long base, long long exponent, long long modulus) {
  if (modulus == 1) return 0;
  long long result = 1;
  base = base % modulus;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long choose(long long n, long long k) {
  if (k == 0) return 1;
  return (n * choose(n - 1, k - 1)) / k;
}
void EE(long long a, long long b, long long &co1, long long &co2) {
  if (a % b == 0) {
    co1 = 0;
    co2 = 1;
    return;
  }
  EE(b, a % b, co1, co2);
  long long temp = co1;
  co1 = co2;
  co2 = temp - co2 * (a / b);
}
long long inverse(long long a, long long m) {
  long long x, y;
  EE(a, m, x, y);
  if (x < 0) x += m;
  return x;
}
