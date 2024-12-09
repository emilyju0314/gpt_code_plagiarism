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
#include <numeric>
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

const double EPS = 1e-8;
const int MOD = 1000000007;


typedef int Weight;
const Weight INF=999999999;
struct Edge{
	int src,dst;
	Weight weight;
	int rev, f;
	Edge(int f, int t, Weight c,int rev=0, int ff=0):src(f),dst(t),weight(c),rev(rev),f(ff){}
};
typedef vector< vector<Edge> > Graph;

void add_edge(Graph &G,int s,int t,Weight cap, int f=0){
//	printf("%d->%d(%d)\n", s, t, cap);
	G[s].push_back(Edge(s,t,cap,G[t].size(), f));
	G[t].push_back(Edge(t,s,cap,G[s].size()-1, f));
}


void bfs(const Graph &G,vector<int> &level,int s){
	level[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		REP(i,G[v].size()){
			const Edge &e=G[v][i];
			if(e.weight>0 && level[e.dst] < 0){
				level[e.dst] = level[v] +1;
				que.push(e.dst);
			}
		}
	}
}
Weight dfs(Graph &G,vector<int> &level,vector<int> &iter,int v,int t,Weight flow){
	if(v==t)return flow;
	for(int &i=iter[v];i<(int)G[v].size();i++){
		Edge &e=G[v][i];
		if(e.weight>0&&level[v]<level[e.dst]){
			Weight d=dfs(G,level,iter,e.dst,t,min(flow,e.weight));
			if(d>0){
				e.weight-=d;
				G[e.dst][e.rev].weight+=d;
				return d;
			}
		}
	}
return 0;
}

// Dinic
// O(EV^2)
Weight max_flow(Graph &G,int s,int t){
	Weight flow = 0;
	while(true){
		vector<int> level(G.size(),-1);
		vector<int> iter(G.size(),0);
		bfs(G,level,s);
		if(level[t]<0)break; // もう流せない
		Weight f=0;
		while((f=dfs(G,level,iter,s,t,INF))>0){
			flow+=f;
		}
	}
	return flow;
}


int n, w;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> w;
	vi a(n), b(n);
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];

	int sum = accumulate(ALL(a), 0) + accumulate(ALL(b), 0);
	pair<int, string> res(-1, "");
	REP(k, 2){
		Graph g(n+2*w+3);
		const int s = n+2*w+1;
		const int t = n+2*w+2;
		REP(i, n){
			add_edge(g, w+i, w+i+1, a[i], 1);
			add_edge(g, i, 2*w+i+1, b[i]);
		}
		REP(i, w+1){
			if(i&1) add_edge(g, s, i, INF);
			else    add_edge(g, i, t, INF);
			if(((w+n+i)&1)^k) add_edge(g, s, w+n+i, INF);
			else        add_edge(g, w+n+i, t, INF);
		}
		int score = sum - max_flow(g, s, t);
		string ans(n, '1');
		queue<int> q;
		vi att(g.size(), 0);
		att[s] = 1;
		q.push(s);
		while(!q.empty()){
			int u = q.front();q.pop();
			FOR(e, g[u])if(e->weight != 0){
				if(!att[e->dst]){
					att[e->dst] = 1;
					q.push(e->dst);
				}
			}
		}
//		cout << att << endl;
		REP(i, n+1) ans[i] = '0' + (att[i+w] == att[i+w+1]);
//		cout << ans << ": " << score << endl;
		res = max(res, make_pair(score, ans));
	}
	cout << res.second << endl;
	return 0;
}