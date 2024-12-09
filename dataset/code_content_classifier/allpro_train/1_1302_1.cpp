#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fr(i,c) for(__typeof(c.begin()) i=c.begin();i!=c.end();i++)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(),c.end()
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
const int inf=(int)1e9;
const double EPS=1e-4, INF=1e12;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow,
    const vector<int> &level, vector<bool> &finished, int u, int t, Weight cur) {
  if (u == t || cur == 0) return cur;
  if (finished[u]) return 0;
  finished[u] = true;
  fr(e, g[u]) if (level[e->dst] > level[u]) {
    Weight f = augment(g, capacity, flow, level, finished,
        e->dst, t, min(cur, RESIDUE(u, e->dst)));
    if (f > 0) {
      flow[u][e->dst] += f; flow[e->dst][u] -= f;
      finished[u] = false;
      return f;
    }
  }
  return 0;
}
Weight maximumFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
  rep(u,n) fr(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  for (bool cont = true; cont; ) {
    cont = false;
    vector<int> level(n, -1); level[s] = 0; // make layered network
    queue<int> Q; Q.push(s);
    for (int d = n; !Q.empty() && level[Q.front()] < d; ) {
      int u = Q.front(); Q.pop();
      if (u == t) d = level[u];
      fr(e, g[u]) if (RESIDUE(u,e->dst) > 0 && level[e->dst] == -1)
        Q.push(e->dst), level[e->dst] = level[u] + 1;
    }
    vector<bool> finished(n); // make blocking flows
    for (Weight f = 1; f > 0; ) {
      f = augment(g, capacity, flow, level, finished, s, t, inf);
      if (f == 0) break;
      total += f; cont = true;
    }
  }
  return total;
}
void add_edge(Graph &g, int s,int t,int w){
	g[s].pb(Edge(s,t,w));
	g[t].pb(Edge(t,s,0));
}


typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
typedef vector<P> G;
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS)   return +1;       // counter clockwise
  if (cross(b, c) < -EPS)   return -1;       // clockwise
  if (dot(b, c) < EPS)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool hoge(const L &s,const P&p){
	return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
bool intersectSP(const L &s, const P &p) {
	bool res=0;
	rep(i,2)if(abs(s[i]-p)<EPS)res=1;
	if(!res&&ccw(p,s[1],s[0])==2)res=1;
	/*
	if(res!=hoge(s,p)){
		cerr<<s[0]<<" "<<s[1]<<" "<<p<<endl;
		dbg(ccw(p,s[1],s[0]));
		dbg(arg(s[1]-s[0]));
		dbg(arg(p-s[0]));
		cerr<<res<<" "<<hoge(s,p)<<endl;
		assert(0);
		
	}
	*/
	return res;
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}


bool sameline(const L &l,const L &m){
	return abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;
}

map<P,int> id;
void push(vector<P> &ps,const P &p){
	if(id.count(p))return;
	rep(i,ps.size())if(abs(ps[i]-p)<EPS){
		id[p]=i;
		return;
	}
	id[p]=ps.size();
	ps.pb(p);
}
struct cmp{
	P o;
	cmp(P p):o(p){}
	bool operator()(const P&a,const P&b)const{
		return abs(a-o)<abs(b-o);
	}
};


int n,m,w[500];

int main(){
	vector<L> ls;
	vector<P> ps;
	cin>>n;
	rep(i,n){
		double ax,ay,bx,by;
		cin>>ax>>ay>>bx>>by>>w[i];
		ls.pb(L(P(ax,ay),P(bx,by)));
		push(ps,P(ax,ay)); push(ps,P(bx,by));
	}
	cin>>m;
	vector<P> ss;
	double x,y;
	rep(i,m){
		cin>>x>>y;
		ss.pb(P(x,y));
		push(ps,P(x,y));
	}
	cin>>x>>y;
	P g(x,y);
	push(ps,g);
	
	rep(i,n)rep(j,i)if(intersectSS(ls[i],ls[j])){
		P cp=crosspoint(ls[i],ls[j]);
		push(ps,cp);
	}
	
	int V=ps.size();
	
	Graph graph(V+1);
	int s=V, t=id[g];
	rep(i,m){
		add_edge(graph,s,id[ss[i]],inf);
	}
	
	vector<vector<double> > width(V,vector<double>(V));
	rep(i,n){
		vector<P> online;
		rep(j,V)if(intersectSP(ls[i],ps[j]))online.pb(ps[j]);
		sort(all(online),cmp(ls[i][0]));
		const double dist=abs(ls[i][0]-ls[i][1]);
		rep(j,online.size()-1){
			double tw=w[i]*abs(online[j]-online[j+1])/dist;
			width[id[online[j]]][id[online[j+1]]]+=tw;
			width[id[online[j+1]]][id[online[j]]]+=tw;
		}
	}
	rep(i,V)rep(j,V)if(width[i][j]>EPS)add_edge(graph,i,j,(int)(width[i][j]+EPS));
	
	int ans=maximumFlow(graph,s,t);
	cout<<ans<<endl;
	
	return 0;
	
}