#include <bits/stdc++.h>
using namespace std;
#define rep2(i, a, n) for(int i = a; i <= n; ++i)
#define rep(i, n) rep2(i, 0, n - 1)

using Real = double;
using Point = complex<Real>;
istream &operator>>(istream &is, Point &p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}
#define x real()
#define y imag()
ostream &operator<<(ostream &os, Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
const Real EPS = 1e-8, PI = acos(-1);
inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }
namespace std {
bool operator<(const Point &a, const Point &b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
} // namespace std
Point operator*(const Point &p, const Real &d) { return Point(p.x * d, p.y * d); }
struct Segment {
    Point a, b;
    Segment() = default;
    Segment(Point a, Point b) : a(a), b(b) {}
};
Real dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
Real cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
Point proj(const Segment &l, const Point &p) {
    Real t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return 1;
    if(cross(b, c) < -EPS) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }
Real Dist(const Point &p, const Segment &s) {
    Point r = proj(s, p);
    if(intersect(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
Real Dist(const Segment &s, const Point &p) { return Dist(p, s); }
Real Dist(const Segment a, const Segment b) {
    if(intersect(a, b)) return 0;
    return min({Dist(a, b.a), Dist(a, b.b), Dist(b, a.a), Dist(b, a.b)});
}

using Polygon = vector<Point>;
ostream &operator<<(ostream &os, Polygon p) {
    rep(i, p.size()) os << p[i] << " ";
    return os;
}
Polygon convexHull(Polygon &p) {
    int n = p.size(), k = 0;
    if(n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Point> ch(2 * n);
    for(int i = 0; i < n; ch[k++] = p[i++]) {
        while(k >= 2 and cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
    }
    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while(k >= t and cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
    }
    ch.resize(k - 1);
    return ch;
}

int contains(const Polygon &Q, const Point &p) {
    bool in = false;
    for(int i = 0; i < Q.size(); i++) {
        Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
        if(a.y > b.y) swap(a, b);
        if(a.y <= 0 and 0 < b.y and cross(a, b) < 0) in = !in;
        if(cross(a, b) == 0 and dot(a, b) <= 0) return 1;
    }
    return in;
}
Real D(Polygon a, Polygon b) {
    int n = a.size(), m = b.size();
    double d = 1e18;
    rep(i, n) if(contains(b, a[i])) return (Real)0;
    rep(i, m) if(contains(a, b[i])) return (Real)0;
    rep(i, n) {
        rep(j, m) { d = min(d, Dist(Segment(a[i], a[(i + 1) % n]), Segment(b[j], b[(j + 1) % m]))); }
    }
    rep(i, n) rep(j, m) d = min(d, Dist(Segment(a[i], a[(i + 1) % n]), b[j])), d = min(d, Dist(Segment(b[j], b[(j + 1) % m]), a[i]));
    rep(i, n) rep(j, m) d = min(d, abs(a[i] - b[j]));
    return d;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    while(1) {
        cin >> n;
        if(!n) return 0;
        vector<Polygon> P(n), Q(n);
        vector<double> H(n);
        rep(i, n) {
            int v;
            cin >> v;
            cin >> H[i];
            P[i].resize(v);
            rep(j, v) cin >> P[i][j];
        }
        double theta, phi;
        cin >> theta >> phi;
        theta *= PI * 2, phi *= PI * 2;
        theta /= 360, phi /= 360;
        rep(i, n) {
            int v = P[i].size();
            double r = H[i] / tan(phi);
            Point p(r * cos(theta + PI), r * sin(theta + PI));
            rep(j, v) { P[i].emplace_back(P[i][j] + p); }
            P[i] = convexHull(P[i]);
        }
        vector<vector<Real>> d(n + 2, vector<Real>(n + 2, 1e18));
        Point s, t;
        cin >> s >> t;
        P.emplace_back(Polygon{s}), P.emplace_back(Polygon{t});
        rep(i, n + 2) rep(j, n + 2) {
            if(i <= j) continue;
            d[i][j] = d[j][i] = D(P[i], P[j]);
        }
        rep(k, n + 2) rep(i, n + 2) rep(j, n + 2) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
        cout << d[n][n + 1] << endl;
    }
}
