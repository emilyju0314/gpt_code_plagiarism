#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <complex>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
using ll = long long;
constexpr long long INF = 1LL << 62;
constexpr int MOD = 1e9 + 7;

using Point = complex<double>;
struct Line {
    Point s, t;
    Line(Point s, Point t) : s(s), t(t){}
};
double dot(Point p, Point q) { return (conj(p) * q).real(); }
double cross(Point p, Point q) { return (conj(p) * q).imag(); }
Point project(Line l, Point p) { // project p onto line (s,t)
    return l.s + (l.t - l.s) * dot(p - l.s, l.t - l.s) / norm(l.t - l.s);
}
Point reflect(Line l, Point p) {
    return l.s + conj((p - l.s) / (l.t - l.s)) * (l.t - l.s);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    Point p1(a, b), p2(c, d);
    Line l(p1, p2);
    cout << fixed << setprecision(10);

    int q;
    cin >> q;
    for(int i=0; i < q; ++i) {
        double x,y;
        cin >> x >> y;
        Point ret = reflect(l, Point(x, y));
        cout << ret.real() << " " << ret.imag() << '\n';
    }
    return 0;
}
