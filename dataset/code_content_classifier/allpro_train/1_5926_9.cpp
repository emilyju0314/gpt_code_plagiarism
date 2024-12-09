#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-9;
const int MAXN = 2e6 + 5;
int code(char c) {
  if ('a' <= c && c <= 'z') {
    return c - 'a';
  }
  return (c - 'A') + 26;
}
char decode(int c) {
  if (c < 26) {
    return 'a' + c;
  }
  return 'A' + (c - 26);
}
int k;
struct Edge {
  int v, to, cap, cost, flow;
};
struct Graph {
  vector<Edge> e;
  vector<vector<int> > g;
  int n;
  Graph() {}
  Graph(int n) : n(n) { g.resize(n); }
  void AddE(int v, int to, int cost) {
    g[v].push_back(((int)(e).size()));
    e.push_back({v, to, 1, cost, 0});
    g[to].push_back(((int)(e).size()));
    e.push_back({to, v, 0, -cost, 0});
  }
  int AddFlow() {
    vector<int> dist(n, (int)2e9);
    vector<int> prev(n, -1);
    dist[0] = 0;
    for (int _ = 0; _ < (int)n + 5; ++_) {
      for (int id = 0; id < (int)((int)(e).size()); ++id) {
        auto E = e[id];
        if (E.cap > E.flow) {
          if (dist[E.v] + E.cost < dist[E.to]) {
            dist[E.to] = dist[E.v] + E.cost;
            prev[E.to] = id;
          }
        }
      }
    }
    if (prev[n - 1] == -1) {
      return 0;
    }
    int add = 2e9;
    int v = n - 1;
    while (prev[v] != -1) {
      int id = prev[v];
      add = min(add, e[id].cap - e[id].flow);
      v = e[id].v;
    }
    v = n - 1;
    while (prev[v] != -1) {
      int id = prev[v];
      e[id].flow += add;
      e[id ^ 1].flow -= add;
      v = e[id].v;
    }
    return add;
  }
  void Go() {
    int F = 0;
    while (1) {
      int add = AddFlow();
      if (!add) break;
      F += add;
    }
    int res = 0;
    for (int v = 1; v <= k; ++v) {
      for (int id : g[v]) {
        if (e[id].to && e[id].flow) {
          res += -e[id].cost;
          break;
        }
      }
    }
    cout << res << endl;
    for (int v = 1; v <= k; ++v) {
      for (int id : g[v]) {
        if (e[id].to && e[id].flow) {
          printf("%c", decode(e[id].to - k - 1));
          break;
        }
      }
    }
    puts("");
  }
};
int n;
char second[MAXN];
char t[MAXN];
int cost[60][60];
Graph G;
int main() {
  cin >> n >> k;
  scanf("\n");
  gets(second);
  gets(t);
  G = Graph(1 + k + k + 1);
  for (int i = 1; i <= k; ++i) {
    G.AddE(0, i, 0);
  }
  for (int i = k + 1; i <= k + k; ++i) {
    G.AddE(i, 1 + k + k, 0);
  }
  for (int i = 0; i < (int)n; ++i) {
    ++cost[code(second[i])][code(t[i])];
  }
  for (int i = 0; i < (int)k; ++i) {
    for (int j = 0; j < (int)k; ++j) {
      G.AddE(1 + i, 1 + k + j, -cost[i][j]);
    }
  }
  G.Go();
  return 0;
}
