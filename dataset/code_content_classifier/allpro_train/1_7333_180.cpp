#include <bits/stdc++.h>
using namespace std;
int _gcd(int x, int y) {
  if (y == 0) return x;
  if (x < y) return _gcd(x, y % x);
  return _gcd(y, x % y);
}
long long int _pow(unsigned long long int x, unsigned long long int y) {
  long long int res = 1;
  x = x % (1000000000 + 7);
  while (y > 0) {
    if (y & 1) res = (res * x) % (1000000000 + 7);
    y = y >> 1;
    x = (x * x) % (1000000000 + 7);
  }
  return res;
}
int main() {
  unsigned long long int x, k;
  cin >> x >> k;
  if (x == 0) {
    cout << "0"
         << "\n";
    return 0;
  }
  long long int ans;
  ans = (((x % (1000000000 + 7)) * (_pow(2, k + 1) % (1000000000 + 7))) %
             (1000000000 + 7) -
         (_pow(2, k) % (1000000000 + 7)) + 1 + (1000000000 + 7)) %
        (1000000000 + 7);
  cout << ans << "\n";
  return 0;
}
