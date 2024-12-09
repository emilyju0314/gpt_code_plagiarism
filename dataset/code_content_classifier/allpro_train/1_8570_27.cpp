#include <bits/stdc++.h>
#define N 510
#define int long long
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> PP;
const int INF = 1LL<<55;
int n;
vector<P> G[N];
int A,B,C;

int dijkstra(int start,int goal,int v0,int flg = 1){
  vector<vector<int> > D(n,vector<int>(C,INF));
  priority_queue<PP,vector<PP>,greater<PP> >Q;
  D[start][v0] = 0;
  Q.push(PP(0,P(start,v0)));

  int res = INF;
  while(!Q.empty()){
    PP t = Q.top();Q.pop();
    int cost = t.first;
    int pos = t.second.first;
    int v = t.second.second;
    //cout<<flg<<" " <<pos<<" "<<cost<<" "<<v<<endl;
    if(D[pos][v] < cost) continue;
    
    if(pos == goal){
      if(flg == 1) res = min(res, cost + dijkstra(goal,start,v,0));
      if(flg == 0) return cost;
    }
    
    for(int i=0;i<G[pos].size();i++){
      int npos = G[pos][i].first;
      int ncost = cost + v * G[pos][i].second;
      int nv = (A*v+B)%C;
      if(D[npos][nv]<=ncost) continue;
      Q.push(PP(ncost,P(npos,nv)));
      D[npos][nv] = ncost;
    }
  }
  return res;
}


signed main(){
  int m;
  cin>>n>>m;

  for(int i=0;i<m;i++){
    int a,b,t;
    cin>>a>>b>>t;a--,b--;
    G[a].push_back(P(b,t));
    G[b].push_back(P(a,t));
  }
  int v0;
  cin>>v0;
  cin>>A>>B>>C;
  cout<<dijkstra(0,n-1,v0)<<endl;
}