#include <bits/stdc++.h>
using namespace std;
inline long long read(void) {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9';
       x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar())
    ;
  return x * f;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long n = read(), m = read(), k = read();
  if (n * m * 2 % k != 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << "0 0" << endl;
  long long x = gcd(2 * n, k), y = k / x;
  x = 2 * n / x, y = m / y;
  if (x <= n && y <= m) {
    cout << x << " 0" << endl;
    cout << "0 " << y << endl;
  } else {
    x >>= 1, y <<= 1;
    cout << x << " 0" << endl;
    cout << "0 " << y << endl;
  }
  return 0;
}
