#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ele, i, j, ele1, k, n, a, b, q;
  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> n >> a >> b;
    if (n == 1) {
      cout << a << endl;
      continue;
    } else if (2 * a > b) {
      ele = n % 2;
      ele1 = n / 2;
      if (ele == 0) {
        cout << ele1 * b << endl;
      } else {
        cout << ele1 * b + a << endl;
      }
    } else if (2 * a <= b) {
      cout << n * a << endl;
    }
  }
}
