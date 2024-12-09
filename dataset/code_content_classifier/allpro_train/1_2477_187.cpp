#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
const double EPS = 1e-12;
const double PI = acos(-1);
struct Point {
  long long x, y;
  Point(long long _x = 0, long long _y = 0) {
    x = _x;
    y = _y;
  }
  Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
  Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
  Point operator*(const long long v) { return Point(x * v, y * v); }
  long long operator*(const Point& b) const { return x * b.y - y * b.x; }
  long long operator^(const Point& b) const { return x * b.x + y * b.y; }
  bool operator==(const Point& b) const { return x == b.x && y == b.y; }
  bool operator<(const Point& b) const {
    return x < b.x || (x == b.x && y < b.y);
  }
  double angle() { return atan2(y, x); }
  double dis() { return sqrt(x * x + y * y); }
  void print() { cout << x << " " << y << endl; }
};
bool compare(const Point& X, const Point& Y) {
  long long me = X * Y;
  if (!me) {
    return abs(X.x) + abs(X.y) < abs(Y.x) + abs(Y.y);
  }
  return me > 0;
}
Point tmp, stk[SIZE];
int sn;
long long solve(vector<Point>& p) {
  if (((int)(p).size()) < 3) {
    sn = 0;
    for (int i = 0; i < (((int)(p).size())); ++i) stk[sn++] = p[i];
    return 0;
  }
  for (int i = (1); i < (((int)(p).size())); ++i) {
    if (p[i] < p[0]) swap(p[0], p[i]);
  }
  for (int i = (1); i < (((int)(p).size())); ++i) {
    p[i].x -= p[0].x;
    p[i].y -= p[0].y;
  }
  sort(p.begin() + 1, p.end(), compare);
  tmp = p[0];
  p[0] = Point(0, 0);
  sn = 0;
  stk[sn++] = p[0];
  stk[sn++] = p[1];
  for (int i = (2); i < (((int)(p).size())); ++i) {
    while (sn >= 2 && (stk[sn - 1] - stk[sn - 2]) * (p[i] - stk[sn - 1]) <= 0) {
      sn--;
    }
    stk[sn++] = p[i];
  }
  long long res = 0;
  for (int i = (2); i < (sn); ++i) res += stk[i - 1] * stk[i];
  for (int i = 0; i < (sn); ++i) p[i] = stk[i] + tmp;
  p.resize(sn);
  return res;
}
long long area(const Point& X, const Point& Y, const Point& Z) {
  return abs((X - Y) * (X - Z));
}
int main() {
  int(n);
  scanf("%d", &n);
  char s[24];
  scanf("%s", (s));
  vector<Point> p;
  for (int i = 0; i < (n); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p.push_back(Point(x, y));
  }
  solve(p);
  int m = ((int)(p).size());
  for (int i = 0; i < (m); ++i) p.push_back(p[i]);
  long long ma = -1, id[3];
  for (int v1 = 0; v1 < (m); ++v1) {
    int v3 = v1 + 1;
    for (int i = (2); i < (m); ++i) {
      int v2 = v1 + i;
      while (v3 + 1 < v2 &&
             area(p[v1], p[v2], p[v3]) < area(p[v1], p[v2], p[v3 + 1]))
        v3++;
      long long me = area(p[v1], p[v2], p[v3]);
      if (ma < me) {
        ma = me;
        id[0] = v1, id[1] = v2, id[2] = v3;
      }
    }
  }
  for (int i = 0; i < (3); ++i) {
    (p[id[i]] + p[id[(i + 1) % 3]] - p[id[(i + 2) % 3]]).print();
  }
  return 0;
}
