#include <bits/stdc++.h>
using namespace std;
struct NetworkFlow {
  struct Edge {
    int target, inverse_index;
    int capacity, flow;
    Edge(int t, int c, int ii)
        : target(t), capacity(c), flow(0), inverse_index(ii) {}
    int residual() const { return capacity - flow; }
  };
  int V;
  vector<vector<Edge> > adj;
  vector<int> levels, edges_tried;
  NetworkFlow(int V) : V(V), adj(V), levels(V), edges_tried(V) {}
  void add_edge(int a, int b, int a2b, int b2a = 0) {
    int a2b_index = adj[a].size(), b2a_index = adj[b].size();
    adj[a].push_back(Edge(b, a2b, b2a_index));
    adj[b].push_back(Edge(a, b2a, a2b_index));
  }
  bool assign_levels(int source, int sink) {
    fill(levels.begin(), levels.end(), -1);
    queue<int> q;
    q.push(source);
    levels[source] = 0;
    while (!q.empty()) {
      int here = q.front();
      q.pop();
      for (int i = 0; i < adj[here].size(); ++i) {
        const Edge& e = adj[here][i];
        if (levels[e.target] == -1 && e.residual() > 0) {
          levels[e.target] = levels[here] + 1;
          q.push(e.target);
        }
      }
    }
    return levels[sink] != -1;
  }
  int push_flow(int here, int sink, int flow) {
    if (here == sink) return flow;
    for (int& i = edges_tried[here]; i < adj[here].size(); ++i) {
      Edge& e = adj[here][i];
      if (e.residual() > 0 && levels[e.target] == levels[here] + 1) {
        int amt = push_flow(e.target, sink, min(flow, e.residual()));
        if (amt > 0) {
          Edge& e_inv = adj[e.target][e.inverse_index];
          e.flow += amt;
          e_inv.flow = -e.flow;
          return amt;
        }
      }
    }
    return 0;
  }
  int go(int source, int sink) {
    int total_flow = 0;
    while (assign_levels(source, sink)) {
      fill(edges_tried.begin(), edges_tried.end(), 0);
      while (true) {
        int pushed = push_flow(source, sink, numeric_limits<int>::max());
        if (pushed == 0) break;
        total_flow += pushed;
      }
    }
    return total_flow;
  }
};
int main() {
  int n, m, x;
  int a[505], b[505], c[505];
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  double lo, hi, md;
  lo = 1 / (double)(x);
  hi = 1000000;
  for (int k = 1; k <= 100; k++) {
    md = (lo + hi) / 2.0;
    NetworkFlow f(n + 1);
    f.add_edge(0, 1, x);
    for (int i = 1; i <= m; i++) {
      f.add_edge(a[i], b[i], (int)(c[i] / md), 0);
    }
    int flow = f.go(0, n);
    if (flow >= x)
      lo = md;
    else
      hi = md;
  }
  printf("%.8lf", md * x);
}
