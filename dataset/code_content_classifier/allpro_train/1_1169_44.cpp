#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int tec = x * x + y * y;
  bool clr = 0;
  for (int i = 0;; i++) {
    if (tec >= i * i && tec < (i + 1) * (i + 1)) {
      if (tec == i * i) {
        cout << "black\n";
        return 0;
      }
      clr = i & 1;
      break;
    }
  }
  if (x * y < 0) {
    clr ^= 1;
  }
  if (clr) {
    cout << "white\n";
  } else {
    cout << "black\n";
  }
  return 0;
}
