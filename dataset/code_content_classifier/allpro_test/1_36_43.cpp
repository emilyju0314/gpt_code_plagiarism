#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod1 = 998244353;
const long long mod = 1e9 + 7;
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long findMinNumber(long long n) {
  long long count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isprime(long long n) {
  long long i, d = sqrt(n) + 1;
  for (i = 2; i < d; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], i, sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (isprime(sum)) {
      long long idx;
      cout << n - 1 << '\n';
      for (i = 0; i < n; i++) {
        if (!isprime(sum - a[i])) {
          idx = i;
          break;
        }
      }
      for (i = 0; i < n; i++) {
        if (i != idx) cout << i + 1 << " ";
      }
      cout << '\n';
    } else {
      cout << n << '\n';
      for (i = 0; i < n; i++) cout << i + 1 << " ";
      cout << '\n';
    }
  }
  return 0;
}
