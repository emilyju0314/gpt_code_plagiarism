#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double> > v;
const double pi = 3.1415926535897932384626433832795;
const double eps = 0.00000001;
double cosa, sina;
double w, h, a;
double x, y;
double fun_y(pair<double, double> p1, pair<double, double> p2, double x) {
  return (x * (p1.second - p2.second) - p2.first * (p1.second - p2.second) +
          p2.second * (p1.first - p2.first)) /
         (p1.first - p2.first);
}
double fun_x(pair<double, double> p1, pair<double, double> p2, double y) {
  return (y * (p1.first - p2.first) - p2.second * (p1.first - p2.first) +
          p2.first * (p1.second - p2.second)) /
         (p1.second - p2.second);
}
bool inside(double xx, double yy) {
  return (xx >= -x - eps && xx <= x + eps && yy >= -y - eps && yy <= y + eps);
}
void per(pair<double, double> p1, pair<double, double> p2) {
  double xx, yy;
  xx = x;
  yy = fun_y(p1, p2, xx);
  if (inside(xx, yy)) v.push_back(pair<double, double>(xx, yy));
  xx = -x;
  yy = fun_y(p1, p2, xx);
  if (inside(xx, yy)) v.push_back(pair<double, double>(xx, yy));
  yy = y;
  xx = fun_x(p1, p2, yy);
  if (inside(xx, yy)) v.push_back(pair<double, double>(xx, yy));
  yy = -y;
  xx = fun_x(p1, p2, yy);
  if (inside(xx, yy)) v.push_back(pair<double, double>(xx, yy));
}
void line(double x, double y, double xx, double yy) {
  double x1 = x * cosa - y * sina;
  double y1 = x * sina + y * cosa;
  double x2 = xx * cosa - yy * sina;
  double y2 = xx * sina + yy * cosa;
  per(pair<double, double>(x1, y1), pair<double, double>(x2, y2));
}
double sum(int num) {
  double dx = v[num].first - v[0].first;
  double dy = v[num].second - v[0].second;
  double d2x = v[num + 1].first - v[0].first;
  double d2y = v[num + 1].second - v[0].second;
  return fabs(dx * d2y - dy * d2x);
}
bool cmp(const pair<double, double> &p1, const pair<double, double> &p2) {
  return atan2(p1.second, p1.first) < atan2(p2.second, p2.first);
}
void fun() {
  cin >> w >> h >> a;
  a = a / 180.0 * pi;
  cosa = cos(a);
  sina = sin(a);
  x = w / 2.0;
  y = h / 2.0;
  if (a == 0.0 || a == 180.0) {
    printf("%lf", w * h);
    return;
  }
  if (a == 90.0) {
    printf("%lf", min(w, h) * min(w, h));
    return;
  }
  line(+x, +y, -x, +y);
  line(+x, +y, +x, -y);
  line(-x, +y, -x, -y);
  line(-x, -y, +x, -y);
  sort(v.begin(), v.end(), cmp);
  double S = 0;
  for (int i = 1; i < int(v.size()) - 1; ++i) {
    S += sum(i);
  }
  printf("%lf", S / 2.0);
}
int main() {
  fun();
  return 0;
}
