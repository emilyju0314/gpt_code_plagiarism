#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e18 + 7;
struct line {
  long double a, b, c;
};
struct pt {
  long double x, y;
};
long double sqr(long double x) { return x * x; }
long double dist(pt a, pt b) {
  if (a.x == INF || a.y == INF || b.x == INF || b.y == INF) return INF;
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main() {
  line l;
  cin >> l.a >> l.b >> l.c;
  pt a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  long double d1 = abs(a.x - b.x) + abs(a.y - b.y);
  long double d2 = INF;
  pt a1{INF, INF}, a2 = {INF, INF}, b1 = {INF, INF}, b2 = {INF, INF};
  if (l.a != 0) {
    a1.x = (-l.c - l.b * a.y) / l.a;
    a1.y = a.y;
    b1.x = (-l.c - l.b * b.y) / l.a;
    b1.y = b.y;
  }
  if (l.b != 0) {
    a2.y = (-l.c - l.a * a.x) / l.b;
    a2.x = a.x;
    b2.y = (-l.c - l.a * b.x) / l.b;
    b2.x = b.x;
  }
  d2 = min(d2, dist(a, a1) + dist(b, b1) + dist(a1, b1));
  d2 = min(d2, dist(a, a1) + dist(b, b2) + dist(a1, b2));
  d2 = min(d2, dist(a, a2) + dist(b, b1) + dist(a2, b1));
  d2 = min(d2, dist(a, a2) + dist(b, b2) + dist(a2, b2));
  cout << fixed << setprecision(9) << min(d1, d2);
  return 0;
}
