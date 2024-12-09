#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, w, z, a = 0;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    z = 0;
    cin >> w;
    while (w) {
      if (w % 10 == 7 || w % 10 == 4) z++;
      w /= 10;
    }
    if (z <= y) a++;
  }
  cout << a << endl;
  return 0;
}
