#include<bits/stdc++.h>
using namespace std;
 
#define ForEach(it,c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define UNQ(s) { sort(ALL(s)); (s).erase( unique( ALL(s)), (s).end());}
#define fr first
#define sc second
 
typedef pair< int , int > Pi;
typedef pair< int , Pi > Pii;
 
typedef long long int64;
const int INF = 1 << 30;

struct edge{
  int to, cost;
};
struct edge2{
  int u, v, cost;
  bool operator<(const edge2& hoge)const{
    return cost < hoge.cost;
  }
};
typedef vector< vector< edge > > Graph;
typedef vector< edge2 > Edges; /* 辺集合 */

void add_edge(Graph& info, int u, int v, int cost, bool flag = true){
  info[u].push_back( (edge){ v, cost});
  if(flag) info[v].push_back( (edge){ u, cost});
}
int Dijkstra(Graph& info, int s, int g, Graph& graph) { //sからgへの最短路
  typedef pair< int, int > Pi;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  vector< int > min_cost;
  min_cost.resize(info.size(), -1);
  que.push( Pi( 0, s));
  min_cost[s] = 0;
  while(!que.empty()){
    Pi p = que.top(); que.pop();
    if(p.second == g) return p.first;
    if(p.first > min_cost[p.second]) continue;
    for(int i = 0; i < info[p.second].size(); i++){
      edge& e = info[p.second][i];
      if(min_cost[e.to] == -1 || p.first + e.cost < min_cost[e.to]){
        min_cost[e.to] = p.first + e.cost;
        que.push( Pi( min_cost[e.to], e.to));
        graph[e.to].clear(); /* 最短ルートではない */
      }
      if(p.first + e.cost == min_cost[e.to]){
        add_edge( graph, e.to, p.second, -1, false); /* 最短ルート */
      }
    }
  }
  return -1;
}

Graph Make_Dag(Graph& graph, int start){
  vector< bool > used(graph.size(), false);
  queue< int > Que;
  Graph ret(graph.size());

  Que.push(start);
  used[start] = true;
  while(!Que.empty()){
    int idx = Que.front(); Que.pop();
    for(int i = 0; i < graph[idx].size(); i++){
      edge& e = graph[idx][i];
      add_edge( ret, e.to, idx, -1, false);
      if(used[e.to]) continue;
      used[e.to] = true;
      Que.push(e.to);
    }
  }
  return ret;
}

void dfs(int idx, vector< bool >& used, Graph& graph, vector< int >& ret){
  used[idx] = true;
  for(int i = 0; i < graph[idx].size(); i++){
    edge& e = graph[idx][i];
    if(!used[e.to]) dfs( e.to, used, graph, ret);
  }
  ret.push_back(idx);
}

vector< int > Topological(Graph& graph){
  vector< int > ret;
  vector< bool > used(graph.size(), false);
  for(int i = 0; i < graph.size(); i++){
    if(!used[i]) dfs( i, used, graph, ret);
  }
  reverse(ALL(ret));
  return ret;
}


void solve(Graph& graph, vector< int >& edges, vector< Pi >& query){
  vector< unsigned long long int > dp(graph.size());
  for(int _ = 0; _ < query.size(); _ += 64){
    int start = _, end = min< int >( _ + 64, query.size());
    fill( dp.begin(), dp.end(), 0uLL);
    for(int i = start; i < end; i++){
      dp[query[i].first] |= 1uLL << (i - start);
    }
    for(int __ = 0; __ < edges.size(); __++){
      int j = edges[__];
      if(dp[j] == 0uLL) continue;
      for(int k = 0; k < graph[j].size(); k++){
        dp[graph[j][k].to] |= dp[j];
      }
    }
    for(int i = start; i < end; i++){
      puts( ((dp[query[i].second] >> (i - start)) & 1) ? "Yes" : "No");
    }
  }
}

int main(){
  int S, R;
  scanf("%d %d", &S, &R);
  Graph info(S);
  for(int i = 0; i < R; i++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--, v--;
    add_edge( info, u, v, w);
  }
  int a, b, Q;
  scanf("%d %d %d", &a, &b, &Q);
  a--, b--;

  Graph graph(S);
  Dijkstra( info, a, -1, graph);
  Graph ret = Make_Dag(graph, b);
  vector< int > rets = Topological(ret);
  vector< Pi > query(Q);
  for(int i = 0; i < query.size(); i++){
    scanf("%d %d", &query[i].first, &query[i].second);
    query[i].first--, query[i].second--;
  }
  solve( ret, rets, query);
  return(0);
}