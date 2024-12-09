#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, c, a, b, t;
  cin >> a >> b >> c;
  for (i = 1; i < 501; i++) {
    a *= 10;
    t = a / b;
    a %= b;
    if (t == c) {
      cout << i;
      return 0;
    }
    if (a % b == 0) {
      if (c == 0) {
        cout << i + 1;
        return 0;
      } else
        break;
    }
  }
  cout << -1;
  return 0;
}
