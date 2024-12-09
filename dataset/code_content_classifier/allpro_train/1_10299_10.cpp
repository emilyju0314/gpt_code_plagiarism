#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > Pi;
struct edge
{
  int to, cost;
};
typedef vector< vector< edge > > Graph;
const int INF = 1 << 30;

vector< int > min_cost;
int Dijkstra(Graph& graph, int s)
{
  min_cost.assign(graph.size(), INF);
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.push(make_pair(0, s));
  min_cost[s] = 0;
  while(!que.empty()) {
    int now = que.top().second;
    int cost = que.top().first;
    que.pop();
    if(cost > min_cost[now]) continue;
    for(int i = 0; i < graph[now].size(); i++) {
      edge& e = graph[now][i];
      if(cost <= e.cost && e.cost < min_cost[e.to]) {
        min_cost[e.to] = e.cost;
        que.push(make_pair(min_cost[e.to], e.to));
      }
    }
  }
  return(-1);
}

int main()
{
  int N, M;
  cin >> N >> M;
  Graph g(N), rg(N);
  for(int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    --A, --B;
    g[A].push_back((edge){B, C});
    rg[B].push_back((edge){A, C});
  }
  Dijkstra(g, 0);
  int ret = -1;
  for(auto& e : rg[N - 1]) {
    if(min_cost[e.to] < INF && min_cost[e.to] <= e.cost) {
      ret = max(ret, e.cost);
    }
  }
  cout << ret << endl;
}