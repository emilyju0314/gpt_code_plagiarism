#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

#include <complex>
#include <cmath>
#define EPS 1.0e-10
#define PI 3.1415926535897932384 

// 実数の符号関数
inline int signum(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
//XY座標
#define X real()
#define Y imag()
// 点
typedef complex<double> P;
 

// 線分・半直線・直線
struct L { P pos, dir; L(P p=P(), P d=P()):pos(p),dir(d){}};

// 多角形
typedef vector<P> G;
 
// 円
struct C { P p; double r; C(P q=P(), double R=0):p(q),r(R){}};

// std::norm はabs(p)*abs(p)なので遅い
inline double norm(P p){
	return p.X*p.X+p.Y*p.Y;
}

// 二つのベクトルの内積を計算する
inline double inp(const P& a, const P& b) {
	return (conj(a)*b).X;
}
 
// 二つのベクトルの外積を計算する
inline double outp(const P& a, const P& b) {
	return (conj(a)*b).Y;
}

inline int ccw(const P& p, const P& r, const P& s) {
    P a(r-p), b(s-p);
    int sgn = signum(outp(a, b));
    if (sgn != 0)
        return sgn;
    if (a.X*b.X < -EPS || a.Y*b.Y < -EPS)
        return -1;
    if (norm(a) < norm(b) - EPS)
        return 1;
    return 0;
}

// ベクトルpをベクトルbに射影したベクトルを計算する
inline P proj(const P& p, const P& b) {
	return b*inp(p,b)/norm(b);
}

// 点pから直線lに引いた垂線の足となる点を計算する
inline P perf(const L& l, const P& p) {
	L m = L(l.pos - p, l.dir);
	return (p + (m.pos - proj(m.pos, m.dir)));
}
 
// 線分sを直線bに射影した線分を計算する
inline L proj(const L& s, const L& b) {
	 return (L){perf(b, s.pos), proj(s.dir, b.dir)};
}

inline double lp_distance(const L& l, const P& p) {
	return abs(outp(l.dir, p-l.pos) / abs(l.dir));
}

L rotate(L l, double rad){
	double base = atan2(l.dir.Y, l.dir.X);
	double d = abs(l.dir);
	l.dir = d * P(cos(base+rad), sin(base+rad));
	return l;
}

vector<L> CCCommonTangent(C c1, C c2){
	if(c1.r > c2.r) swap(c1, c2);
	double d = abs(c1.p-c2.p);
	vector<L> res;
	if(norm(c1.p - c2.p) < EPS) return res;
	if(d + EPS > c1.r + c2.r){
		// 内接線
		P crs = (c1.p*c2.r + c2.p*c1.r) / (c1.r + c2.r);
		double rad = asin(c1.r/abs(crs-c1.p));
		res.push_back(rotate(L(crs, c1.p-crs), rad));
		res.push_back(rotate(L(crs, c1.p-crs), -rad));
	}
	if(c1.r + d + EPS > c2.r){
		// 外接線
		double rad = 0.5*PI+asin((c2.r-c1.r) / d);
		L l1 = rotate(L(c1.p, (c2.p-c1.p)/abs(c2.p-c1.p)), rad);
		L l2 = rotate(L(c2.p, (c2.p-c1.p)/abs(c2.p-c1.p)), rad);
		l1.dir *= c1.r;
		l2.dir *= c2.r;
		if(c1.r + d - EPS < c2.r){
			res.push_back(L(l1.pos + l1.dir, P((c1.p - c2.p).Y, (c1.p - c2.p).X)));
		}else{
			res.push_back(L(l1.pos+l1.dir, l2.pos+l2.dir - (l1.pos+l1.dir)));
			l1 = rotate(l1, -rad*2);
			l2 = rotate(l2, -rad*2);
			res.push_back(L(l1.pos+l1.dir, l2.pos+l2.dir - (l1.pos+l1.dir)));
		}
	}
	
	return res;
}

int n;
vector<pair<C, C> > jewel;


int solve(L l){
	int res = 0;
	REP(i, jewel.size()){
		double d = lp_distance(l, jewel[i].first.p);
		if(jewel[i].first.r < d+EPS && d-EPS < jewel[i].second.r) res ++;
	}
	return res;
}

int main(){
	while(cin >> n, n){
		jewel.clear();
		REP(i, n){
			int x, y, r, m;
			cin >> x >> y >> r >> m;
			jewel.emplace_back(C(P(x, y), r), C(P(x, y), r+m));
		}
		int ans = 1;
		REP(i, n)REP(j, i){
			REP(k, 4){
				C &c1 = (k&1) ? jewel[i].first : jewel[i].second;
				C &c2 = (k&2) ? jewel[j].first : jewel[j].second;
				vector<L> cand = CCCommonTangent(c1, c2);
				REP(l, cand.size()) {
					ans = max(ans, solve(cand[l]));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}