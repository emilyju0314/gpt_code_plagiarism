#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
int main() {
  long long n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  if (p < q) {
    swap(a, b);
    swap(p, q);
  }
  long long ans = (n / a) * p;
  ans += (n / b - n / lcm(a, b)) * q;
  cout << ans << endl;
  return 0;
}
