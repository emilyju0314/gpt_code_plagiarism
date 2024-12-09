#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_V 111111
#define int long long
int V,E;
vector<int> G[MAX_V];
int used[MAX_V];
void add_edge(int a,int b){
  G[a].push_back(b);
  G[b].push_back(a);
}
int a[2];
bool dfs(int v,int c){
  if(~used[v]) return used[v]==c;
  bool f=1;
  a[c]++;used[v]=c;
  for(int i=0;i<(int)G[v].size();i++) f&=dfs(G[v][i],!c);
  return f;
}
typedef pair<int,int> P;
bool dp[2][MAX_V];
int solve(){
  int x=0;
  vector<P> v;
  memset(used,-1,sizeof(used));
  for(int i=0;i<V;i++){
    if(used[i]>=0) continue;
    a[0]=a[1]=0;
    if(dfs(i,0)){
      if(a[1]) v.push_back(P(a[1],a[0]));
      else x++;
    }else return -1;
  }
  int k=0,m=0;
  memset(dp[0],0,sizeof(dp[0]));
  dp[0][0]=1;
  for(int i=0;i<(int)v.size();i++){
    bool f=i%2;
    memset(dp[!f],0,sizeof(dp[!f]));
    for(int j=0;j<=m;j++){
      if(dp[f][j])
	dp[!f][j+v[i].first]=dp[!f][j+v[i].second]=1,
	  m=max(m,j+max(v[i].first,v[i].second));
    }
  }
  for(int i=0;i<V;i++){
    if(dp[v.size()%2][i]){
      for(int j=0;j<=x&&i+j<V;j++){
	//cout<<i+j<<":"<<(V-(i+j))*(i+j)<<endl;
	if((V-k)*k<(V-(i+j))*(i+j)) k=i+j;
      }
    }
  }
  return (V-k)*k-E;
}
signed main(){
  cin>>V>>E;
  for(int i=0,a,b;i<E;i++) cin>>a>>b,add_edge(a-1,b-1);
  cout<<solve()<<endl;
  return 0;
}