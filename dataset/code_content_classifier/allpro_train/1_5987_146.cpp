#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, x, y, top, down, left, right, max = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    max = 0;
    cin >> a >> b >> x >> y;
    top = (x - 0) * b;
    down = (a - x - 1) * b;
    left = (y - 0) * a;
    right = (b - y - 1) * a;
    if (top >= max) max = top;
    if (down >= max) max = down;
    if (right >= max) max = right;
    if (left >= max) max = left;
    cout << max << endl;
  }
  return 0;
}
