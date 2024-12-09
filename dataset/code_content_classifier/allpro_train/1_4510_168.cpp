#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1.0);
long long mod = 998244353;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long prod(long long a, long long b) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1ll) res = (res + a) % mod;
    a = (2ll * a) % mod;
    b >>= 1ll;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return res;
}
long long binaryExponentiation(long long a, long long b) {
  long long result = 1ll;
  while (b > 0) {
    if (b % 2 == 1) result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return result;
}
long long ModularInverse(long long a) {
  return binaryExponentiation(a, mod - 2);
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long l = 0, r = n * m;
  while (l < r) {
    long long x = l + (r - l) / 2;
    bool f = true;
    long long prev = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] < prev) {
        if (prev - a[i] > x) {
          f = false;
          break;
        }
      } else if (a[i] > prev) {
        if (x < (m - a[i]) + prev) {
          prev = a[i];
        }
      }
    }
    if (f) {
      r = x;
    } else {
      l = x + 1;
    }
  }
  cout << r << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
