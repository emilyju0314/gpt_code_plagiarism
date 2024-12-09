#include <bits/stdc++.h>
using namespace std;
constexpr int mod = (int)998244353;
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long binmul(long long a, long long b) {
  long long res = 0;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}
long long area(pair<long long, long long> a, pair<long long, long long> b,
               pair<long long, long long> c) {
  return abs(a.first * b.second + b.first * c.second + c.first * a.second -
             a.second * b.first - b.second * c.first - c.second * a.first);
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
double intlog(long long n, long long base) {
  return (double)log(n) / log(base);
}
long long t, m, temp, temp2, root, q, k, i, j, r, u, v, w, n, p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<long long> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  long long res = 1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == i) continue;
    int last = i;
    int k = 110;
    int result = 0;
    while (k--) {
      last = a[last];
      result++;
      if (last == i) break;
    }
    if (result == 110) {
      cout << -1 << "\n";
      return 0;
    }
    if (result % 2 == 0) result /= 2;
    res = lcm(res, result);
  }
  cout << res << "\n";
}
