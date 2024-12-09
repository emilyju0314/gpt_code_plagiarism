#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

class Edge {
public:
  long long int to;
  long long int max_flow;
  long long int rev;
};

class Dinic {
  int V;
public:
  vector< vector< Edge>> edge;
  vector< int > depth;
  vector< int > index;

  Dinic(int n) {
    n++;
    V = n;
    edge.resize(V);
    depth.resize(V);
    index.resize(V);
    return;
  }

  void Add_Edge(int l, int r, int max_flow) {
    edge[l].push_back({r, max_flow, (int) edge[r].size()});
    edge[r].push_back({l, 0, (int) edge[l].size() - 1});
    return;
  }

  void Check_Depth(int s) {
    for(int i = 0; i < V; i++) {
      depth[i] = INT_MAX;
    }
    depth[s] = 0;
    queue< int > Q;
    Q.push(s);
    while(!Q.empty()) {
      int cn = Q.front();
      Q.pop();
      for(auto i : edge[cn]) {
        if(i.max_flow > 0 && depth[i.to] == INT_MAX) {
          depth[i.to] = depth[cn] + 1;
          Q.push(i.to);
        }
      }
    }
    return;
  }

  long long int max_flow(int v, int g, long long int ret) {
    if(v == g) {
      return ret;
    }
    for(int i = index[v]; i < edge[v].size(); i++) {
      if(edge[v][i].max_flow > 0 && depth[v] < depth[edge[v][i].to]) {
        long long int d = max_flow(edge[v][i].to, g, min(ret, edge[v][i].max_flow));
        if(d > 0) {
          edge[v][i].max_flow -= d;
          edge[edge[v][i].to][edge[v][i].rev].max_flow += d;
          return d;
        }
      }
    }
    return 0;
  }

  long long Solve(int s, int g) {
    long long int ret = 0;
    while(1) {
      Check_Depth(s);
      if(depth[g] == INT_MAX) {
        return ret;
      }
      for(int i = 0; i < V; i++) {
        index[i] = 0;
      }
      long long int add = 0;
      while((add = max_flow(s, g, INT_MAX)) > 0) {
        ret += add;
      }
    }
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> L >> R;
  vector< vector< pair< int, int>> > edge(N + 1, vector< pair< int, int>>(N + 1, {-1, -1}));
  for(int i = 0; i < M; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    edge[a][b] = {c, d};
  }
  vector< int > dis(N + 1, MOD);
  dis[L] = 0;
  priority_queue< pair< int, int >, vector< pair< int, int>>, greater< pair< int, int>> > PQ;
  PQ.push({0, L});
  while(!PQ.empty()) {
    auto box = PQ.top();
    PQ.pop();
    int cn = box.second;
    int c = box.first;
    if(dis[cn] < c) {
      continue;
    }
    for(int i = 1; i <= N; i++) {
      if(edge[cn][i].first == -1) {
        continue;
      }
      if(dis[i] > c + edge[cn][i].first) {
        dis[i] = c + edge[cn][i].first;
        PQ.push({dis[i], i});
      }
    }
  }
  vector< vector< bool>> flag(N + 1, vector< bool >(N + 1, false));
  queue< int > Q;
  Q.push(R);
  bool v[1000] = {};
  while(!Q.empty()) {
    int cn = Q.front();
    Q.pop();
    for(int i = 1; i <= N; i++) {
      if(edge[i][cn].first == -1) {
        continue;
      }
      if(dis[cn] - edge[i][cn].first == dis[i]) {
        flag[i][cn] = true;
        if(v[i]++)continue;
        Q.push(i);
      }
    }
  }
  Dinic d(N + 2);
  d.Add_Edge(0, L, 100000);
  d.Add_Edge(R, N + 1, 100000);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(flag[i][j]) {
        d.Add_Edge(i, j, edge[i][j].second);
      }
    }
  }
  cout << d.Solve(0, N + 1) << endl;
  return 0;
}

