#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x1, y1, x2, y2, dx, dy, nx, ny;
  int u;
  cin >> u;
  while (u--) {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    if (dy == 0) {
      cout << m * max(0ll, 2 * dx - n) << endl;
    } else if (dx == 0) {
      cout << n * max(0ll, 2 * dy - m) << endl;
    } else {
      nx = n - dx + 1;
      ny = m - dy + 1;
      long long int c = dx * dy * 2;
      if (nx <= dx && ny <= dy)
        c -= (dx - nx + 1) * (dy - ny + 1);
      else if (nx <= dx)
        c += (dx - nx + 1) * (ny - dy - 1);
      else if (ny <= dy)
        c += (dy - ny + 1) * (nx - dx - 1);
      cout << c << endl;
    }
  }
  return 0;
}
