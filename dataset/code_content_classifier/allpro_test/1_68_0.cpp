#include <bits/stdc++.h>
using namespace std;
using Point = complex<int>;
using ll = long long;
ll cross(Point a, Point b) {
  return 1LL * a.real() * b.imag() - 1LL * b.real() * a.imag();
}
ll det(Point a, Point b, Point c) { return cross(b - a, c - a); }
namespace std {
bool operator<(const Point& a, const Point& b) {
  return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
}
}  // namespace std
struct DynHull {
  struct Node {
    int bl, br, l, r, lc, rc;
  };
  vector<Node> T = {{-1, -1, -1, -1, 0, 0}};
  vector<Point> P;
  DynHull(vector<Point> P) : P(P) {}
  bool leaf(int x) { return T[x].l == T[x].r; }
  int combine(int lc, int rc, int ret = -1) {
    if (!lc || !rc) return lc + rc;
    if (ret == -1 || ret == lc || ret == rc) ret = T.size(), T.push_back({});
    T[ret] = {-1, -1, T[lc].l, T[rc].r, lc, rc};
    while (!leaf(lc) || !leaf(rc)) {
      int a = T[lc].bl, b = T[lc].br, c = T[rc].bl, d = T[rc].br;
      if (a != b && det(P[a], P[b], P[c]) > 0) {
        lc = T[lc].lc;
      } else if (c != d && det(P[b], P[c], P[d]) > 0) {
        rc = T[rc].rc;
      } else if (a == b) {
        rc = T[rc].lc;
      } else if (c == d) {
        lc = T[lc].rc;
      } else {
        auto s1 = det(P[a], P[b], P[c]), s2 = det(P[a], P[b], P[d]);
        assert(s1 >= s2);
        auto xc = P[c].real(), xd = P[d].real(), xm = P[T[rc].l].real();
        if (s1 == s2 || s1 * xd - s2 * xc < (s1 - s2) * xm) {
          lc = T[lc].rc;
        } else {
          rc = T[rc].lc;
        }
      }
    }
    T[ret].bl = T[lc].l;
    T[ret].br = T[rc].l;
    return ret;
  }
  int Build(int b, int e) {
    if (e - b == 1) {
      T.push_back({b, b, b, b, 0, 0});
      return T.size() - 1;
    }
    int m = (b + e) / 2;
    return combine(Build(b, m), Build(m, e));
  }
  int Erase(int x, int pos) {
    if (!x || T[x].r < pos || T[x].l > pos) return x;
    return leaf(x) ? 0 : combine(Erase(T[x].lc, pos), Erase(T[x].rc, pos), x);
  }
  template <typename Callback>
  void Hull(int x, Callback&& cb, int l = 0, int r = 1e9) {
    if (!x || l > r) return;
    if (leaf(x)) {
      cb(T[x].l);
      return;
    }
    Hull(T[x].lc, cb, l, min(r, T[x].bl));
    Hull(T[x].rc, cb, max(l, T[x].br), r);
  }
};
inline ll area(Point a, Point b, Point c) {
  return (ll)(b.real() - a.real()) * (c.imag() - a.imag()) -
         (ll)(b.imag() - a.imag()) * (c.real() - a.real());
}
vector<Point> convexHull(vector<Point> p) {
  int n = p.size(), m = 0;
  if (n < 3) return p;
  vector<Point> hull(n + n);
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    while (m > 1 and area(hull[m - 2], hull[m - 1], p[i]) <= 0) --m;
    hull[m++] = p[i];
  }
  for (int i = n - 2, j = m + 1; i >= 0; --i) {
    while (m >= j and area(hull[m - 2], hull[m - 1], p[i]) <= 0) --m;
    hull[m++] = p[i];
  }
  hull.resize(m - 1);
  return hull;
}
const int LG = 18;
const int N = 100010;
int q, par[LG][N];
inline int prv(int i, int n) { return (i ? i : n) - 1; }
inline int nxt(int i, int n) { return i + 1 < n ? i + 1 : 0; }
int kthPar(int u, int k) {
  for (int i = LG - 1; i >= 0; --i) {
    assert(u != -1);
    if (k & 1 << i) k ^= 1 << i, u = par[i][u];
  }
  return u;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<Point, int>> pts(n);
  map<Point, int> id;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    pts[i] = make_pair(Point{x, y}, i);
    id[Point{x, y}] = i;
  }
  if (n == 1) {
    cin >> q;
    while (q--) cout << 1 << '\n';
    return 0;
  }
  vector<pair<Point, int>> pts_copy = pts;
  sort(pts.begin(), pts.end());
  vector<Point> P(n);
  vector<int> remap(n);
  for (int i = 0; i < n; ++i) {
    remap[i] = pts[i].second;
    P[i] = pts[i].first;
  }
  auto LH = DynHull(P);
  int lh = LH.Build(0, n);
  for (int i = 0; i < n; ++i) P[i] = -P[i];
  reverse(P.begin(), P.end());
  auto UH = DynHull(P);
  int uh = UH.Build(0, n);
  vector<int> layer(n, -1);
  for (int i = 0;; ++i) {
    vector<int> all;
    LH.Hull(lh, [&](int x) { all.push_back(x); });
    UH.Hull(uh, [&](int x) { all.push_back(n - x - 1); });
    if (all.empty()) break;
    for (auto x : all) {
      lh = LH.Erase(lh, x);
      uh = UH.Erase(uh, n - x - 1);
      layer[remap[x]] = i;
    }
  }
  int up = *max_element(layer.begin(), layer.end()) + 1;
  vector<vector<Point>> layers(up);
  for (int i = 0; i < n; ++i) {
    layers[layer[i]].emplace_back(pts_copy[i].first);
  }
  for (int i = 0; i < up; ++i) layers[i] = convexHull(layers[i]);
  vector<int> pf(up);
  for (int i = 0; i < up; ++i) {
    pf[i] = layers[i].size();
    if (i) pf[i] += pf[i - 1];
  }
  vector<int> whichLayer(n), whichPos(n);
  for (int i = 0; i < up; ++i) {
    for (int j = 0; j < layers[i].size(); ++j) {
      auto x = layers[i][j];
      whichLayer[id[x]] = i, whichPos[id[x]] = j;
    }
  }
  memset(par, -1, sizeof par);
  for (int i = 0; i + 1 < up; ++i) {
    if (layers[i + 1].size() == 1) {
      int to = id[layers[i + 1][0]];
      for (auto x : layers[i]) par[0][id[x]] = to;
      continue;
    }
    int k = 0, sz = layers[i + 1].size();
    vector<int> to(layers[i].size());
    for (int j = 0; j < layers[i].size(); ++j) {
      while (area(layers[i][j], layers[i + 1][k], layers[i + 1][nxt(k, sz)]) <
             0)
        k = nxt(k, sz);
      while (area(layers[i][j], layers[i + 1][prv(k, sz)], layers[i + 1][k]) >
             0)
        k = prv(k, sz);
      to[j] = k;
    }
    for (int j = 0; j < layers[i].size(); ++j) {
      int u = id[layers[i][j]],
          v = id[layers[i + 1][to[prv(j, layers[i].size())]]];
      par[0][u] = v;
    }
  }
  for (auto x : layers[up - 1]) par[0][id[x]] = n;
  for (int j = 1; j < LG; ++j) {
    for (int i = 0; i <= n; ++i)
      if (par[j - 1][i] != -1) {
        par[j][i] = par[j - 1][par[j - 1][i]];
      }
  }
  int sz = layers[0].size();
  vector<pair<long double, int>> vec;
  for (int i = 0; i < sz; ++i) {
    Point cur = layers[0][nxt(i, sz)] - layers[0][i];
    vec.emplace_back(atan2l(cur.imag(), cur.real()), i);
  }
  sort(vec.begin(), vec.end());
  cin >> q;
  while (q--) {
    int dx, dy, k;
    cin >> dx >> dy >> k;
    long double ang = atan2l(dy, dx);
    int pos = -1;
    auto it = upper_bound(vec.begin(), vec.end(), make_pair(ang, 696969));
    if (it == vec.end())
      pos = vec[0].second;
    else
      pos = it->second;
    int where = lower_bound(pf.begin(), pf.end(), k) - pf.begin();
    int ext = k - (where ? pf[where - 1] : 0);
    int at = kthPar(id[layers[0][pos]], where);
    assert(at != n);
    int final = (whichPos[at] + ext - 1) % (int)layers[where].size();
    int ans = id[layers[where][final]];
    printf("%d\n", ans + 1);
  }
  return 0;
}
