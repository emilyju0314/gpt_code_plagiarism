#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
template <typename T>
T K(T a) {
  return a * a;
}
typedef long double ll;
const long double eps = 1e-12;
#pragma GCC diagnostic ignored "-Wnarrowing"
struct P {
  ll x, y;
  P operator+(P he) { return P{x + he.x, y + he.y}; }
  P operator-(P he) { return P{x - he.x, y - he.y}; }
  ll operator*(P he) { return x * he.y - y * he.x; }
  P operator*(ll mul) { return P{x * mul, y * mul}; }
  P operator/(ll mul) { return P{x / mul, y / mul}; }
  ll dot(P b) { return x * b.x + y * b.y; }
  long double len() { return sqrt(K(1LL * (x)) + K(1LL * (y))); }
  P scaleTo(long double to) { return *this * (to / len()); }
  long double dist(P& b) { return (*this - b).len(); }
  P rotate90() { return P{-y, x}; }
  long double angle() { return atan2(y, x); }
  P rotate(long double ang) {
    long double c = cos(ang), s = sin(ang);
    return P{x * c - y * s, x * s + y * c};
  }
  bool operator<(P he) { return make_pair(x, y) < make_pair(he.x, he.y); }
  bool below(P a, P b) { return (b - a) * (*this - a) <= 0; }
  P apol_in(P b, long double ratio) {
    return (*this + b * ratio) / (1 + ratio);
  }
  P apol_out(P b, long double ratio) {
    return (*this - b * ratio) / (1 - ratio);
  }
};
debug& operator<<(debug& dd, P p) {
  dd << "(" << p.x << ", " << p.y << ")";
  return dd;
}
struct L2 {
  P one, two;
  P dir() { return two - one; }
  P normal() { return dir().rotate90(); }
  long double dist(P he) {
    return abs((he - one) * (he - two)) / one.dist(two);
  }
  long double segDist(P he) {
    if ((he - two) * normal() < 0 && normal() * (he - one) < 0) return dist(he);
    return min(one.dist(he), two.dist(he));
  }
  P inter(L2 he) {
    P A = dir(), B = he.dir();
    ll den = A * B;
    assert(abs(den) > eps);
    return (A * (he.one * he.two) - B * (one * two)) * (1.0 / den);
  }
  P project(P he) {
    P unit_normal = normal().scaleTo(1);
    return he + unit_normal * unit_normal.dot(one - he);
  }
  P reflect(P he) { return project(he) * 2 - he; }
};
L2 toL2(ll a, ll b, ll c) {
  P first;
  if (abs(b) > eps)
    first = P{0, (long double)-c / b};
  else if (abs(a) > eps)
    first = P{(long double)-c / a, 0};
  else
    assert(false);
  return L2{first, first + P{b, -a}};
}
ll det(ll t[3][3]) {
  ll s = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = i + 1, mul = 1; j != i + 3; ++j, mul -= 2)
      s += t[0][i] * t[1][j % 3] * t[2][3 - i - j % 3] * mul;
  return s;
}
struct L3 {
  ll a, b, c;
  L3 fix() {
    assert(abs(b) > eps || abs(a) > eps);
    ll g = (b > eps || (abs(b) < eps && a > eps)) ? 1 : -1;
    return L3{a / g, b / g, c / g};
  }
  long double dist(P he) {
    return abs(a * he.x + b * he.y + c) / sqrt(K(1LL * (a)) + K(1LL * (b)));
  }
  P dir() { return P{b, -a}; }
  P normal() { return P{a, b}; }
  P project(P he) {
    long double den = K(1LL * (a)) + K(1LL * (b));
    return P{(b * (b * he.x - a * he.y) - a * c) / den,
             (a * (a * he.y - b * he.x) - b * c) / den};
  }
  P reflect(P he) { return project(he) * 2 - he; }
  P inter(L3 he) {
    ll den = (a * he.b - b * he.a);
    assert(abs(den) > 1e-14);
    return P{(b * he.c - c * he.b), (c * he.a - a * he.c)} * (1.0 / den);
  }
  bool operator<(L3 he) {
    if (abs(a * he.b - b * he.a) < eps) return b * he.c < c * he.b;
    return a * he.b < b * he.a;
  }
  bool below(L3 A, L3 C) {
    ll t[3][3] = {{A.a, A.b, A.c}, {a, b, c}, {C.a, C.b, C.c}};
    return det(t) <= 0;
  }
};
L3 toL3(P one, P two) {
  ll a = two.y - one.y;
  ll b = one.x - two.x;
  return L3{a, b, -(a * one.x + b * one.y)}.fix();
}
const int INF = 1e6 + 5;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<P> poly(n);
  for (P& p : poly) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = P{x, y};
  }
  ll area = 0;
  for (int i = 0; i < n; ++i) {
    area += poly[i] * poly[(i + 1) % n];
  }
  if (area > 0) {
    debug() << "REVERSE";
    reverse(poly.begin(), poly.end());
  }
  area = abs(area) / 2;
  vector<P> left, right;
  int lowest = 0;
  for (int i = 1; i < n; ++i) {
    if (poly[i].y < poly[lowest].y) {
      lowest = i;
    }
  }
  debug() << " ["
          << "lowest"
             ": "
          << (lowest) << "] ";
  for (int i = lowest;;) {
    left.push_back(poly[i]);
    int j = (i + 1) % n;
    if (poly[j].y < poly[i].y) {
      break;
    }
    i = j;
  }
  debug() << " ["
          << "left"
             ": "
          << (left) << "] ";
  for (int i = lowest;;) {
    right.push_back(poly[i]);
    int j = (i + n - 1) % n;
    if (poly[j].y < poly[i].y) {
      break;
    }
    i = j;
  }
  debug() << " ["
          << "right"
             ": "
          << (right) << "] ";
  vector<vector<P>> triples;
  triples.push_back({left[0], left[0], left[0]});
  {
    int j = 1;
    for (int i = 1; i < (int)left.size(); ++i) {
      while (j < (int)right.size() - 1 && right[j].y < left[i].y) {
        L2 one{left[i], left[i - 1]};
        L2 two{right[j], right[j] - P{INF, 0}};
        P inter = one.inter(two);
        triples.push_back({inter, (inter + right[j]) / 2, right[j]});
        j++;
      }
      if (i == (int)left.size() - 1) {
        break;
      }
      L2 one{right[j], right[j - 1]};
      L2 two{left[i], left[i] + P{INF, 0}};
      P inter = one.inter(two);
      triples.push_back({left[i], (left[i] + inter) / 2, inter});
    }
    triples.push_back({left.back(), left.back(), left.back()});
  }
  debug() << " ["
          << "triples"
             ": "
          << (triples) << "] ";
  vector<pair<long double, pair<int, int>>> events;
  for (int i = 0; i < (int)triples.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      events.emplace_back(triples[i][j].x, make_pair(i, j));
    }
  }
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    events.emplace_back(x, make_pair(-1, i));
  }
  sort(events.begin(), events.end());
  vector<long double> answer(q);
  vector<vector<bool>> on(triples.size(), vector<bool>(3));
  long double a1 = 0, b1 = 0, c1 = 0;
  for (pair<long double, pair<int, int>> event : events) {
    long double x = event.first;
    pair<int, int> para = event.second;
    if (para.first == -1) {
      long double s = a1 * x * x + b1 * x + c1;
      debug() << "query"
                 " ["
              << "x"
                 ": "
              << (x)
              << "] "
                 " ["
              << "s"
                 ": "
              << (s)
              << "] "
                 " ["
              << "para.second"
                 ": "
              << (para.second) << "] ";
      answer[para.second] = s;
    } else {
      int i = para.first;
      int j = para.second;
      debug() << " ["
              << "i"
                 ": "
              << (i)
              << "] "
                 " ["
              << "j"
                 ": "
              << (j) << "] ";
      long double mul = 1;
      if (j == 1) {
        mul = -2;
      }
      if (j == 2) {
        mul = 1;
      }
      for (int i2 : {i - 1, i + 1}) {
        if (0 <= i2 && i2 < (int)triples.size()) {
          P A = triples[i][j];
          P B = triples[i2][j];
          if (abs(A.x - B.x) >= 1e-7) {
            long double a = abs(A.y - B.y) / abs(A.x - B.x);
            if (!on[i2][j]) {
              long double tmp = a * mul / 2;
              a1 += tmp;
              b1 -= 2 * tmp * x;
              c1 += tmp * x * x;
            } else {
              long double tmp = a * -mul / 2;
              a1 += tmp;
              b1 -= 2 * tmp * B.x;
              c1 += tmp * B.x * B.x;
            }
          }
          if (!on[i2][j]) {
          } else {
            c1 += mul * abs(A.y - B.y) * abs(A.x - B.x) / 2;
            b1 += mul * abs(A.y - B.y);
            c1 -= x * mul * abs(A.y - B.y);
          }
        }
      }
      on[i][j] = true;
    }
  }
  for (long double x : answer) {
    printf("%.10lf\n", (double)(area - x));
  }
}
