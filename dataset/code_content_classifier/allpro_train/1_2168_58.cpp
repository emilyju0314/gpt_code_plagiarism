#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

template<class T> using V = vector<T>;

using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) { return (abs(a) <= EPS) ? 0 : (a < 0 ? -1 : 1); }
int sgn(D a, D b) { return sgn(a-b); }
//relative sign
// int rsgn(D a, D f) {
//     if (abs(a) <= f*EPS) return 0;
//     return (a < 0) ? -1 : 1;
// }
struct Pt2 {
    D x, y;
    Pt2(D _x = D(), D _y = D()) : x(_x), y(_y) {}
    Pt2 operator+(const Pt2 &r) const { return Pt2(x+r.x, y+r.y); }
    Pt2 operator-(const Pt2 &r) const { return Pt2(x-r.x, y-r.y); }
    Pt2 operator*(const Pt2 &r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x); }

    Pt2 operator*(const D &r) const { return Pt2(x*r, y*r); }
    Pt2 operator/(const D &r) const { return Pt2(x/r, y/r); }

    Pt2& operator+=(const Pt2 &r) { return *this=*this+r; }
    Pt2& operator-=(const Pt2 &r) { return *this=*this-r; }
    Pt2& operator*=(const Pt2 &r) { return *this=*this*r; }
    Pt2& operator*=(const D &r) { return *this=*this*r; }
    Pt2& operator/=(const D &r) { return *this=*this/r; }
    
    Pt2 operator-() const { return Pt2(-x, -y); }

    bool operator<(const Pt2 &r) const { return 2*sgn(x, r.x)+sgn(y, r.y)<0; }
    bool operator==(const Pt2 &r) const { return sgn((*this-r).rabs()) == 0; }

    D norm() const { return x*x + y*y; }
    D abs() const { return sqrt(norm()); }
    D rabs() const { return max(std::abs(x), std::abs(y)); } // robust abs
    D arg() const { return atan2(y, x); }

    pair<D, D> to_pair() const { return make_pair(x, y); }
    static Pt2 polar(D le, D th) { return Pt2(le*cos(th), le*sin(th)); }
};
ostream& operator<<(ostream& os, const Pt2 &p) {
    return os << "P(" << p.x << ", " << p.y << ")";
}
using P = Pt2;

struct L {
    P s, t;
    L(P _s = P(), P _t = P()) : s(_s), t(_t) {}
    P vec() const { return t-s; }
    D abs() const { return vec().abs(); }
    D arg() const { return vec().arg(); }
};
ostream& operator<<(ostream& os, const L &l) {
    return os << "L(" << l.s << ", " << l.t << ")";
}

D cross(P a, P b) { return a.x*b.y - a.y*b.x; }
D dot(P a, P b) { return a.x*b.x + a.y*b.y; }
// cross(a, b) is too small?
int sgncrs(P a, P b) {
    D cr = cross(a, b);
    if (abs(cr) <= (a.rabs() + b.rabs()) * EPS) return 0;
    return (cr < 0) ? -1 : 1;
}

// -2, -1, 0, 1, 2 : front, clock, on, cclock, back
int ccw(P b, P c) {
    int s = sgncrs(b, c);
    if (s) return s;
    if (!sgn(c.rabs()) || !sgn((c-b).rabs())) return 0;
    if (dot(b, c) < 0) return 2;
    if (dot(-b, c-b) < 0) return -2;
    return 0;
}
int ccw(P a, P b, P c) { return ccw(b-a, c-a); }
int ccw(L l, P p) { return ccw(l.s, l.t, p); }

P project(const L &l, const P &p) {
    P v = l.vec();
    return l.s + v * (dot(v, p-l.s) / v.norm());
}

bool insSL(const L &s, const L &l) {
    int a = ccw(l, s.s), b = ccw(l, s.t);
    return (a%2 == 0 || b%2 == 0 || a != b);
}

bool insSS(const L &s, const L &t) {
    int a = ccw(s, t.s), b = ccw(s, t.t);
    int c = ccw(t, s.s), d = ccw(t, s.t);
    if (a*b <= 0 && c*d <= 0) return true;
    return false;
}

D distLP(const L &l, const P &p) {
    return abs(cross(l.vec(), p-l.s)) / l.abs();
}

D distSP(const L &s, const P &p) {
    P q = project(s, p);
    if (ccw(s, q) == 0) return (p - q).abs();
    else return min((s.s - p).abs(), (s.t - p).abs());
}

using Pol = V<P>;

struct C {
    P p; D r;
    C(P _p = P(), D _r = D()) : p(_p), r(_r) {}
};

// Tri((0, 0), a, b)とC(P(0, 0), r)の共有面積
D insAreaTC(const P &a, const P &b, const D &r) {
    if (a == b) return 0;
    D r2 = distSP(L(a, b), P(0, 0));
    if (sgn(max(a.abs(), b.abs()), r) != 1) return cross(a, b) / 2;
    if (sgn(r, r2) != 1) {
        D ar = b.arg() - a.arg();
        ar = fmod(fmod(ar, 2*PI) + 2*PI, 2*PI);
        if (!sgn(ar - 2*PI)) ar = 0;
        if (ar >= PI) ar -= 2*PI;
        return r * r * ar / 2;
    }
    return insAreaTC(a, (a+b)/2, r) + insAreaTC((a+b)/2, b, r);
}

// p, cの共有面積
D insAreaPolC(const Pol &po, const C &c) {
    D sm = 0;
    P a, b = po.back();
    for (auto p: po) {
        a = b; b = p;
        sm += insAreaTC(a, b, c.r);
    }
    return sm;
}

//need Intersect/distLP
int crossCL(const C &c, const L &l, L &r) {
    D u = distLP(l, c.p);
    int si = sgn(u, c.r);    
    if (si == 1) return 0;
    P v = project(l, c.p);
    P di = (si == 0) ? P(0, 0) : l.vec() * (sqrt(c.r*c.r - u*u) / l.abs());
    r = L(v+di, v-di);
    if (si == 0) return 1;
    return 2;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    
    int n; D r;
    cin >> n >> r;
    C c = C(P(0, 0), r);
    Pol po(n);
    for (int i = 0; i < n; i++) {
        D x, y;
        cin >> x >> y;
        po[i] = P(x, y);
    }
    cout << insAreaPolC(po, c) << endl;
    return 0;
}

