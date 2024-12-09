#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1e9 + 7;
long long mod2 = 998244353;
long long mul(long long x, long long y) {
  return (1ll * (x % mod1) * (y % mod1));
}
long long power(long long x, long long y) {
  long long z = 1;
  while (y > 0) {
    if (y % 2) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long sq(long long a) {
  long long ans = (1ll * a * a);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]] = i;
  }
  sort(a, a + n);
  long long b[n];
  for (long long i = 0; i < n; i++) {
    b[m[a[i]]] = a[(i + 1) % n];
  }
  for (long long i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}
