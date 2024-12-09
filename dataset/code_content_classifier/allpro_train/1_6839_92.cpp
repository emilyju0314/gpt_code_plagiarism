#include <bits/stdc++.h>
using namespace std;
 
using ll = long long; using ld = long double; using ull = unsigned long long; using uint = unsigned int;
using vi  = vector<int>; using vb  = vector<bool>; using vd  = vector<double>; using vl  = vector<ll>;
using vvi = vector<vi>;  using vvb = vector<vb>;   using vvd = vector<vd>;     using vvl = vector<vl>;
 
#define REP(i,n) for(ll i=0; i<(n); ++i)
#define FOR(i,b,n) for(ll i=(b); i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define TEN(x) ((ll)1e##x)
 
template<typename T> inline string join(const vector<T>& vec, string sep = " ") { stringstream ss; REP(i, vec.size()) ss << vec[i] << ( i+1 == vec.size() ? "" : sep ); return ss.str(); }
 
 
///////////////
 
#define EPS (1e-10)
#define NEXT(x, i) (x[(i + 1) % x.size()])
 
template<class T> using CR = const T &;
using P = complex<ld>;
using G = vector<P>;
 
int sgn(ld a, ld b = 0) {
    if (a > b + EPS) return 1;
    if (a < b - EPS) return -1;
    return 0;
}
 
ld dot(P a, P b) { return real(conj(a)*b); }
ld cross(P a, P b) { return imag(conj(a)*b); }
 
int ccw(P a, P b, P c) {
    b -= a;
    c -= a;
    if (sgn(cross(b, c))) return sgn(cross(b, c)); // clockwise or counter clockwise
    if (sgn(dot(b, c)) == -1) return 2;            // c--a--b
    if (sgn(norm(b), norm(c)) == -1) return -2;    // a--b--c
    return 0;                                      // a--c--b
}
 
struct L : public vector<P> {
    L(P a, P b) { push_back(a); push_back(b); }
};

bool iLL(CR<L> l, CR<L> m, bool strict = false) {
	if (sgn(cross(l[1] - l[0], m[1] - m[0]))) return true;   // not-parallel
	return !strict && !sgn(cross(l[1] - l[0], m[0] - l[0])); // same line
}
bool iLS(CR<L> l, CR<L> s, bool strict = false) {
	int c = sgn(cross(l[1] - l[0], s[0] - l[0])) * sgn(cross(l[1] - l[0], s[1] - l[0]));
	return c <= 0 && (!strict || c == -1);
}
bool iSS(CR<L> s, CR<L> t, bool strict = false) {
	int ccwa = ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]);
	int ccwb = ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]);
	return ccwa <= 0 && (!strict || ccwa == -1)
		&& ccwb <= 0 && (!strict || ccwb == -1);
}
ld dLP(CR<L> l, P p) { return abs(cross((l[1] - l[0]), p - l[0]) / (l[1] - l[0])); }
ld dSP(L s, P p) {
	if (dot(s[1] - s[0], p - s[0]) < 0) return abs(p - s[0]);
	if (dot(s[1] - s[0], p - s[1]) > 0) return abs(p - s[1]);
	return dLP(s, p);
}
ld dLL(CR<L> a, CR<L> b) { return iLL(a, b) ? 0 : dLP(a, b[0]); }
ld dLS(CR<L> a, CR<L> b) { return iLS(a, b) ? 0 : min(dLP(a, b[0]), dLP(a, b[1])); }
ld dSS(CR<L> a, CR<L> b) { return iSS(a, b) ? 0 : min(min(dSP(a, b[0]), dSP(a, b[1])), min(dSP(b, a[0]), dSP(b, a[1]))); }

//////////////
 
int main() {
#ifdef INPUT_FROM_FILE
    ifstream cin("sample.in");
    ofstream cout("sample.out");
#endif
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
	ll n; cin >> n;
	REP(i, n) {
		ld x0, y0, x1, y1, x2, y2, x3, y3;
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		cout << dSS({ { x0, y0 }, { x1, y1 } }, { { x2, y2 }, { x3, y3 } }) << endl;
	}
    return 0;
}