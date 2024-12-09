#include <cassert>// c
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
#include <utility>
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

// must template
typedef long double D;
const D INF = 1e20,EPS = 1e-10;

int sig(D a,D b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}


typedef D Cost;Cost CINF=1e20;
struct Edge{
	int from,to;Cost cost;
	Edge(int from,int to,Cost cost) : from(from),to(to),cost(cost) {};
	bool operator<(Edge r) const{return cost<r.cost;}
	bool operator>(Edge r) const{return cost>r.cost;}
};
typedef vector<vector<Edge> >  Graph;
typedef complex<D> P;
#define X real()
#define Y imag()

bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
istream& operator >> (istream& is,P& p){D x,y;is >> x >> y;p=P(x,y);return is;}

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
	if (sig(cross(b,c)) > 0)   return +1;       // counter clockwise
	if (sig(cross(b,c)) < 0)   return -1;       // clockwise
	if (sig(dot(b,c)) < 0)     return +2;       // c--a--b on line
	if (sig(norm(b),norm(c))<0) return -2;       // a--b--c on line
	return 0; //a--c--b on line or c==a or c==b
}

//直線・線分
struct L : public vector<P> {
	P vec() const {return this->at(1)-this->at(0);}
	L(const P &a, const P &b){push_back(a); push_back(b);}
	L(){push_back(P(0,0));push_back(P(0,0));}
};
istream& operator >> (istream& is,L& l){is >> l[0] >> l[1];return is;}

bool isIntersectLL(const L &l, const L &m) {
 	return sig(cross(l.vec(), m.vec()))!=0 || // non-parallel
	sig(cross(l.vec(), m[0]-l[0])) == 0;   // same line
}
bool isIntersectLS(const L &l, const L &s) {
	return sig(cross(l.vec(), s[0]-l[0])*       // s[0] is left of l
		cross(l.vec(), s[1]-l[0]))<=0; // s[1] is right of l
}
bool isIntersectLP(const L &l, const P &p) {return sig(cross(l[1]-p, l[0]-p))==0;}

// verified by ACAC003 B
// http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899178&cid=ACAC003
bool isIntersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
		ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool isIntersectSP(const L &s, const P &p) {
	return sig(abs(s[0]-p)+abs(s[1]-p),abs(s[1]-s[0])) <=0; // triangle inequality
}
P crosspoint(const L &l, const L &m) {
	D A = cross(l.vec(), m.vec());
	D B = cross(l.vec(), l[1] - m[0]);
	if (sig(A)==0 && sig(B)==0) return m[0]; // same line
	if (sig(A)==0) assert(false); //交点を持たない．
	return m[0] + B / A * m.vec();
}

bool parallel(const L &l, const L &m) { return eq<P>(cross(l.vec(), m.vec()), 0); }
bool sameline(const L &l, const L &m) { return parallel(l, m) && eq<P>(cross(l.vec(), m[1]-l[0]), 0); }

// オーバーラップした線分を1つにマージする．
// O(n^2)
vector<L> merge_segments(vector<L>& ss){
	REP(i,ss.size())if(ss[i][1]<ss[i][0])swap(ss[i][0],ss[i][1]);
	REP(i,ss.size())FOR(j,i+1,ss.size()){
		if(sameline(ss[i],ss[j]) && !ccw(ss[i][0],ss[i][1],ss[j][0])){
			ss[i] = L(min(ss[i][0],ss[j][0]), max(ss[i][1],ss[j][1]));
			ss[j--]=ss.back();ss.pop_back();
		}
	}
	return ss;
}

// 線分アレンジメント
// ps[i]=頂点iに対応するP
// O(n^2logn)
// 制約 : 線分のオーバーラップがない．
Graph segmentArrangement(vector<L> ss, vector<P> &ps) {
	vector<vector<D>> vs(ss.size());
	REP(i,ss.size()){vs[i].push_back(0);vs[i].push_back(abs(ss[i][1]-ss[i][0]));}
	REP(i,ss.size())REP(j,ps.size())if(isIntersectSP(ss[i], ps[j]))
		vs[i].push_back(abs(ps[j]-ss[i][0]));
	
	REP(i,ss.size())FOR(j,i+1,ss.size()){
		L& a=ss[i],b=ss[j];
		if(isIntersectSS(a,b)){
			P p = crosspoint(a,b);
			vs[i].push_back(abs(p-a[0]));vs[j].push_back(abs(p-b[0]));				
		}
	}
	REP(i,vs.size()){sort(ALL(vs[i]));vs[i].erase(unique(ALL(vs[i]),eq<D>),vs[i].end());}
	REP(i,vs.size())REP(j,vs[i].size())ps.push_back(ss[i][0]+vs[i][j]*ss[i].vec()/abs(ss[i].vec()));
	sort(ALL(ps));UNIQUE(ps);

	Graph g(ps.size());
	REP(i,vs.size()){
		vector<D>& cut=vs[i];
		REP(j,cut.size()-1){
			P a = ss[i][0] + vs[i][j]*ss[i].vec()/abs(ss[i].vec()),b = ss[i][0] + vs[i][j+1]*ss[i].vec()/abs(ss[i].vec());
			int f=distance(ps.begin(),lower_bound(ALL(ps),a)), t=distance(ps.begin(),lower_bound(ALL(ps),b));
			g[f].push_back(Edge(f,t,abs(a-b)));g[t].push_back(Edge(t,f,abs(a-b)));
		}
	}
	return g;
}

struct Task{
    int prev,pos;Cost cost;
    Task(int prev,int pos,Cost cost)
        :prev(prev),pos(pos),cost(cost){};
    bool operator>(const Task& r) const{ return cost > r.cost;}
};

//verified by codoforces 144D http://codeforces.com/contest/144/submission/4976825
// // 負の辺がない
// // O(E*logV)
vector<Cost> dijkstra(const Graph& g,const int s,vector<int>& prev){
    const int V=g.size();
    vector<Cost> d(V,CINF);d[s]=0;
    fill(ALL(prev), -2);
    
    priority_queue<Task,vector<Task>,greater<Task> > que;que.push(Task(-1,s,0));// [ ,e,,f, ] <=> e.cost < e.cost
    vector<bool> visited(V);
    while(!que.empty()){
        Task task=que.top();que.pop();
        if(visited[task.pos])continue;
        visited[task.pos]=true;
        prev[task.pos]=task.prev;
        EACH(e,g[task.pos])if(d[e->to]>d[e->from]+e->cost){
            d[e->to]=d[e->from]+e->cost;
            que.push(Task(e->from,e->to,d[e->to]));
        }
    }
    return d;
}
vector<Cost> dijkstra(const Graph& g,const int s){
    vector<int> prev(g.size());return dijkstra(g,s,prev);
}

int main(){
	// ifstream cin( "in" );
	// ofstream cout( "out" );
	cout << fixed <<setprecision(20);
	cerr << fixed <<setprecision(20);
	cin.tie(0); ios::sync_with_stdio(false);

	while(true){
		int N;cin >> N;if(N==0)break;
		vector<L> ls(N);REP(i,N) cin >> ls[i];
		P p;cin >> p;
		vector<P> ps;ps.push_back(p);
		Graph g=segmentArrangement(ls,ps);
		
		int si=-1;REP(i,ps.size())if(p==ps[i])si=i;
		vector<Cost> ds = dijkstra(g,si);

		D Mv=*max_element(ALL(ds));
		REP(i,g.size())EACH(e,g[i]){
			D a=abs(ds[e->from]-ds[e->to]);
			D d=abs(ps[e->from]-ps[e->to]);
			Mv=max(Mv,min(ds[e->from],ds[e->to])+(a+d)/2);
		}
		cout << Mv <<endl;
	}
	return 0;
}