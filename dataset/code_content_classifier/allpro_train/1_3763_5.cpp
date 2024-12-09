#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, PI = acos(-1);
inline int sig(double a) { return (a > eps) - (a < -eps); }
using CP = const struct P &;
struct P {
  double x, y;
  P() : P(0, 0) {}
  P(double x, double y) : x(x), y(y) {}
  void read() { scanf("%lf%lf", &x, &y); }
  void log() { fprintf(stderr, "%g %g\n", x, y); }
  P operator+(CP b) const { return P(x + b.x, y + b.y); }
  P operator-(CP b) const { return P(x - b.x, y - b.y); }
  P operator*(double a) const { return P(a * x, a * y); }
  P operator/(double a) const { return P(x / a, y / a); }
  P to(CP a) const { return a - *this; }
  double operator*(CP b) const { return x * b.x + y * b.y; }
  double operator%(CP b) const { return x * b.y - y * b.x; }
  double operator/(CP b) const { return (*this * b) / b.norm(); }
  double dot(CP a, CP b) const { return to(a) * to(b); }
  double cross(CP a, CP b) const { return to(a) % to(b); }
  double angle(CP a, CP b) const {
    double t = atan2(b.y - y, b.x - x) - atan2(a.y - y, a.x - x);
    while (sig(t) < 0) t += 2 * PI;
    while (sig(t - 2 * PI) >= 0) t -= 2 * PI;
    return t;
  }
  double norm2() const { return x * x + y * y; }
  double norm() const { return hypot(x, y); }
  bool operator<(CP b) const {
    return sig(x - b.x) ? x < b.x : sig(y - b.y) < 0;
  }
  bool operator==(CP b) const { return !sig(x - b.x) && !sig(y - b.y); }
  bool on_seg(CP a, CP b) const {
    return !sig(cross(a, b)) && sig(dot(a, b)) < 1;
  }
  int in(const P *a, int n) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      const P &s = a[i], &t = a[(i + 1) % n];
      if (on_seg(s, t)) return 0;
      c += (sig(s.y - y) <= 0 && sig(t.y - y) > 0 && sig(cross(t, s)) > 0);
      c += (sig(s.y - y) > 0 && sig(t.y - y) <= 0 && sig(cross(s, t)) > 0);
    }
    return c % 2 * 2 - 1;
  }
  int in(const vector<P> &a) { return in(&a[0], a.size()); }
};
int cut(CP a, CP b, CP c, CP d) {
  if (a.on_seg(c, d) || b.on_seg(c, d) || c.on_seg(a, b) || d.on_seg(a, b))
    return 0;
  if (sig(a.cross(b, c) * a.cross(b, d)) < 0 &&
      sig(c.cross(d, a) * c.cross(d, b)) < 0)
    return 1;
  return -1;
}
int intersect(CP a, CP b, CP c, CP d, P *p) {
  if (cut(a, b, c, d) < 0) return 0;
  P u = b - a, v = d - c, w = d - a;
  double t = u % v;
  if (sig(t))
    *p = a + u * (w % v / t);
  else if ((!sig(a.dot(b, c)) && sig(a.dot(b, d)) < 1) ||
           (!sig(a.dot(b, d)) && sig(a.dot(b, c)) < 1))
    *p = a;
  else if ((!sig(b.dot(a, c)) && sig(b.dot(a, d)) < 1) ||
           (!sig(b.dot(a, d)) && sig(b.dot(a, c)) < 1))
    *p = b;
  else if (c == d)
    *p = c;
  else
    return -1;
  return 1;
}
double darea(const P *a, int n) {
  double ans = 0;
  for (int i = 1; i < n - 1; ++i) ans += a[0].cross(a[i], a[i + 1]);
  return ans / 2;
}
double darea(const vector<P> &a) { return darea(&a[0], a.size()); }
double w, h;
int n, m;
vector<pair<P, P>> isegs;
set<P> pts;
vector<P> ptv;
struct Sg {
  int id, ai, bi;
  P &a() { return ptv[ai]; }
  P &b() { return ptv[bi]; }
  int other_end(int x) { return ai + bi - x; }
};
vector<Sg> segs;
struct G {
  int id;
  double area;
  vector<P> a;
  vector<int> s;
  bool operator<(const G &o) const { return area < o.area; }
};
vector<G> gons;
const int N = 1.1e5;
int top = 0;
vector<int> e[N];
string c[N];
vector<int> pe[N];
void adde(int x, int y) { e[x].push_back(y), e[y].push_back(x); }
void dfs(int id, const string &newc) {
  string oldc = c[id];
  if (oldc == newc) return;
  c[id] = newc;
  for (int x : e[id])
    if (c[x] == oldc) dfs(x, newc);
}
int main() {
  scanf("%lf%lf%d", &w, &h, &n);
  for (int i = 0; i < n; ++i) {
    P p, q;
    p.read();
    q.read();
    if (q < p) swap(p, q);
    isegs.emplace_back(p, q);
    pts.insert(p);
    pts.insert(q);
  }
  sort(isegs.begin(), isegs.end());
  for (size_t i = 1; i < isegs.size(); ++i) {
    bool ok = true;
    P p = isegs[i].first, q = isegs[i].second;
    for (size_t j = 0; j < i; ++j) {
      P r;
      int test = intersect(isegs[j].first, isegs[j].second, p, q, &r);
      if (test > 0) pts.insert(r);
      if (test < 0) {
        isegs[j].first = min(isegs[j].first, p);
        isegs[j].second = max(isegs[j].second, q);
        ok = false;
      }
    }
    if (!ok) {
      isegs[i] = isegs.back();
      isegs.pop_back();
      --i;
    }
  }
  ptv.insert(ptv.end(), pts.begin(), pts.end());
  for (auto &s : isegs) {
    vector<int> ps;
    for (int i = 0; i < (int)ptv.size(); ++i)
      if (ptv[i].on_seg(s.first, s.second)) ps.push_back(i);
    for (int i = 1; i < (int)ps.size(); ++i) {
      Sg sg;
      sg.id = ++top;
      sg.ai = ps[i - 1];
      sg.bi = ps[i];
      c[top] = "black";
      pe[sg.ai].push_back(segs.size());
      pe[sg.bi].push_back(segs.size());
      segs.push_back(sg);
    }
  }
  for (int i = 0; i < (int)segs.size(); ++i)
    for (int j = 0; j < i; ++j)
      if (cut(segs[i].a(), segs[i].b(), segs[j].a(), segs[j].b()) >= 0)
        adde(segs[i].id, segs[j].id);
  {
    G og;
    c[og.id = ++top] = "white";
    og.area = w * h;
    og.a = {{0, 0}, {w, 0}, {w, h}, {0, h}};
    gons.push_back(og);
  }
  for (int i = 0; i < (int)ptv.size(); ++i) {
    for (int j = 0; j < (int)pe[i].size(); ++j) {
      Sg sg = segs[pe[i][j]];
      int x = i, y = sg.other_end(i);
      vector<P> ps = {ptv[x]};
      vector<int> ss = {sg.id};
      while (y != i) {
        double ma = -1;
        int xi = -1;
        for (int k = 0; k < (int)pe[y].size(); ++k) {
          int z = segs[pe[y][k]].other_end(y);
          double ang = ptv[y].angle(ptv[x], ptv[z]);
          if (ang > ma) {
            ma = ang;
            xi = k;
          }
        }
        assert(xi >= 0);
        sg = segs[pe[y][xi]];
        int ny = sg.other_end(y);
        pe[y][xi] = pe[y].back();
        pe[y].pop_back();
        ps.push_back(ptv[y]);
        ss.push_back(sg.id);
        x = y;
        y = ny;
      };
      double area = darea(ps);
      if (sig(area) <= 0) {
        for (int k = (int)gons.size() - 1; k >= 0; --k)
          if (ps[0].in(gons[k].a) > 0) {
            gons[k].area += area;
            for (int si : ss) adde(gons[k].id, si);
            break;
          }
        continue;
      }
      G g;
      g.id = ++top;
      g.a = ps;
      g.s = ss;
      g.area = area;
      c[top] = "white";
      gons.push_back(g);
      for (int si : ss) adde(top, si);
    }
    pe[i].clear();
  }
  sort(gons.begin(), gons.end());
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    P p;
    p.read();
    string s;
    cin >> s;
    bool done = false;
    for (auto &sg : segs)
      if (p.on_seg(sg.a(), sg.b())) {
        dfs(sg.id, s);
        done = true;
        break;
      }
    if (!done)
      for (auto &g : gons)
        if (p.in(g.a) > 0) {
          dfs(g.id, s);
          break;
        }
  }
  map<string, double> res;
  for (auto &g : gons)
    if (sig(g.area) > 0) res[c[g.id]] += g.area;
  for (auto &sg : segs) res[c[sg.id]] += 0;
  for (auto &p : res) printf("%s %.9lf\n", p.first.c_str(), p.second);
}
