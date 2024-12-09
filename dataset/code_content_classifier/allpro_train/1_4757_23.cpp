#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename TF,typename TC>
struct PrimalDual{
  struct edge{
    int to;
    TF cap;
    TC cost;
    int rev;
    edge(){}
    edge(int to,TF cap,TC cost,int rev):
      to(to),cap(cap),cost(cost),rev(rev){}
  };

  static const TC INF;
  vector<vector<edge>> G;
  vector<TC> h,dist;
  vector<int> prevv,preve;

  PrimalDual(){}
  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}

  void add_edge(int u,int v,TF cap,TC cost){
    G[u].emplace_back(v,cap,cost,G[v].size());
    G[v].emplace_back(u,0,-cost,G[u].size()-1);
  }

  void dijkstra(int s){
    struct P{
      TC first;
      int second;
      P(TC first,int second):first(first),second(second){}
      bool operator<(const P&a) const{return a.first<first;}
    };
    priority_queue<P> que;
    fill(dist.begin(),dist.end(),INF);

    dist[s]=0;
    que.emplace(dist[s],s);
    while(!que.empty()){
      P p=que.top();que.pop();
      int v=p.second;
      if(dist[v]<p.first) continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap==0) continue;
        if(dist[v]+e.cost+h[v]-h[e.to]<dist[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          que.emplace(dist[e.to],e.to);
        }
      }
    }
  }

  TC flow(int s,int t,TF f,int &ok){
    TC res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      dijkstra(s);
      if(dist[t]==INF){
        ok=0;
        return res;
      }

      for(int v=0;v<(int)h.size();v++)
        if(dist[v]<INF) h[v]=h[v]+dist[v];

      TF d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);

      f-=d;
      res=res+h[t]*d;
      for(int v=t;v!=s;v=prevv[v]){
        edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    ok=1;
    return res;
  }
};
template<typename TF, typename TC>
const TC PrimalDual<TF, TC>::INF = numeric_limits<TC>::max()/2;


template<typename TF,typename TC>
struct NegativeEdge{
  PrimalDual<TF, TC> G;
  vector<TF> fs;
  TC sum;
  int S,T;
  NegativeEdge(){}
  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}

  void use_edge(int u,int v,TF cap,TC cost){
    fs[u]-=cap;
    fs[v]+=cap;
    sum=sum+cost*cap;
  }

  void add_edge(int u,int v,TF cap,TC cost){
    if(cost<TC(0)){
      use_edge(u,v,cap,cost);
      swap(u,v);
      cost=-cost;
    }
    G.add_edge(u,v,cap,cost);
  }

  TC flow(int &ok){
    TF f=0;
    for(int i=0;i<S;i++){
      if(fs[i]>0){
        f+=fs[i];
        G.add_edge(S,i,+fs[i],TC(0));
      }
      if(fs[i]<0){
        G.add_edge(i,T,-fs[i],TC(0));
      }
    }
    return sum+G.flow(S,T,f,ok);
  }

  TC flow(int ts,int tt,TF tf,int &ok){
    fs[ts]+=tf;
    fs[tt]-=tf;
    return flow(ok);
  }
};

//INSERT ABOVE HERE
signed main(){
  using P = pair<int, int>;
  using ll = long long;
  const ll INF = 1e9;

  int n,m;
  cin>>n>>m;
  vector< vector<P> > H(n);
  NegativeEdge<ll, ll> G(n);
  for(int i=0;i<m;i++){
    int x,y,s;
    cin>>x>>y>>s;
    H[x].emplace_back(y,s);
    G.add_edge(y,x,1,-s-INF);
    G.add_edge(y,x,INF,-s);
  }

  vector<int> dp(n,0);
  for(int i=0;i<n;i++)
    for(auto e:H[i])
      chmax(dp[e.first],dp[i]+e.second);
  G.add_edge(0,n-1,INF,dp[n-1]);

  int ok=0;
  cout<<INF*m+G.flow(ok)<<endl;
  assert(ok);
  return 0;
}

