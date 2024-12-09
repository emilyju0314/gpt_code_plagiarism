#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, cap, cost, next;
};
Edge E[22222];
int head[2222], ne = 1;
inline void addEdge(int from, int to, int cap, int cost) {
  E[++ne] = {to, cap, cost, head[from]}, head[from] = ne;
  E[++ne] = {from, 0, -cost, head[to]}, head[to] = ne;
}
long long d[2222];
int p[2222];
bool inqueue[2222];
pair<int, long long> mcmf(int S, int T) {
  int f = 0;
  long long c = 0;
  while (1) {
    for (int i = S; i <= T; ++i) d[i] = 1e18;
    queue<int> Q;
    Q.push(S);
    d[S] = 0;
    while (!Q.empty()) {
      auto v = Q.front();
      Q.pop();
      inqueue[v] = 0;
      for (int x = head[v]; x; x = E[x].next) {
        int &u = E[x].to, &cap = E[x].cap, &cost = E[x].cost;
        if (cap > 0 and d[v] + cost < d[u]) {
          d[u] = d[v] + cost;
          p[u] = x;
          if (!inqueue[u]) Q.push(u), inqueue[u] = 1;
        }
      }
    }
    if (d[T] == 1e18) break;
    int df = 1e9;
    for (int i = T; i != S; i = E[p[i] ^ 1].to) df = min(df, E[p[i]].cap);
    for (int i = T; i != S; i = E[p[i] ^ 1].to)
      E[p[i]].cap -= df, E[p[i] ^ 1].cap += df;
    f += df, c += df * d[T];
  }
  return {f, c};
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int S = 0, T = n + 2, TT = n + 1;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    addEdge(S, i, 1, a);
  }
  for (int i = 1; i <= n; ++i) {
    int b;
    cin >> b;
    addEdge(i, TT, 1, b);
  }
  for (int i = 1; i < n; ++i) addEdge(i, i + 1, k, 0);
  addEdge(TT, T, k, 0);
  auto ans = mcmf(S, T);
  cout << ans.second << endl;
  return 0;
}
