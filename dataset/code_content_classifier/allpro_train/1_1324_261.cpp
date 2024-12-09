#include <bits/stdc++.h>
using namespace std;
int bpow(int a, int b) {
  long double res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << fixed << setprecision(9) << 1 << "\n";
      continue;
    }
    if (n % 2 == 0) {
      long double y = 2 * n;
      long double a = ((y - 2) * 90 * 1.0) / y;
      long double b = 90.0 - a;
      a = a * 3.1415926535897932385 / 180.0;
      b = b * 3.1415926535897932385 / 180.0;
      long double c = (sin(a) * 0.5) / sin(b);
      cout << fixed << setprecision(9) << 2 * c << "\n";
    } else {
      long double y = 2 * n;
      long double a = ((y - 2) * 90 * 1.0) / y;
      long double b = 180.0 - 2 * a;
      a = a * 3.1415926535897932385 / 180.0;
      b = b * 3.1415926535897932385 / 180.0;
      long double c = (sin(a) * 1.0) / sin(b);
      cout << fixed << setprecision(9) << 2 * c << "\n";
    }
  }
  return 0;
}
