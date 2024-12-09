#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//各ルートの最短だす
//二点間が最短じゃなかったらカウントだなも
int main(){
  ll N,M; cin>>N>>M;
  vector<vector<ll>> path(N+1, vector<ll>(N+1,1e6)), graph(N+1, vector<ll>(N+1,1e6));
  for(int i=0; i<M; i++){
    ll a,b,c; cin>>a>>b>>c;
    graph[a][b]=c;
    graph[b][a]=c;
  }
  for(int i=0; i<=N; i++) graph[i][i]=0;
  path=graph;
  for(int k=1; k<=N; k++){
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
      }
    }
  }
  ll ans=0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
//      cout<<"i:"<<i<<" j:"<<j<<" path:"<<path[i][j]<<" graph:"<<graph[i][j]<<endl;
      if(path[i][j]==graph[i][j] || graph[i][j]==1e6) continue;
      ans++;
    }
  }
  cout<<ans/2<<endl;
}
