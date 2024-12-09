#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;

template<class T> using V = vector<T>;

using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) { return (abs(a) <= EPS) ? 0 : (a < 0 ? -1 : 1); }
int sgn(D a, D b) { return sgn(a-b); }

struct Pt2 {
    D x, y;
    Pt2(D _x = D(), D _y = D()) : x(_x), y(_y) {}

    Pt2 operator+(const Pt2 &r) const { return Pt2(x+r.x, y+r.y); }
    Pt2 operator-(const Pt2 &r) const { return Pt2(x-r.x, y-r.y); }
    Pt2 operator*(const Pt2 &r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x); }

    bool operator==(const Pt2 &r) const { return sgn((*this-r).rabs()) == 0; }
    bool operator!=(const Pt2 &r) const { return !(*this == r); }
    D rabs() const { return max(std::abs(x), std::abs(y)); }
};
using P = Pt2;

struct L {
    P s, t;
    L(P _s = P(), P _t = P()) : s(_s), t(_t) {}
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

int dfs(V<P> s, V<P> t, int rem);
int dfs2(const V<P> &s, const V<P> &t, int rem) {
    int erc = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] != t[i]) erc++;
    }
    if (rem - erc < 0) return -1;
    if (s[0] == t[0]) return -1;
    int ans = -1;
    {
        L l1 = L(t[0], s[0]);
        L l2 = L(s[2], s[1]);
        if (!sgncrs(l1.vec(), l2.vec())) {
            auto s2 = s;
            s2[0] = t[0];
            ans = max(ans, dfs(s2, t, rem-1));
        }
    }

    for (int ph = 0; ph < 2; ph++) {
        int x = 1, y = 2;
        if (ph) swap(x, y);
        //move x
        L l1 = L(s[y], s[y] + (t[0] - s[0]));
        L l2 = L(s[x], s[x] + (s[0] - s[y]));
        if (sgncrs(l1.vec(), l2.vec())) {
            P p;
            assert(crossLL(l1, l2, p));
            auto s2 = s;
            s2[x] = p;
            ans = max(ans, dfs(s2, t, rem-1));
        }
    }
    return ans;
}

int dfs(V<P> s, V<P> t, int rem) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        if (s[i] != t[i]) {
            ok = false;
            break;
        }
    }
    if (ok) return rem;
    int ans = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dfs2(s, t, rem));
            rotate(begin(t), begin(t)+1, end(t));
        }
        rotate(begin(s), begin(s)+1, end(s));
    }
    return ans;
}

bool solve() {
    V<P> s(3), t(3);
    for (int i = 0; i < 3; i++) {
        D x, y;
        if (!(cin >> x >> y)) return false;
        s[i] = P(x, y);
    }
    for (int i = 0; i < 3; i++) {
        D x, y;
        if (!(cin >> x >> y)) return false;
        t[i] = P(x, y);
    }
    if (cross(s[1] - s[0], s[2] - s[0]) < 0) swap(s[1], s[2]);
    if (cross(t[1] - t[0], t[2] - t[0]) < 0) swap(t[1], t[2]);

    int res = 4 - dfs(s, t, 4);
    if (res > 4) cout << "Many" << endl;
    else cout << res << endl;

    return true;
}


int main() {
    while (solve()) {}
    return 0;
}
