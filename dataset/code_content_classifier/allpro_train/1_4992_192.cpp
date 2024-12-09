#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long val = (n * (n + 1)) / 2;
    long long ans;
    if (m < val) {
      for (long long i = 1; i <= n; i++) {
        if (m >= i) {
          m = m - i;
        }
      }
      ans = m;
    } else {
      long long rem = m % val;
      for (long long i = 1; i <= n; i++) {
        if (rem >= i) {
          rem = rem - i;
        }
      }
      ans = rem;
    }
    cout << ans << "\n";
  }
  return 0;
}
