#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using D = double;
const D PI = acos(D(-1)), EPS = 1e-8;

int sgn(D a) { return (abs(a) <= EPS) ? 0 : (a < 0 ? -1 : 1); }
int sgn(D a, D b) { return sgn(a-b); }

struct Pt2 {
    D x, y;
    Pt2() {}
    Pt2(D _x, D _y) : x(_x), y(_y) {}
    Pt2 operator+(const Pt2 &r) const { return Pt2(x+r.x, y+r.y); }
    Pt2 operator-(const Pt2 &r) const { return Pt2(x-r.x, y-r.y); }
    Pt2 operator*(const Pt2 &r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x); }

    Pt2 operator*(const D &r) const { return Pt2(x*r, y*r); }
    bool operator<(const Pt2 &r) const { return 2*sgn(x, r.x)+sgn(y, r.y)<0; }

    D norm() const { return x*x + y*y; }
    D abs() const { return sqrt(norm()); }
    D rabs() const { return max(std::abs(x), std::abs(y)); }
    D arg() const { return atan2(y, x); }
    static Pt2 polar(D le, D th) { return Pt2(le*cos(th), le*sin(th)); }
};
ostream& operator<<(ostream& os, const Pt2 &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
using P = Pt2;

struct L {
    P s, t;
    L() {}
    L(P _s, P _t) : s(_s), t(_t) {}
    P vec() const { return t-s; }
};

D cross(P a, P b) { return a.x*b.y - a.y*b.x; }

int sgncrs(P a, P b) {
    D cr = cross(a, b);
    if (abs(cr) <= (a.rabs() + b.rabs()) * EPS) return 0;
    return (cr < 0) ? -1 : 1;
}

int crossLL(const L &l, const L &m, P &r) {
    D cr1 = cross(l.vec(), m.vec()), cr2 = cross(l.vec(), l.t - m.s);
    if (sgncrs(l.vec(), m.vec()) == 0) {
        r = l.s;
        if (sgncrs(l.vec(), l.t - m.s)) return 0;
        return -1;
    }
    r = m.s + m.vec() * (cr2 / cr1);
    return 1;
}

using Pol = V<P>;

// pol must be convex
D diameter(const Pol &p) {
    int n = int(p.size());
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] < p[x]) x = i;
        if (p[y] < p[i]) y = i;
    }
    D ans = 0;
    int sx = x, sy = y;
    while (sx != y || sy != x) {
        ans = max(ans, (p[x]-p[y]).abs());
        int nx = (x+1 < n) ? x+1 : 0, ny = (y+1 < n) ? y+1 : 0;
        if (cross(p[nx] - p[x], p[ny] - p[y]) < 0) x = nx;
        else y = ny;
    }
    return ans;
}

int main(void) {
    cout << setprecision(20) << fixed;
    int n;
    cin >> n;
    Pol p(n);
    for (int i = 0; i < n; i++) {
        D x, y;
        cin >> x >> y;
        p[i] = P(x, y);
    }
    cout << diameter(p) << endl;
    return 0;
}

