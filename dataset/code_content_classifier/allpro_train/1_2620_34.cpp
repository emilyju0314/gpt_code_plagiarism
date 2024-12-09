#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
inline long long add(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x + _y;
  if (_ >= _mod) _ -= _mod;
  return _;
}
inline long long sub(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x - _y;
  if (_ < 0) _ += _mod;
  return _;
}
inline long long mul(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x * _y;
  if (_ >= _mod) _ %= _mod;
  return _;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1ll;
  long long _tmp = mypow(_a, _x / 2, _mod);
  _tmp = mul(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = mul(_tmp, _a, _mod);
  return _tmp;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0ll;
  long long _tmp = mymul(_a, _x / 2, _mod);
  _tmp = add(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = add(_tmp, _a, _mod);
  return _tmp;
}
inline bool equal(long double _x, long double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
int __ = 1, _cs;
inline long double getLD() {
  double _;
  scanf("%lf", &_);
  return _;
}
inline void scan(tuple<long double, long double, long double>& tp) {
  get<0>(tp) = getLD();
  get<1>(tp) = getLD();
  get<2>(tp) = getLD();
}
inline void print(const tuple<long double, long double, long double>& tp) {
  printf("(%.6f,%.6f,%.6f)\n", (double)get<0>(tp), (double)get<1>(tp),
         (double)get<2>(tp));
}
inline bool onbase(const tuple<long double, long double, long double>& tp) {
  return equal(get<2>(tp), 0.0);
}
inline long double sqr(const long double& x) { return x * x; }
long double r, h, ans, rr;
tuple<long double, long double, long double> p[2];
const long double pi = acosl(-1.0);
const long double pi2 = 2.0 * acosl(-1.0);
void build() {}
void init() {
  r = getLD();
  h = getLD();
  rr = sqrtl(sqr(r) + sqr(h));
  scan(p[0]);
  scan(p[1]);
}
inline long double dist(const tuple<long double, long double, long double>& x,
                        const tuple<long double, long double, long double>& y) {
  return sqrtl(sqr(get<0>(x) - get<0>(y)) + sqr(get<1>(x) - get<1>(y)) +
               sqr(get<2>(x) - get<2>(y)));
}
inline long double dist_oncone(
    const tuple<long double, long double, long double>& x,
    const tuple<long double, long double, long double>& y) {
  long double ang1 = atan2(get<1>(x), get<0>(x));
  long double ang2 = atan2(get<1>(y), get<0>(y));
  long double dang = fabsl(ang1 - ang2);
  dang *= r / rr;
  long double r1 = rr * (1.0 - get<2>(x) / h);
  long double r2 = rr * (1.0 - get<2>(y) / h);
  tuple<long double, long double, long double> p1 = make_tuple(r1, 0.0, 0.0);
  tuple<long double, long double, long double> p2 =
      make_tuple(cosl(dang) * r2, sinl(dang) * r2, 0.0);
  dang = r / rr * pi2 - dang;
  tuple<long double, long double, long double> p3 = make_tuple(r1, 0.0, 0.0);
  tuple<long double, long double, long double> p4 =
      make_tuple(cosl(dang) * r2, sinl(dang) * r2, 0.0);
  return min(dist(p1, p2), dist(p3, p4));
}
inline void cal1() { ans = min(ans, dist(p[0], p[1])); }
inline void cal2() {
  for (int y = 0; y < 10; y++) {
    long double bans = 1e40, bl = pi2 / 10 * y, br = pi2 / 10 * (y + 1), m1, m2;
    for (int i = 0; i < 120; i++) {
      m1 = bl + (br - bl) / 3;
      m2 = br - (br - bl) / 3;
      tuple<long double, long double, long double> tmp1 =
          make_tuple(cosl(m1) * r, sinl(m1) * r, 0.0);
      tuple<long double, long double, long double> tmp2 =
          make_tuple(cosl(m2) * r, sinl(m2) * r, 0.0);
      long double tans1 = dist_oncone(p[1], tmp1) + dist(tmp1, p[0]);
      long double tans2 = dist_oncone(p[1], tmp2) + dist(tmp2, p[0]);
      if (tans1 < tans2) {
        bans = min(bans, tans1);
        br = m2;
      } else {
        bans = min(bans, tans2);
        bl = m1;
      }
    }
    ans = min(ans, bans);
  }
}
inline long double cal4(
    const tuple<long double, long double, long double>& p1,
    const tuple<long double, long double, long double>& p2) {
  long double bbans = 1e40;
  for (int y = 0; y < 10; y++) {
    long double bans = 1e40, bl = pi2 / 10 * y, br = pi2 / 10 * (y + 1), m1, m2;
    for (int i = 0; i < 80; i++) {
      m1 = bl + (br - bl) / 3;
      m2 = br - (br - bl) / 3;
      tuple<long double, long double, long double> tmp1 =
          make_tuple(cosl(m1) * r, sinl(m1) * r, 0.0);
      tuple<long double, long double, long double> tmp2 =
          make_tuple(cosl(m2) * r, sinl(m2) * r, 0.0);
      long double tans1 = dist_oncone(p2, tmp1) + dist(p1, tmp1);
      long double tans2 = dist_oncone(p2, tmp2) + dist(p1, tmp2);
      if (tans1 < tans2) {
        bans = min(bans, tans1);
        br = m2;
      } else {
        bans = min(bans, tans2);
        bl = m1;
      }
    }
    bbans = min(bbans, bans);
  }
  return bbans;
}
inline void cal3() {
  ans = min(ans, dist_oncone(p[0], p[1]));
  for (int y = 0; y < 10; y++) {
    long double bans = 1e40, bl = pi2 / 10 * y, br = pi2 / 10 * (y + 1), m1, m2;
    for (int i = 0; i < 80; i++) {
      m1 = bl + (br - bl) / 3;
      m2 = br - (br - bl) / 3;
      tuple<long double, long double, long double> tmp1 =
          make_tuple(cosl(m1) * r, sinl(m1) * r, 0.0);
      tuple<long double, long double, long double> tmp2 =
          make_tuple(cosl(m2) * r, sinl(m2) * r, 0.0);
      long double tans1 = dist_oncone(p[0], tmp1) + cal4(tmp1, p[1]);
      long double tans2 = dist_oncone(p[0], tmp2) + cal4(tmp2, p[1]);
      if (tans1 < tans2) {
        bans = min(bans, tans1);
        br = m2;
      } else {
        bans = min(bans, tans2);
        bl = m1;
      }
    }
    ans = min(ans, bans);
  }
}
void solve() {
  ans = 1e40;
  if (onbase(p[0]) && onbase(p[1]))
    cal1();
  else if (onbase(p[0]) || onbase(p[1])) {
    if (onbase(p[1])) swap(p[0], p[1]);
    cal2();
  } else
    cal3();
  printf("%.12f\n", (double)ans);
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
