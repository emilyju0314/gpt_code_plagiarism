#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    long long int a, b;
    cin >> a >> b;
    if (x >= y) {
      if (2 * a <= b) {
        cout << (x + y) * a << endl;
      } else {
        cout << ((x - y) * a) + (y * b) << endl;
      }
    } else {
      if (2 * a <= b) {
        cout << (x + y) * a << endl;
      } else {
        cout << ((y - x) * a) + (x * b) << endl;
      }
    }
  }
  return 0;
}
