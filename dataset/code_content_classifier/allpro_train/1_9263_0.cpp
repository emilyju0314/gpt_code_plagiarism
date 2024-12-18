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
#include <unordered_map>
#include <iterator>
#include <functional>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
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
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

namespace geom{
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
	enum {TRUE = 1, FALSE = 0, BORDER = -1};
	typedef int BOOL;
	typedef long double R;
	const R INF = 1e8;
	R EPS = 1e-6;
	const R PI = 3.1415926535897932384626;
	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}
	typedef complex<R> P;
	inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}
	inline R inp(const P& a, const P& b){return (conj(a)*b).X;}
	inline R outp(const P& a, const P& b){return (conj(a)*b).Y;}
	inline P unit(const P& p){return p/abs(p);}
	inline P proj(const P &s, const P &t){return t*inp(s, t)/norm(t);}
	inline int ccw(const P &s, const P &t, const P &p, int adv=0){
		int res = sig(outp(t-s, p-s));
		if(res || !adv) return res;
		if(sig(inp(t-s, p-s)) < 0) return -2;	// p-s-t
		if(sig(inp(s-t, p-t)) < 0) return 2;	// s-t-p
		return 0;								// s-p-t
	}
	
	
	struct L : public vector<P>{	// line
		L(const P &p1, const P &p2){this->push_back(p1);this->push_back(p2);}
		L(){}
		P dir()const {return at(1) - at(0);}
	};
	struct S : public L{	// segment
		S(const P &p1, const P &p2):L(p1, p2){}
		S(){}
	};
	inline P proj(const P &s, const L &t){return t[0] + proj(s-t[0], t[1]-t[0]);}
	inline P reflect(const P &s, const L &t){return (R)2.*proj(s, t) - s;}
	inline S reflect(const S &s, const L &t){return S(reflect(s[0], t), reflect(s[1], t));}
	inline P crosspoint(const L &l, const L &m){
		R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);
		if(!sig(abs(A)) && !sig(abs(B))) return m[0]; // same line
		if(abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
		return m[0] + B / A * (m[1] - m[0]);
	}
	
	struct G : public vector<P>{
		G(size_type size=0):vector(size){}
		S edge(int i)const {return S(at(i), at(i+1 == size() ? 0 : i+1));}
		R area()const {
			R sum = 0;
			REP(i, size()) sum += outp(at(i), at((i+1)%size()));
			return abs(sum / 2.);
		}
		G cut(const L &l)const {
			G g;
			REP(i, size()){
				const S &s = edge(i);
				if(ccw(l[0], l[1], s[0], 0) >= 0) g.push_back(s[0]);
				if(ccw(l[0], l[1], s[0], 0) * ccw(l[0], l[1], s[1], 0) < 0)
					g.push_back(crosspoint(s, l));
			}
			return g;
		}
	};

#undef SELF
#undef at
}

using namespace geom;

int f = 0;
namespace std{
	bool operator<(const P &a, const P &b){return sig(a.X-b.X) ? a.X < b.X : a.Y+EPS < b.Y;}
	bool operator==(const P &a, const P &b){return abs(a-b) < EPS;}
	istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}
	istream& operator>>(istream &is, L &l){l.resize(2);return is >> l[0] >> l[1];}
	const R B = 500;
	const R Z = 50;
	ostream& operator<<(ostream &os, const P &p){return os << "circle("<<B+Z*(p.X)<<", "<<1000-B-Z*(p.Y)<<", 2)";}
	ostream& operator<<(ostream &os, const S &s){return os << "line("<<B+Z*(s[0].X)<<", "<<1000-B-Z*(s[0].Y)<<", "<<B+Z*(s[1].X)<<", "<<1000-B-Z*(s[1].Y)<<")";}
	ostream& operator<<(ostream &os, const G &g){REP(i, g.size()) os << g.edge(i) << endl;return os;}

}

int T, n, m;
R len, rot;
P bias;
G g;
vector<pair<R, int>> areas;

R search(R area){
	R l=0, r=len;
	REP(itr, 50){
		R mid=(r+l)/2;
		if(g.cut(L(P(mid, 0), P(mid, 1))).area() < area) l = mid;
		else r = mid;
	}
	return r;
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	g.resize(n);
	REP(i, n) cin >> g[i];
//cerr << g << endl;
	tuple<R, int, int> ma(-1, 0, 0);
	REP(i, n)REP(j, n) chmax(ma, tuple<R, int, int>(abs(g[i]-g[j]), i, j));
	len = get<0>(ma);
	rot = arg(g[get<2>(ma)] - g[get<1>(ma)]);
	for(auto &p : g) p *= polar((R)1, -rot);
	bias = g[get<1>(ma)];
	for(auto &p : g) p -= bias;
	R sumarea = g.area();
	R sum = 0;
	REP(i, m){
		R r;
		cin >> r;
		areas.eb(r*sumarea, i);
		sum += r;
	}
	REP(i, m) areas[i].first /= sum;
	sort(RALL(areas));
	vector<pair<R, int>> tar;
	R prevw = INF, prevb = 0;
	int i=0;
	sumarea = 0;
	int center = -1;
	while(center == -1){
		REP(i, areas.size()){
			R b = search(sumarea + areas[i].first);
			if(i+1 == areas.size()){
				tar.eb(b, areas[i].second);
				if(prevw > b - prevb) center = tar.size()-1;
				else center = tar.size()-2;
				sumarea += areas[i].first;
				areas.erase(areas.begin() + i);
				break;
			}else if(prevw > b - prevb){
				tar.eb(b, areas[i].second);
				prevw = b - prevb;
				prevb = b;
				sumarea += areas[i].first;
				areas.erase(areas.begin() + i);
				break;
			}
		}
	}
	while(!areas.empty()){
		R b = search(sumarea + areas.back().first);
		tar.eb(b, areas.back().second);
		sumarea += areas.back().first;
		areas.pop_back();
	}
//	cout << center << ", " << tar << endl;
//cerr << g << endl;
//REP(i, m) cerr << S(P(tar[i].first, -100), P(tar[i].first, 100)) << endl;
//	REPS(i, tar.size()-1) cout << tar[i].first - tar[i-1].first << endl;
	
	vector<P> ans(m);
	ans[tar[center].second] = P((tar[center].first + tar[center-1].first)/2, (R)0);
	for(int i=center-1;i>=0;i--){
		ans[tar[i].second] = reflect(ans[tar[i+1].second], L(P(tar[i].first, 0), P(tar[i].first, 1)));
	}
	for(int i=center+1;i<m;i++){
		ans[tar[i].second] = reflect(ans[tar[i-1].second], L(P(tar[i-1].first, 0), P(tar[i-1].first, 1)));
	}
	REP(i, m){
		P p = (ans[i] + bias) * polar((R)1, rot);
//		cerr << p << endl;
		printf("%.11f %.11f\n", (double)p.X, (double)p.Y);
	}
	return 0;
}