#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct edge{
  int from,to,cap,rev;
};
static const int INF = INT_MAX/3;
int dfs(int f,int v,int t,vector<vector<edge>> &g,vector<bool> &used){
  
  if(v == t) return f;
  used[v] = true;
  for(auto& e: g[v]){
    if(used[e.to]) continue;
    if(e.cap <= 0) continue;
    int d = dfs(min(e.cap,f), e.to, t, g, used);
    if(d > 0){
      e.cap -= d;
      g[e.to][e.rev].cap += d;
      return d;
    }
  }
  return 0;
}
int max_flow(int s,int t,vector<vector<edge>> &g){
  int f = 0;
  vector<bool> used(g.size());
  while(true){
    fill(used.begin(),used.end(),false);
    int df = dfs(INF,s,t,g,used);
    if(df == 0){
      break;
    }
    f += df;
  }
  return f;
}
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<edge>> g(v);
  for(int i = 0; i < e;i++){
    int u,v,c;
    cin >> u >> v >> c;
    g[u].push_back({u, v, c, (int)g[v].size()});
    g[v].push_back({v, u, 0, (int)g[u].size() - 1});
  }
  cout << max_flow(0,v-1,g) << endl;
}