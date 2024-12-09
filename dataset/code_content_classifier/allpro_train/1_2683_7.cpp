#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:

using edge=struct {int to,cap,cost,rev;};
using G=vector<vector<edge>>;
const int inf=1<<29;

void add_edge(G &graph,int a,int b,int c,int d){
	graph[a].push_back({b,c,d,int(graph[b].size())});
	graph[b].push_back({a,0,-d,int(graph[a].size()-1)});
}

int min_cost_flow(G &graph,int s,int t,int f){
	using W=ll;
	W res=0;
	while(f){
		int n=graph.size(),update;
		vector<W> dist(n,inf),pv(n,0),pe(n,0);
		dist[s]=0;

		rep(loop,n){
			update=false;
			rep(v,n)rep(i,graph[v].size()){
				edge &e=graph[v][i];
				if(e.cap>0 && chmin(dist[e.to],dist[v]+e.cost)){
					pv[e.to]=v,pe[e.to]=i;
					update=true;
				}
			}
			if(!update) break;
		}

		if(dist[t]==inf) return -1;

		int d=f;
		for(int v=t;v!=s;v=pv[v]) chmin(d,graph[pv[v]][pe[v]].cap);
		f-=d,res+=d*dist[t];

		for(int v=t;v!=s;v=pv[v]){
			edge &e=graph[pv[v]][pe[v]];
			e.cap-=d;
			graph[v][e.rev].cap+=d;
		}
	}
	return res;
}

int a[110],b[110][110],l[110];


int main(void){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,n) cin >> a[i];
	rep(i,m)rep(j,n) cin >> b[i][j];
	rep(i,m) cin >> l[i];

	const int my=n+m,hub=my+1,s=hub+1,t=s+1,all=t+1;
	G graph(all);

	rep(i,n) add_edge(graph,s,i,1,0);

	rep(i,n){
		rep(j,m) add_edge(graph,i,j+n,1,-b[j][i]);
		add_edge(graph,i,my,1,-a[i]);
	}

	rep(j,m) add_edge(graph,j+n,hub,l[j],0);

	add_edge(graph,hub,t,n-k,0);
	add_edge(graph,my,t,inf,0);

	cout << -min_cost_flow(graph,s,t,n) << endl;

	return 0;
}