#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const int INF = 1e9;

struct EdgeF{
  int to, cap, rev;
  EdgeF(int to_=0, int cap_ = 0, int rev_ = 0)
	:to(to_), cap(cap_), rev(rev_){}
};
using GraphF = vector<vector<EdgeF>>;

void add_edge(GraphF& G, int from, int to, int cap){
  G[from].emplace_back(to, cap, G[to].size());
  G[to].emplace_back(from, cap, G[from].size()-1);
}

int max_flow(GraphF& G, int s, int t, int maximum = INF){
  const int V = G.size();
  vector<bool> used(V);
 
  function<int(int,int,int)> dfs = [&](int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    for(auto& e: G[v]){
      if(!used[e.to] && e.cap > 0){
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  };
 
  int flow = 0;
  while(true){
    fill(used.begin(), used.end(), false);
    int f = dfs(s, t, maximum);
    if(f == 0) return flow;
    flow += f;
	maximum -= f;
	if(maximum == 0)
	  return flow;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;

  GraphF G(V);
  vector<PII> es;
  REP(i,E){
	int s, t, c;
	cin >> s >> t >> c;
	add_edge(G, s, t, c);
	if(c == 1){
	  es.EB(s, SZ(G[s])-1);
	  es.EB(t, SZ(G[t])-1);
	}
  }
  int S = 0, T = V - 1;

  int ans = max_flow(G, S, T);
  for(auto& p: es){
	auto& e = G[p.FF][p.SS];
	if(e.cap == 0){
	  G[e.to][e.rev] = 0;
	  if(max_flow(G, p.FF, e.to, 1) == 0){
		--ans;
		break;
	  }
	  G[e.to][e.rev] = 1;
	}
	else{
	  
	}
  }

  cout << (ans <= 10000? ans: -1) << endl;

  return 0;
}