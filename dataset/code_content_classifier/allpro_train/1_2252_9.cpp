#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 100005
ll N,M,R,Q;
struct edge {ll to,cost;};
vector< edge > G[MAX_N+100];

ll d[11][MAX_N+100];
typedef pair<ll,ll> P;

void dijkstra(int si,ll d[MAX_N+100]){
  si+=MAX_N;
  fill(d,d+MAX_N+100, (1LL<<60) );
  d[si]=0;
  priority_queue< P , vector<P> , greater<P> > Q;
  Q.push( P(0,si) );
  while(!Q.empty()){
    P p=Q.top();Q.pop();
    ll cost=p.first;
    ll pos=p.second;
    if(d[pos]<cost)continue;
    for(int i=0;i<(int)G[pos].size();i++){
      edge e=G[pos][i];
      if(d[e.to]<=cost+e.cost)continue;
      d[e.to]=cost+e.cost;
      Q.push( P(d[e.to],e.to) );
    }
  }
}

int main(){
  scanf("%lld %lld %lld %lld",&N,&M,&R,&Q);
  for(int i=0;i<M;i++){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    G[b].push_back( (edge){a,c} );
  }
  for(ll i=1;i<=N;i++){
    G[MAX_N+i%R].push_back( (edge){i,0} );
  }
  for(int i=0;i<R;i++)dijkstra(i,d[i]);

  ll ans=0;
  while(Q--){
    ll x,y,z;
    scanf("%lld %lld %lld",&x,&y,&z);
    ll mini=(1LL<<60);
    for(int i=0;i<R;i++){
      mini=min(mini, d[i][x]+d[i][y]);
    }
    if(mini<z){
      ans+=(z-mini);
    }
  }
  printf("%lld\n",ans);
  return 0;
}