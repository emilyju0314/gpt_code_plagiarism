#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

struct edge{
  int to;
  i64 cost;
};

vector<edge> G[101010];
i64 dist[101010];

void dfs1(int v,int f = -1){
  for(edge &  e : G[v]){
    if(e.to == f) continue;
    dfs1(e.to , v);
    dist[v] = max(dist[v] , dist[e.to] + e.cost);
  }
}

int dfs2(int v,int d_f = 0,int f = -1){
  vector< pair<int,int> > d_child;
  d_child.push_back({0,-1});
  for(edge & e : G[v]){
    if(e.to == f) d_child.push_back({d_f + e.cost , e.to});
    else d_child.push_back({e.cost + dist[e.to] , e.to});
  }
  sort(d_child.rbegin(),d_child.rend());
  int ret = d_child[0].first + d_child[1].first;
  for(edge & e : G[v]){
    if(e.to == f) continue;
    ret = max(ret , dfs2(e.to,d_child[d_child[0].second == e.to].first , v));
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  for(int i = 0;i < N - 1;i++){
    int a,b,w;
    cin >> a >> b >> w;
    G[a].push_back({b,(i64)w});
    G[b].push_back({a,(i64)w});
  }
  dfs1(N / 2);
  cout << dfs2(N / 2) << endl;
}

