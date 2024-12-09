#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0) { x = _x, y = _y; }
  inline bool operator<(const Point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
  inline Point F() {
    Point p = Point(x, y);
    if (x || y) {
      int g = gcd(p.x, p.y);
      p.x /= g, p.y /= g;
    }
    return p;
  }
  inline Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
  }
};
map<long long, set<Point> > C;
map<Point, long long> L;
int q;
int t, x, y;
long long d;
Point P;
int cnt;
int main() {
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &t, &x, &y);
    P = Point(x, y);
    d = 1ll * x * x + 1ll * y * y;
    if (t == 1) {
      for (auto p : C[d]) L[(p + P).F()] += 2;
      L[P.F()]++;
      C[d].insert(P);
      cnt++;
    } else if (t == 2) {
      C[d].erase(C[d].find(P));
      for (auto p : C[d]) L[(p + P).F()] -= 2;
      L[P.F()]--;
      cnt--;
    } else if (t == 3)
      printf("%lld\n", cnt - L[P.F()]);
  }
  return 0;
}
