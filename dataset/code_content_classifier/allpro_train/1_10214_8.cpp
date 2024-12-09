#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <cassert>
#include <queue>
#include <cstring>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define fi first
#define se second

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
  Edge(int src, int dst) :
    src(src), dst(dst), weight(0) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool augment(const Graph& g, int u,
    vector<int>& matchTo, vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }
  REP(u, L) if (matchTo[u] >= 0) // make explicit matching
    matching.push_back( Edge(u, matchTo[u]) );
  return match;
}

int main(){
	int N;
	while(cin >> N && N){
		set<int> w;
		int a,b;
		cin >> a;
		vector<int> day;
		for(int i = 0 ; i < a ; i++){
			cin >> b;
			b--;
			w.insert(b);
			day.push_back(b);
		}
		Edges edge;
		for(int i = 0 ; i < N ; i++){
			int t;
			cin >> t;
			for(int j = 0 ; j < t ; j++){
				int s;
				cin >> s;
				s--;
				if(w.count(s)) edge.push_back(Edge(i,s));
				day.push_back(s);
			}
		}
		sort(day.begin(),day.end());
		day.erase(unique(day.begin(),day.end()),day.end());
		int ub = max(N,(int)day.size());
		Graph g(2*ub);
		for(int i = 0 ; i < edge.size() ; i++){
			int a = edge[i].src;
			int b = ub + lower_bound(day.begin(),day.end(),edge[i].dst) - day.begin();
			g[a].push_back(Edge(a,b));
			g[b].push_back(Edge(b,a));
			//cout << a << " " << b << endl;
		}
		Edges tmp;
		cout << bipartiteMatching(g,ub,tmp) << endl;
		
		
	}
}