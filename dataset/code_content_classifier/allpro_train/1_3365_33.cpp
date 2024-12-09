#include <cassert>// c
#include <ctime>
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>

using namespace std;
typedef long long ll;

#define ALL(c) (c).begin(),(c).end()
#define FOR(i,l,r) for(int i=(int)l;i<(int)r;++i)
#define REP(i,n) FOR(i,0,n)
#define FORr(i,l,r) for(int i=(int)r-1;i>=(int)l;--i)
#define REPr(i,n) FORr(i,0,n)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

template<typename T,typename U> T pmod(T x,U M){return (x%M+M)%M;}


//output
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){REP(i,as.size()){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){REP(i,as.size()){if(i!=0)os<<endl; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){os<<p.first<<" "<<p.second;return os;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){os << get<0>(t);return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){os << get<0>(t)<<" "<<get<1>(t);return os;}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t)<<" "<<get<6>(t);return os;}


// must template
typedef long double D;
const D INF = 1e12,EPS = 1e-8;

typedef complex<D> P;
#define X real()
#define Y imag()
istream& operator >> (istream& is,complex<D>& p){D x,y;is >> x >> y; p=P(x,y); return is;}

int sig(D a,D b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}
bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
namespace std{
	bool operator <  (const P& a,const P& b){return compX(a,b);}
  	bool operator == (const P& a,const P& b){return eq(a,b);}
};
// a×b
D cross(const P& a,const P& b){return imag(conj(a)*b);}
// a・b
D dot(const P& a,const P& b) {return real(conj(a)*b);}
int ccw(const P& a,P b,P c){
    b -= a; c -= a;
    if (cross(b,c) > EPS)   return +1;       // counter clockwise
    if (cross(b,c) < -EPS)   return -1;       // clockwise
    if (dot(b,c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0; //a--c--b on line (c==b,c==a)
}
// //must template

//直線・線分
struct L : public vector<P> {
	P vec() const {return this->at(1)-this->at(0);}
	L(const P &a, const P &b){push_back(a); push_back(b);}
	L(){push_back(P());push_back(P());}
};
istream& operator >> (istream& is,L& l){P s,t;is >> s >> t;l=L(s,t);return is;}

bool isIntersectLL(const L &l, const L &m) {
 	return sig(cross(l.vec(), m.vec()))!=0 || // non-parallel
	sig(cross(l.vec(), m[0]-l[0])) ==0;   // same line
}
bool isIntersectLS(const L &l, const L &s) {
	return sig(cross(l.vec(), s[0]-l[0])*       // s[0] is left of l
		cross(l.vec(), s[1]-l[0]))<=0; // s[1] is right of l
}
bool isIintersectLP(const L &l, const P &p) {return sig(cross(l[1]-p, l[0]-p))==0;}
// verified by ACAC003 B
// http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899178&cid=ACAC003
bool isIntersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
		ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool isIntersectSP(const L &s, const P &p) {
	return sig(abs(s[0]-p)+abs(s[1]-p),abs(s[1]-s[0])) <=0; // triangle inequality
}

// 直線へ射影した時の点
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092212
P projection(const L &l, const P &p) {
	D t = dot(p-l[0],l.vec()) / norm(l.vec());
	return l[0] + t * l.vec();
}
//対称な点
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092214
P reflection(const L &l, const P &p) {return p + 2.0L * (projection(l, p) - p);}


D distanceLP(const L &l, const P &p) {return abs(p - projection(l, p));}
D distanceLL(const L &l, const L &m) {return isIntersectLL(l, m) ? 0 : distanceLP(l, m[0]);}
D distanceLS(const L &l, const L &s) {
	if (isIntersectLS(l, s)) return 0;
	return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
D distanceSP(const L &s, const P &p) {
	const P r = projection(s, p);
	if (isIntersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}
D distanceSS(const L &s, const L &t) {
	if (isIntersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
		min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

// 交点計算
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092231
P crosspoint(const L &l, const L &m) {
	D A = cross(l.vec(), m.vec());
	D B = cross(l.vec(), l[1] - m[0]);
	if (sig(A)==0 && sig(B)==0) return m[0]; // same line
	if (sig(A)==0) assert(false); //交点を持たない．
	return m[0] + B / A * (m[1] - m[0]);
}


class Main{
	public:

	vector<L> ls;
	vector<vector<L>> chs;
	vector<int> lis;
	D dfs(int d){
		if(d>6)return INF;
		D mv=INF;

		//check
		L lt(l,t);
		// cerr << lt <<endl;
		vector<tuple<D,int,int>> ps;
		REP(_d,d)REP(i,chs[_d].size()){
			if(isIntersectSS(lt,chs[_d][i])){
				ps.push_back(make_tuple(abs(crosspoint(lt, chs[_d][i])-l),_d,i));
			}
		}
		sort(ALL(ps));
		int _d=0;
		vector<int> mr;
		REP(i,ps.size())if(get<1>(ps[i])==_d)if(_d==0 || get<2>(ps[i])!=mr[_d-1]){
			mr.push_back(get<2>(ps[i]));
			_d++;
		}
		if(mr == lis){
			// cerr <<"ok"<<endl; 
			// cerr << lis <<endl;
			// cerr <<"sz" <<ps.size() <<endl;
			// REP(i,ps.size())cerr  << ps[i] <<endl;
			mv=min(mv,abs(l-t)); //反射なしでもいける
		}
		
		//反射
		REP(i,ls.size())if(lis.size()==0 || lis.back()!=i){
			REP(j,ls.size())REP(k,2)chs[d][j][k]=reflection(chs[d-1][i],chs[d-1][j][k]);
			t=reflection(chs[d-1][i],t);
			lis.push_back(i);
			mv=min(mv,dfs(d+1));
			t=reflection(chs[d-1][i],t);
			lis.pop_back();
		}
		return mv;
	}

	P t,l;
	void run(){
		// ifstream cin("D2");
		// ofstream cout( "D2.out" );
		while(true){
			int n;cin >> n;if(n==0)break;
			ls=vector<L>(n);
			chs=vector<vector<L>>(10,vector<L>(n));
			REP(i,n)cin >> ls[i];
			REP(i,n)chs[0][i]=ls[i];
			cin >> t >> l;
			cout << dfs(1)<<endl;
		}
	}
};
int main(){
	cout <<fixed<<setprecision(15);	
	ios::sync_with_stdio(false);
	Main().run();
	return 0;
}