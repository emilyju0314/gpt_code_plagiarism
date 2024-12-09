#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const long long INF = 1LL << 60;
struct P {
  long long d, cost;
  int num, v;
  P(long long d = 0, long long cost = 0, int num = 0, int v = 0)
      : d(d), cost(cost), num(num), v(v) {}
  friend bool operator>(const P a, const P b) {
    if (a.d != b.d) {
      return a.d > b.d;
    }
    return a.cost > b.cost;
  }
};
struct edge {
  int to, num, cost;
  edge(int to = 0, int num = 0, int cost = 0) : to(to), num(num), cost(cost) {}
};
vector<edge> E[maxn];
vector<int> t;
long long d[maxn];
long long cost[maxn];
long long solve(int u, int n) {
  priority_queue<P, vector<P>, greater<P> > q;
  fill(cost + 1, cost + n + 1, INF);
  fill(d + 1, d + n + 1, INF);
  d[u] = cost[u] = 0;
  q.push(P(0, 0, -1, u));
  long long res = 0;
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int v = p.v;
    if (d[v] != p.d || cost[v] != p.cost) {
      continue;
    }
    res += cost[v];
    if (p.num != -1) {
      t.push_back(p.num + 1);
    }
    for (int i = 0; i < E[v].size(); ++i) {
      edge e = E[v][i];
      if ((d[e.to] > d[v] + e.cost) ||
          (d[e.to] == d[v] + e.cost && cost[e.to] > e.cost)) {
        cost[e.to] = e.cost;
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], cost[e.to], e.num, e.to));
      }
    }
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, l;
    cin >> x >> y >> l;
    E[x].push_back(edge(y, i, l));
    E[y].push_back(edge(x, i, l));
  }
  int u;
  cin >> u;
  cout << solve(u, n) << endl;
  for (int i = 0; i < t.size(); ++i) {
    cout << t[i] << (i != t.size() ? ' ' : '\n');
  }
  return 0;
}
