#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, t, x;
  for (cin >> t; t--;) {
    cin >> n;
    for (p = 2;; ++p) {
      x = pow(2, p) - 1;
      if (n % x == 0) {
        cout << n / x << "\n";
        break;
      }
    }
  }
}
