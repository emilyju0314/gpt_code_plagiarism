#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, d, i, j, k, l, m, x, t;
  cin >> t;
  while (t--) {
    cin >> n;
    d = 0;
    if (n % 2 == 0) {
      d = 0;
      a = 2;
      n = n / 2;
      x = (n / 2) - 1;
      if (x > 999999) x = 999999;
      for (i = 3; i <= x; i++) {
        if (n % i == 0) {
          b = i;
          c = n / i;
          if (c != b && c != a) {
            d = 1;
            break;
          }
        }
      }
      if (d == 1) {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
      } else
        cout << "NO" << endl;
    } else if (n >= 3 && n % 2 != 0) {
      d = 0;
      a = 0;
      for (i = 3; i <= 1111; i += 2) {
        if (n % i == 0) {
          a = i;
          n = n / i;
          break;
        }
      }
      x = (n / 2) - 1;
      if (x > 999999) x = 999999;
      if (a == 0) {
        cout << "NO" << endl;
        continue;
      }
      for (i = a + 2; i <= x; i += 2) {
        if (n % i == 0) {
          b = i;
          c = n / i;
          if (c != b && c != a) {
            d = 1;
            break;
          }
        }
      }
      if (d == 1) {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
      } else
        cout << "NO" << endl;
    } else
      cout << "NO" << endl;
  }
}
