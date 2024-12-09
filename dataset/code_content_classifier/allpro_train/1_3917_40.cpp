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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x, i, res1 = 0, res2 = 0, res = 0;
    string s;
    cin >> s;
    cin >> x;
    long long n = s.length();
    char ans[n];
    for (i = 0; i < n; i++) ans[i] = '2';
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i - x >= 0) ans[i - x] = '0';
        if (i + x < n) ans[i + x] = '0';
      }
    }
    for (i = 0; i < n; i++) {
      res1 = 0;
      res2 = 0;
      if (s[i] == '1') {
        if (i - x >= 0) {
          if (ans[i - x] == '0') {
            res1 = 1;
          } else {
            ans[i - x] = '1';
          }
        } else {
          res1 = 1;
        }
        if (i + x < n) {
          if (ans[i + x] == '0') {
            res2 = 1;
          } else {
            ans[i + x] = '1';
          }
        } else {
          res2 = 1;
        }
        if (res1 == 1 and res2 == 1) {
          res = 1;
          break;
        }
        if (i - x < 0 and i + x > n) {
          res = 1;
          break;
        }
      }
    }
    if (res == 1)
      cout << -1 << '\n';
    else {
      for (i = 0; i < n; i++) {
        if (ans[i] == '2')
          cout << 1;
        else
          cout << ans[i];
      }
      cout << '\n';
    }
  }
  return 0;
}
