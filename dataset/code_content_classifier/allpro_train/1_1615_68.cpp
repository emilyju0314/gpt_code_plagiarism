#include <bits/stdc++.h>
using namespace std;
long long fast_pow(long long base, long long n, long long M) {
  if (n == 0) return 1;
  if (n == 1) return (base) % M;
  long long halfn = fast_pow(base, n / 2, M);
  if (n % 2 == 0)
    return (halfn * halfn) % M;
  else
    return (((halfn * halfn) % M) * base) % M;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long r, d, n, c = 0;
long double x, y, ri, a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> r >> d >> n;
  for (long long(i) = 0; (i) < (long long)(n); ++(i)) {
    cin >> x >> y >> ri;
    a = sqrt((x * x) + (y * y));
    if ((a <= r) && (a >= (r - d))) {
      a -= (r - d);
      b = (d - a);
      if ((ri <= a) && (ri <= b)) c++;
    }
  }
  cout << c;
  return 0;
}
