#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int x, y, z, i;
  cin >> a >> b;
  x = 0;
  y = 0;
  z = 0;
  for (i = 1; i <= 6; i++) {
    if (abs(a - i) < abs(b - i)) {
      x++;
    } else if (abs(a - i) > abs(b - i)) {
      y++;
    } else {
      z++;
    }
  }
  cout << x << " " << z << " " << y << endl;
  return 0;
}
