#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int inf = 1000000000;
int main() {
  int minx = inf, maxx = -inf, miny = inf, maxy = -inf, minp = inf, maxp = -inf,
      minq = inf, maxq = -inf, n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
    minp = min(minp, x + y);
    maxp = max(maxp, x + y);
    minq = min(minq, x - y);
    maxq = max(maxq, x - y);
  }
  minx--;
  maxx++;
  miny--;
  maxy++;
  minp--;
  maxp++;
  minq--;
  maxq++;
  int r = 2 * (maxx - minx + maxy - miny);
  int a = minp - miny - minx, b = maxx - maxp + maxy, c = minq + maxy - minx,
      d = maxx - maxq - miny;
  cout << r - a - b - c - d << endl;
}
