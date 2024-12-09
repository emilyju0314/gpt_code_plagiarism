#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
struct P {
  long long x, y;
  void read() { scanf("%lld%lld", &x, &y); }
  P operator-(const P& b) const { return P{x - b.x, y - b.y}; }
  void operator+=(const P& b) { x += b.x, y += b.y; }
  long long operator*(const P& b) const { return x * b.y - y * b.x; }
  long long cross(const P& b, const P& c) const {
    return (b - *this) * (c - *this);
  }
  bool isRight() const { return x > 0 || (x == 0 && y > 0); }
  bool operator<(const P& b) const {
    if (isRight() != b.isRight()) return isRight();
    return *this * b < 0;
  }
};
debug& operator<<(debug& dd, P p) {
  dd << make_pair(p.x, p.y);
  return dd;
}
struct L2 {
  P one, two;
  P dir() const { return two - one; }
  bool operator<(const L2& b) const { return dir() < b.dir(); }
  long double get_coeff(const L2& b) const {
    long double r = (b.dir() * (one - b.one)) / (long double)(dir() * b.dir());
    return r;
  }
  bool isParallel(const L2& b) const { return dir() * b.dir() == 0; }
  bool isBetter(const L2& b) const {
    assert(isParallel(b));
    return (b.one - one) * (two - one) < 0;
  }
  bool isBelow(const L2& a, const L2& c) const {
    return get_coeff(a) >= get_coeff(c);
  }
  pair<long double, long double> intersect(const L2& b) const {
    long double r = get_coeff(b);
    return make_pair(one.x + r * (two - one).x, one.y + r * (two - one).y);
  }
};
debug& operator<<(debug& dd, L2 line) {
  dd << make_pair(line.one, line.two);
  return dd;
}
deque<L2> getHull(vector<L2> halfplanes) {
  sort(halfplanes.begin(), halfplanes.end());
  debug() << " ["
          << "halfplanes"
             ": "
          << (halfplanes) << "] ";
  deque<L2> hull;
  for (L2 line : halfplanes) {
    if (!hull.empty() && line.isParallel(hull.back())) {
      if (hull.back().isBetter(line)) line = hull.back();
      hull.pop_back();
    }
    while ((int)hull.size() >= 2 &&
           hull.back().isBelow(hull[(int)hull.size() - 2], line))
      hull.pop_back();
    hull.push_back(line);
  }
  while ((int)hull.size() >= 3) {
    if (hull.back().isBelow(hull[(int)hull.size() - 2], hull[0]))
      hull.pop_back();
    else if (hull[0].isBelow(hull.back(), hull[1]))
      hull.pop_front();
    else
      break;
  }
  debug() << " ["
          << "hull"
             ": "
          << (hull) << "] ";
  return hull;
}
long double test_case() {
  int n;
  scanf("%d", &n);
  P origin;
  origin.read();
  vector<P> points(n - 1);
  for (P& p : points) {
    p.read();
    p = p - origin;
  }
  sort(points.begin(), points.end());
  debug() << " ["
          << "points"
             ": "
          << (points) << "] ";
  vector<L2> halfplanes;
  for (int i = 0; i < (int)points.size(); ++i) {
    int j = (i + 1) % points.size();
    halfplanes.push_back(L2{points[i], points[j]});
  }
  int pointer = 0;
  for (int i = 0; i < (int)points.size(); ++i) {
    pointer = max(pointer, i + 1);
    while (points[i] * points[pointer % points.size()] < 0) ++pointer;
    if (i != pointer % (int)points.size())
      halfplanes.push_back(L2{points[i], points[pointer % points.size()]});
  }
  debug() << " ["
          << "halfplanes"
             ": "
          << (halfplanes) << "] ";
  for (L2& line : halfplanes) {
    if (line.one * line.two == 0) return 0;
    if (line.one * line.two > 0) swap(line.one, line.two);
    line.one += origin;
    line.two += origin;
  }
  const int MAX = 1e6;
  vector<P> corners{P{-MAX, MAX}, P{MAX, MAX}, P{MAX, -MAX}, P{-MAX, -MAX}};
  for (int i = 0; i < (int)corners.size(); ++i) {
    int j = (i + 1) % corners.size();
    halfplanes.push_back(L2{corners[i], corners[j]});
  }
  deque<L2> hull = getHull(halfplanes);
  vector<pair<long double, long double>> polygon;
  long double area = 0;
  for (int i = 0; i < (int)hull.size(); ++i) {
    int j = (i + 1) % hull.size();
    polygon.push_back(hull[i].intersect(hull[j]));
  }
  debug() << " ["
          << "polygon"
             ": "
          << (polygon) << "] ";
  for (int i = 0; i < (int)polygon.size(); ++i) {
    int j = (i + 1) % polygon.size();
    area += polygon[i].first * polygon[j].second -
            polygon[i].second * polygon[j].first;
  }
  return abs(area) / 2;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%.12lf\n", (double)test_case());
}
