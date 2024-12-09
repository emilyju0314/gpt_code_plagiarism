#include <bits/stdc++.h>

using namespace std;

struct edge {
  int to, dist, cost;
  edge(){}
  edge(int to, int dist, int cost):to(to), dist(dist), cost(cost){}
};

typedef pair<int, int> P;
typedef pair<P, int> PP;

int N, M;
vector< vector<edge> > G;

const int inf = 1<<25;

int dijkstra()
{
  vector<int> mindist(N, inf);
  priority_queue<PP, vector<PP>, greater<PP> > que;
  que.push(PP(P(0, 0), 0));
  int ret = 0;
  while(!que.empty()) {
    PP p = que.top(); que.pop();
    int now = p.second, dist = p.first.first, cost = p.first.second;
    if(mindist[now] <= dist) continue;
    mindist[now] = dist;
    ret += cost;
    for(edge& e : G[now]) {
      if(mindist[e.to] >= dist + e.dist) {
	que.push(PP(P(dist + e.dist, e.cost), e.to));
      }
    }
  }
  return ret;
}

int main()
{
  while(cin >> N >> M, N || M) {
    G.clear(); G.resize(N);
    for(int i = 0; i < M; i++) {
      int u, v, d, c;
      cin >> u >> v >> d >> c;
      u--, v--;
      G[u].push_back(edge(v, d, c));
      G[v].push_back(edge(u, d, c));
    }
    cout << dijkstra() << endl;
  }
  return 0;
}