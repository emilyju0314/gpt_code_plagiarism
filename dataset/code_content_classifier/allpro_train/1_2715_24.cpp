#include <bits/stdc++.h>
using namespace std;
double eps = 1e-12;
const double inf = 1e9;
const int ops = 100;
bool lt(double a, double b) { return b - a > eps; }
bool eq(double a, double b) { return abs(a - b) <= eps; }
bool leq(double a, double b) { return lt(a, b) || eq(a, b); }
bool gt(double a, double b) { return a - b > eps; }
bool geq(double a, double b) { return gt(a, b) || eq(a, b); }
struct pt {
  double x, y;
  pt() {}
  pt(double x, double y) : x(x), y(y) {}
  pt operator-(const pt& other) const { return {x - other.x, y - other.y}; }
  pt operator+(const pt& other) const { return {x + other.x, y + other.y}; }
  pt operator*(double k) const { return {x * k, y * k}; }
};
bool eq(const pt& p, const pt& q) { return eq(p.x, q.x) && eq(p.y, q.y); }
bool is_zero(const pt& p) { return eq(p.x, 0) && eq(p.y, 0); }
double cross(const pt& p, const pt& q) { return p.x * q.y - p.y * q.x; }
double dot(const pt& p, const pt& q) { return p.x * q.x + p.y * q.y; }
double area(const pt& a, const pt& b, const pt& c) {
  return cross(b - a, c - a);
}
double len(const pt& p) { return sqrt(p.x * p.x + p.y * p.y); }
bool inside(const pt& p, const vector<pt>& v) {
  double s = 0;
  double ans = 0;
  int n = (int)(v).size();
  for (int i = 0; i < n; ++i) {
    s += abs(area(p, v[i], v[(i + 1) % n]));
    ans += area(p, v[i], v[(i + 1) % n]);
  }
  return eq(s, abs(ans));
}
bool on_seg(const pt& p, const pt& a, const pt& b) {
  return leq(dot(a - p, b - p), 0);
}
struct line {
  double a, b, c;
  line() {}
  line(const pt& p, const pt& q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = cross(p, q);
  }
};
bool on_line(const pt& p, const line& l, bool flag = false) {
  if (flag) {
    cout << "ON " << l.a * p.x + l.b * p.y + l.c << "\n";
  }
  return eq(l.a * p.x + l.b * p.y + l.c, 0);
}
vector<pt> intersect(const line& l, const line& m) {
  double a1 = l.a, b1 = l.b, c1 = -l.c;
  double a2 = m.a, b2 = m.b, c2 = -m.c;
  double det = a1 * b2 - a2 * b1;
  if (eq(det, 0)) {
    return {};
  }
  double det1 = c1 * b2 - c2 * b1;
  double det2 = a1 * c2 - a2 * c1;
  return {{det1 / det, det2 / det}};
}
vector<pt> intersect(const pt& a, const pt& b, const pt& c, const pt& d) {
  line l(a, b), m(c, d);
  vector<pt> v = intersect(l, m);
  vector<pt> ans;
  for (pt& p : v) {
    if (on_seg(p, a, b) && on_seg(p, c, d)) {
      ans.push_back(p);
    }
  }
  if (on_line(a, m) && on_seg(a, c, d)) {
    ans.push_back(a);
  }
  if (on_line(b, m) && on_seg(b, c, d)) {
    ans.push_back(b);
  }
  if (on_line(c, l) && on_seg(c, a, b)) {
    ans.push_back(c);
  }
  if (on_line(d, l) && on_seg(d, a, b)) {
    ans.push_back(d);
  }
  return ans;
}
vector<pt> intersect(const pt& a, const pt& b, const line& l) {
  line m(a, b);
  vector<pt> ans = intersect(l, m);
  if ((int)(ans).size() == 1 && !on_seg(ans[0], a, b)) {
    ans.pop_back();
  }
  if (on_line(a, l)) {
    ans.push_back(a);
  }
  if (on_line(b, l)) {
    ans.push_back(b);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << fixed;
  cout.precision(12);
  vector<pt> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  pt a;
  cin >> a.x >> a.y;
  pt v;
  cin >> v.x >> v.y;
  double z1;
  cin >> z1;
  double fdown;
  cin >> fdown;
  fdown = -fdown;
  pt u;
  cin >> u.x >> u.y;
  double z2;
  cin >> z2;
  z2 = -z2;
  if (is_zero(v) && is_zero(u)) {
    cout << "-1 -1\n";
    return 0;
  }
  double t1_ans;
  if (!eq(cross(v, u), 0)) {
    double lf = 0, rg = inf;
    for (int step = 0; step < ops; ++step) {
      double t1 = (lf + rg) / 2.0;
      pt b = a + v * t1;
      pt c = b + u * (z1 * t1 / z2);
      vector<pt> triangle = {a, b, c};
      bool ok = false;
      for (int i = 0; i < n; ++i) {
        if (inside(p[i], triangle)) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        for (int i = 0; i < n; ++i) {
          vector<pt> vv = intersect(a, b, p[i], p[(i + 1) % n]);
          if (!vv.empty()) {
            ok = true;
            break;
          }
          vv = intersect(b, c, p[i], p[(i + 1) % n]);
          if (!vv.empty()) {
            ok = true;
            break;
          }
          vv = intersect(c, a, p[i], p[(i + 1) % n]);
          if (!vv.empty()) {
            ok = true;
            break;
          }
        }
      }
      if (ok) {
        rg = t1;
      } else {
        lf = t1;
      }
    }
    t1_ans = rg;
  } else {
    double t1 = inf;
    line l;
    if (is_zero(u)) {
      l = line(a, a + v);
    } else {
      l = line(a, a + u);
    }
    pt w = v + u * (z1 / z2);
    for (int i = 0; i < n; ++i) {
      vector<pt> vv = intersect(p[i], p[(i + 1) % n], l);
      for (pt& q : vv) {
        if (!is_zero(v)) {
          double val = len(q - a) / len(v);
          if (eq(v * val, q - a) && gt(t1, val)) {
            t1 = val;
          }
        }
        if (!is_zero(w)) {
          double val = len(q - a) / len(w);
          if (eq(w * val, q - a) && gt(t1, val)) {
            t1 = val;
          }
        }
      }
    }
    t1_ans = t1;
  }
  if (eq(t1_ans, inf)) {
    cout << "-1 -1\n";
    return 0;
  }
  cout << t1_ans << " ";
  if (is_zero(u)) {
    cout << "0\n";
    return 0;
  }
  eps = 1e-8;
  pt magic = a + v * t1_ans;
  pt border = magic + u * (z1 * t1_ans / z2);
  line l(magic, border);
  for (int i = 0; i < n; ++i) {
    if (on_line(p[i], l) && on_seg(p[i], magic, border)) {
      magic = p[i];
    }
    if (eq(magic, border)) {
      break;
    }
    vector<pt> vv = intersect(a + v * t1_ans, border, p[i], p[(i + 1) % n]);
    for (pt& q : vv) {
      if (on_seg(q, magic, border)) {
        magic = q;
      }
      if (eq(magic, border)) {
        break;
      }
    }
  }
  t1_ans += eps;
  pt magic2 = a + v * t1_ans;
  pt border2 = a + v * t1_ans + u * (z1 * t1_ans / z2);
  for (int i = 0; i < n; ++i) {
    if (on_line(p[i], l) && on_seg(p[i], magic2, border2)) {
      magic2 = p[i];
    }
    if (eq(magic2, border2)) {
      break;
    }
    vector<pt> vv = intersect(a + v * t1_ans, border2, p[i], p[(i + 1) % n]);
    for (pt& q : vv) {
      if (on_seg(q, magic2, border2)) {
        magic2 = q;
      }
      if (eq(magic2, border2)) {
        break;
      }
    }
  }
  double val = len(magic - (a + v * t1_ans));
  double val2 = len(magic2 - (a + v * t1_ans));
  if (lt(val, val2)) {
    val = val2;
  }
  double par = val / len(u);
  double ans = (z1 * t1_ans - par * z2) / fdown + eps;
  cout << ans << "\n";
}
