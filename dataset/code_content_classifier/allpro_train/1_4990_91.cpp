#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x = abs(x1 - x2);
  int y = abs(y1 - y2);
  if (x == 0) {
    x = 1;
  }
  if (y == 0) {
    y = 1;
  }
  cout << (2 * (x + 1) + 2 * (y + 1)) << endl;
}
