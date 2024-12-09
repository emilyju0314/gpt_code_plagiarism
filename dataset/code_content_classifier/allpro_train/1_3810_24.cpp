#include <bits/stdc++.h>
using namespace std;

struct edge {
  int to;
  int64_t cost;
  edge(int to, int64_t cost) : to(to), cost(cost) {}
};

vector<vector<edge>> G;

void add_edge(int a, int b, int c, int64_t d) {
  G[a].push_back(edge(b, d));
  G[a].push_back(edge(c, d));
  G[b].push_back(edge(a, d));
  G[b].push_back(edge(c, d));
  G[c].push_back(edge(a, d));
  G[c].push_back(edge(b, d));
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  s--, t--;

  G.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    add_edge(a - 1, b - 1, c - 1, d);
  }

  vector<int64_t> d(n, 1001001001001001001ll);

  using P = pair<int64_t, int>;
  priority_queue<P, vector<P>, greater<P>> pq;

  d[s] = 0;
  pq.push(P(0, s));

  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();

    int v = p.second;
    if (p.first < d[v]) continue;
    for (auto &e : G[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push(P(d[e.to], e.to));
      }
    }
  }

  cout << d[t] << endl;
}

