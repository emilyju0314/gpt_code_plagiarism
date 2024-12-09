#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y, r, x1, y1, r1, ra, tmp;
  while (cin >> x >> y >> r >> x1 >> y1 >> r1) {
    ra = (x - x1) * (x - x1) + (y - y1) * (y - y1);
    ra = sqrt(ra);
    if (ra >= fabs(r - r1) && ra <= r + r1) {
      ra = 0;
      printf("%.15f", ra);
    } else if (ra > (r + r1)) {
      ra -= (r + r1);
      ra /= 2.0;
      printf("%.15f", ra);
    } else {
      tmp = min(fabs(r - ra - r1), fabs(r1 - ra - r));
      tmp /= 2.0;
      printf("%.15f", tmp);
    }
  }
}
