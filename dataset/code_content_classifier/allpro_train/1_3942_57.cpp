#include <bits/stdc++.h>
std::ostream& out = std::cout;
std::istream& in = std::cin;
struct PV {
  long double x, y;
  void N() {
    x *= 100;
    y *= 100;
  }
};
struct SV {
  PV a, b;
  void N() {
    a.N();
    b.N();
  }
};
struct P {
  P() {}
  P(PV const& pv) : x(llround(pv.x)), y(llround(pv.y)) {}
  int64_t x, y;
};
bool operator==(P const& a, P const& b) { return a.x == b.x && a.y == b.y; }
PV PPP(P const& p) {
  PV r;
  r.x = (long double)p.x;
  r.y = (long double)p.y;
  return r;
}
struct S {
  S() {}
  S(SV const& ps) : a(ps.a), b(ps.b) {}
  P a, b;
};
bool operator==(S const& a, S const& b) { return a.a == b.a && a.b == b.b; }
struct Comp {
  Comp(S const& s) {
    v.x = s.a.x - s.b.x;
    v.y = s.a.y - s.b.y;
  }
  bool operator()(std::pair<PV, S> const& p1,
                  std::pair<PV, S> const& p2) const {
    long double x = p1.first.x - p2.first.x;
    long double y = p1.first.y - p2.first.y;
    return x * v.x + y * v.y > 0;
  }
  P v;
};
bool operator<(PV const& p1, PV const& p2) {
  return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
const double EPS = 1E-9;
template <class T>
T det(T a, T b, T c, T d) {
  return (T)((long double)a * (long double)d - (long double)b * (long double)c);
}
bool between(int64_t a, int64_t b, long double c) {
  return std::min(a, b) - EPS <= c && c <= std::max(a, b) + EPS;
}
bool between(long double a, long double b, long double c) {
  return std::min(a, b) - EPS <= c && c <= std::max(a, b) + EPS;
}
bool operator==(PV const& a, PV const& b) {
  return between(a.x, a.x, b.x) && between(a.y, a.y, b.y);
}
template <class T, class P>
PV intersect(P const& a, P const& b, P const& c, P const& d) {
  PV r;
  T A1 = a.y - b.y, B1 = b.x - a.x, C1 = -A1 * a.x - B1 * a.y;
  T A2 = c.y - d.y, B2 = d.x - c.x, C2 = -A2 * c.x - B2 * c.y;
  T zn = det<T>(A1, B1, A2, B2);
  if (zn != 0) {
    r.x = (-det((long double)C1, (long double)B1, (long double)C2,
                (long double)B2)) /
          zn;
    r.y = (-det((long double)A1, (long double)C1, (long double)A2,
                (long double)C2)) /
          zn;
    if (!between(a.x, b.x, r.x) || !between(a.y, b.y, r.y))
      r.x = std::numeric_limits<long double>::quiet_NaN();
  } else if (det(A1, C1, A2, C2) == 0 && det(B1, C1, B2, C2) == 0) {
    r.x = std::numeric_limits<long double>::infinity();
  } else
    r.x = std::numeric_limits<long double>::quiet_NaN();
  return r;
}
template <class S, class P>
PV I(S const& s, P const& p1, P const& p2) {
  return intersect<decltype(p1.x), P>(p1, p2, s.a, s.b);
}
bool IsEnd(S const& s, PV const& p) {
  return (between(s.a.x, s.a.x, p.x) && between(s.a.y, s.a.y, p.y) ||
          between(s.b.x, s.b.x, p.x) && between(s.b.y, s.b.y, p.y));
}
bool No(PV const& p) { return std::isnan(p.x); }
bool Same(PV const& p) { return std::isinf(p.x); }
template <class T>
T Sqr(T a) {
  return a * a;
}
template <class P1, class P2>
long double Dist(P1 const& p1, P2 const& p2) {
  return sqrt(Sqr(p1.x - p2.x) + Sqr(p1.y - p2.y));
}
template <class S, class P>
bool OnTheDifSides(P const& p1, P const& p2, S const& lv) {
  return !No(I(lv, p1, p2));
}
template <>
bool OnTheDifSides(std::pair<PV, S> const& p1, std::pair<PV, S> const& p2,
                   SV const& lv) {
  P const& a = Dist(p1.first, p1.second.a) > Dist(p1.first, p1.second.b)
                   ? p1.second.a
                   : p1.second.b;
  P const& b = Dist(p2.first, p2.second.a) > Dist(p2.first, p2.second.b)
                   ? p2.second.a
                   : p2.second.b;
  return OnTheDifSides(a, b, lv);
}
template <class T>
bool operator!=(T const& a, T const& b) {
  return !(a == b);
}
bool FindDif(std::vector<std::pair<PV, S>> const& rr, int j,
             std::pair<int, int>& res) {
  for (int i : {j, j + 1})
    for (int h : {j + 2, j + 3})
      if (rr[i].second == rr[h].second) {
        res.first = 2 * j + 1 - i;
        res.second = 2 * j + 5 - h;
        return true;
      }
  return false;
}
int main() {
  out.precision(20);
  int n, m;
  in >> n >> m;
  std::vector<PV> vv(n);
  std::vector<P> v(n);
  for (int i = 0; i < n; ++i) {
    in >> vv[i].x >> vv[i].y;
    vv[i].N();
    v[i] = P(vv[i]);
  }
  for (int i = 0; i < m; ++i) {
    SV lv;
    in >> lv.a.x >> lv.a.y >> lv.b.x >> lv.b.y;
    lv.N();
    S l(lv);
    std::vector<std::pair<PV, S>> rr;
    bool prevWasSame = false;
    for (int j0 = n - 1, j = 0; j < n; j0 = j++) {
      PV r = I(l, v[j0], v[j]);
      if (No(r)) continue;
      S sss;
      sss.a = v[j0];
      sss.b = v[j];
      if (Same(r)) {
        if (prevWasSame)
          rr.back().first = PPP(v[j]);
        else {
          rr.emplace_back(PPP(v[j0]), sss);
          rr.emplace_back(PPP(v[j]), sss);
        }
        prevWasSame = true;
      } else {
        rr.emplace_back(r, sss);
        prevWasSame = false;
      }
    }
    std::sort(rr.begin(), rr.end(), Comp(l));
    PV prevP;
    long double res = 0;
    bool inside = false;
    for (size_t j = 0; j < rr.size(); ++j) {
      auto const& pa = rr[j];
      std::pair<int, int> dif;
      if ((int)j < (int)rr.size() - 3 && pa.first == rr[j + 1].first &&
          rr[j + 2].first == rr[j + 3].first && FindDif(rr, (int)j, dif)) {
        res += Dist(pa.first, rr[j + 2].first);
        if (inside) res += Dist(pa.first, prevP);
        if (OnTheDifSides(rr[dif.first], rr[dif.second], lv)) inside = !inside;
        if (inside) prevP = rr[j + 2].first;
        j += 3;
      } else if (IsEnd(pa.second, pa.first) && (int)j < (int)rr.size() - 1 &&
                 (j == 0 || pa.second != rr[j - 1].second)) {
        S const& s1 = pa.second;
        S const& s2 = rr[j + 1].second;
        PV p1, p2;
        if (s1.a == s2.a) {
          p1 = PPP(s1.b);
          p2 = PPP(s2.b);
        } else if (s1.a == s2.b) {
          p1 = PPP(s1.b);
          p2 = PPP(s2.a);
        } else if (s1.b == s2.a) {
          p1 = PPP(s1.a);
          p2 = PPP(s2.b);
        } else {
          p1 = PPP(s1.a);
          p2 = PPP(s2.a);
        }
        if (OnTheDifSides(p1, p2, lv)) {
          inside = !inside;
          if (!inside)
            res += Dist(prevP, pa.first);
          else
            prevP = pa.first;
        }
        ++j;
      } else {
        inside = !inside;
        if (!inside)
          res += Dist(prevP, pa.first);
        else
          prevP = pa.first;
      }
    }
    out << res / 100 << '\n';
  }
}
