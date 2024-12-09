#include <bits/stdc++.h>
using namespace std;
long long multiply(long long num, long long x, long long mod) {
  num %= mod;
  for (int i = 2; i <= x; i++) {
    while ((x % i) == 0 && x) {
      num *= i;
      num %= mod;
      x /= i;
    }
  }
  return num % mod;
}
int main() {
  long long a;
  cin >> a;
  long long l = 1, r = 1e18;
  long long res = r / 10;
  res = multiply(res, 18, a);
  res = multiply(res, 45, a);
  l += a - res - 1;
  r += a - res - 1;
  cout << l << ' ' << r;
  return 0;
}
