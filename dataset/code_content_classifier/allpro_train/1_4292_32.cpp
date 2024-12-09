#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  int operator^(const Point &b) const { return x * b.y - y * b.x; }
  int operator*(const Point &b) const { return x * b.x + y * b.y; }
};
Point p[100100];
int main() {
  int n;
  scanf("%d", &n);
  n++;
  int x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    p[i] = Point(x, y);
  }
  int last;
  int ans = 0;
  for (int i = 2; i < n; i++) {
    y = (p[i - 2] - p[i]) ^ (p[i - 1] - p[i]);
    if (y > 0) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
