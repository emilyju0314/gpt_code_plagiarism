#include <bits/stdc++.h>
using namespace std;
const int N = 810, E = N * N, INF = 1e9;
int n, ed = 0, from[E], to[E], cap[E], head[N], nex[E], par[N];
long double dis[N], cost[E];
bool mark[N];
pair<int, int> x[N];
long double dist(int u, int v) {
  return pow((x[u].first - x[v].first) * (x[u].first - x[v].first) +
                 (x[u].second - x[v].second) * (x[u].second - x[v].second),
             0.5);
}
void add_edge(int u, int v, int c, long double co) {
  from[ed] = u, to[ed] = v, cap[ed] = c, cost[ed] = co, nex[ed] = head[u],
  head[u] = ed++;
  from[ed] = v, to[ed] = u, cap[ed] = 0, cost[ed] = -co, nex[ed] = head[v],
  head[v] = ed++;
}
pair<int, long double> spfa(int sink, int source) {
  for (int i = 0; i < N; i++) dis[i] = INF;
  memset(mark, 0, sizeof mark);
  memset(par, -1, sizeof par);
  queue<int> q;
  dis[source] = 0, mark[source] = true;
  q.push(source);
  while (q.size()) {
    int v = q.front();
    q.pop();
    mark[v] = false;
    for (int e = head[v]; e != -1; e = nex[e]) {
      if (cap[e] && dis[to[e]] > dis[v] + cost[e]) {
        dis[to[e]] = dis[v] + cost[e];
        par[to[e]] = e;
        if (!mark[to[e]]) q.push(to[e]), mark[to[e]] = true;
      }
    }
  }
  int curr = sink;
  if (dis[curr] == INF) return make_pair(0, 0);
  long double res = 0;
  int flow = INF;
  while (curr != source) {
    flow = min(flow, cap[par[curr]]);
    curr = from[par[curr]];
  }
  curr = sink;
  while (curr != source) {
    res += cost[par[curr]];
    cap[par[curr]] -= flow;
    cap[par[curr] ^ 1] += flow;
    curr = from[par[curr]];
  }
  return make_pair(flow, res);
}
pair<int, long double> MinCostMaxFlow(int sink, int source) {
  int flow = 0;
  pair<int, long double> f = {INF, 0};
  long double Cost = 0;
  while (f.first) {
    f = spfa(sink, source);
    flow += f.first;
    Cost += f.second;
  }
  return make_pair(flow, Cost);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i].second >> x[i].first;
  sort(x + 1, x + n + 1);
  reverse(x + 1, x + n + 1);
  if (x[1].first == x[2].first) return cout << -1 << endl, 0;
  memset(head, -1, sizeof head);
  int source = 0, sink = 2 * n + 1;
  for (int i = 1; i <= n; i++) add_edge(source, i, 2, 0);
  for (int i = 2; i <= n; i++) add_edge(i + n, sink, 1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (x[j].first < x[i].first) add_edge(i, n + j, 1, dist(i, j));
  auto X = MinCostMaxFlow(sink, source);
  if (X.first < n - 1)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(15) << X.second << endl;
}
