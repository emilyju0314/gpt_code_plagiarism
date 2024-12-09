#include <bits/stdc++.h>
#pragma GCC optimize "-Ofast"
using namespace std;
const long long OO = 0x0101010101010101;
class debug_t {
 public:
  template <typename T>
  debug_t& operator<<(const T& o) {
    return *this;
  }
  void end() {
    *this << "\nExecution Time = " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    exit(0);
  }
} dout;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
const double pi = acos(-1);
bool lineIntersect(complex<double> a, complex<double> b, complex<double> p,
                   complex<double> q, complex<double>& r) {
  double d1 = ((conj(p - a) * (b - a)).imag());
  double d2 = ((conj(q - a) * (b - a)).imag());
  if (fabs(d2 - d1) < 1e-9) return false;
  r = (d1 * q - d2 * p) / (d1 - d2);
  return true;
}
bool isPointOnLine(complex<double> a, complex<double> b, complex<double> p) {
  return fabs(((conj(((b) - (a))) * (((p) - (a)))).imag())) < 1e-9;
}
bool isPointOnSegment(complex<double> a, complex<double> b, complex<double> p) {
  return ((conj(((b) - (a))) * (((p) - (a)))).real()) > -1e-9 &&
         ((conj(((a) - (b))) * (((p) - (b)))).real()) > -1e-9;
}
struct line {
  complex<double> p1, p2;
  line() {}
  line(complex<double>& p1, complex<double>& p2) : p1(p1), p2(p2) {}
};
int main() {
  int x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  vector<line> ve;
  complex<double> home(x0, y0), univ(x1, y1);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    complex<double> p1, p2;
    if (!a) {
      p1 = complex<double>(-1., -1. * c / b);
      p2 = complex<double>(1., -1. * c / b);
    } else if (!b) {
      p1 = complex<double>(-1. * c / a, -1.);
      p2 = complex<double>(-1. * c / a, 1.);
    } else {
      p1 = complex<double>(0., -1. * c / b);
      p2 = complex<double>(-1. * b / a, -1. * c / b + 1.);
    }
    ve.push_back({p1, p2});
  }
  line road(home, univ);
  int res = 0;
  for (auto& l : ve) {
    complex<double> intersect;
    if (lineIntersect(road.p1, road.p2, l.p1, l.p2, intersect)) {
      res += isPointOnSegment(road.p1, road.p2, intersect);
    }
  }
  cout << res << "\n";
  return 0;
}
