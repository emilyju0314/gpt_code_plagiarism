#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

static const ll INF = 1000000000000000ll;

#define MAX_V 1000
// Dinic http://www.prefield.com/algorithm/graph/dinic.html
struct dinic{
  struct edge{int to;ll cost;};
  int n;
  vector< vector<edge> > G;
  vector<vl> flow, capacity;
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
  vi level;
  vector<bool> finished;
  dinic(int _n){
    n = _n;
    G.assign(n,vector<edge>());
    flow.assign(n,vl(n,0));
    capacity.assign(n,vl(n,0));
    level.assign(n,0);
    finished.assign(n,false);
  }
  void add_edge(int from,int to,ll cost){
    assert(0<=from && from<n);
    assert(0<=to && to<n);
    G[from].push_back((edge){to,cost});
    G[to].push_back((edge){from,0ll});  // ?????????????????????????????????????????????
  }
  ll dfs(int u, int t, ll cur){
    if(u==t || cur==0) return cur;
    if(finished[u]) return 0;
    finished[u] = true;
    REP(i,G[u].size()){
      edge e = G[u][i];
      if(level[e.to] > level[u]){
        ll f = dfs(e.to, t, min(cur, RESIDUE(u,e.to)));
        if(f>0){
          flow[u][e.to] += f;
          flow[e.to][u] -= f;
          finished[u] = false;
          return f;
        }
      }
    }
    return 0;
  }
  ll calc(int s, int t){
    REP(i,n)REP(j,n)flow[i][j]=capacity[i][j]=0;
    REP(u,n)REP(j,G[u].size()){
      edge e = G[u][j];
      capacity[u][e.to] += e.cost;
    }
    ll total = 0;
    while(true){
      REP(i,n)level[i] = -1;
      level[s] = 0;
      queue<int> Q; Q.push(s);
      int d = n;
      while(!Q.empty()){
        int u = Q.front(); Q.pop();
        REP(i,G[u].size()){
          edge e = G[u][i];
          if(RESIDUE(u,e.to) > 0 && level[e.to] == -1){
            Q.push(e.to);
            level[e.to] = level[u] + 1;
          }
        }
      }
      REP(i,n)finished[i]=false;
      bool flag = false;
      while(true){
        ll f = dfs(s,t,INF);
        if(f==0)break;
        total += f;
        flag = true;
      }
      if(!flag)break;
    }
    return total;
  }
};

int n,m;
vector<pair<int,pii>> es;

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n)REP(j,m){
    int h;
    scanf("%d",&h);
    es.emplace_back(h,pii(2+i,2+n+j));
  }
  int maxcap = (m+n-1)/n;
  int capsa = m%n==0 ? 0 : 1;
  sort(ALL(es));
  int low = 0, high = n*m-1;
  while(low+1 < high){
    int mid = (low+high)/2;
    dinic D(2+n+m+2);
    REP(i,n)D.add_edge(0,2+i,capsa);
    REP(j,m)D.add_edge(2+n+j,1,1);
    D.add_edge(1,0,m);
    REP(i,mid+1){
      D.add_edge(es[i].second.first,es[i].second.second,1);
    }
    int src = 2+n+m;
    int sink = 2+n+m+1;
    REP(i,n)D.add_edge(src,2+i,maxcap-capsa);
    D.add_edge(src,0,m-n*(maxcap-capsa));
    REP(j,m)D.add_edge(2+n+j,sink,1);
    ll flow = D.calc(src,sink);
    if(flow==m)high = mid;
    else low = mid;
  }
  printf("%d\n",capsa);
  printf("%d\n",es[high].first);
  return 0;
}