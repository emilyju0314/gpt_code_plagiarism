#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long inv(long long a) {
  long long x, y;
  long long g = gcd(a, mod, x, y);
  x = (x % mod + mod) % mod;
  return x;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    for (int i = 0; i < k; i++) v.push_back(1);
    int end = n + m + 1;
    if (m == n - 1 && k == 1) {
      v.push_back(n);
      v.push_back(n + 1);
    } else if (m < n - 1 && k == 1) {
      v.push_back(n);
    } else if (n == 2 && m == 2 && k == 1) {
      v.push_back(n);
      v.push_back(n + 1);
      v.push_back(n + 2);
    } else if (n == 2 && m == 2) {
      v.push_back(n);
      for (int i = 0; i < k - 1; i++) v.push_back(n + 1);
      v.push_back(n + 2);
    } else if (m <= n - 1) {
      v.push_back(n);
      for (int i = 0; i < k - 1; i++) v.push_back(n + 1);
    } else {
      v.push_back(n);
      for (int i = 0; i < k - 1; i++) v.push_back(n + 1);
      v.push_back(n + 2);
    }
    cout << v.size() << "\n";
    for (int u : v) cout << u << " ";
  }
  return 0;
}
