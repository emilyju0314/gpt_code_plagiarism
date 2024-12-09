#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)6e3 + 17;
const int INF = (int)0x3f3f3f3f;
struct edge {
  int to, cap, cost, rev;
  edge(int to = 0, int cap = 0, int cost = 0, int rev = 0)
      : to(to), cap(cap), cost(cost), rev(rev) {}
};
int N, M;
vector<edge> G[MAXN];
int dist[MAXN];
int prevv[MAXN];
int preve[MAXN];
inline void addedge(int from, int to, int cap, int cost) {
  G[from].push_back(edge(to, cap, cost, (int)G[to].size()));
  G[to].push_back(edge(from, 0, -cost, (int)G[from].size() - 1));
}
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    qu;
int h[MAXN];
int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h + 1, h + 1 + N, 0);
  while (f > 0) {
    while (!qu.empty()) qu.pop();
    memset(dist, 0x3f, sizeof(int) * (N + 2));
    dist[s] = 0;
    qu.push(pair<int, int>(0, s));
    while (!qu.empty()) {
      pair<int, int> now = qu.top();
      qu.pop();
      if (dist[now.second] < now.first) continue;
      int v = now.second;
      for (int i = (int)0; i <= (int)G[v].size() - 1; i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          qu.push(pair<int, int>(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == INF) return -1;
    for (int i = (int)1; i <= (int)N; i++) h[i] += dist[i];
    int d = f;
    for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}
void init() {
  for (int i = (int)1; i <= (int)N; i++) G[i].clear();
}
int a[MAXN];
int b[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, s, p;
  cin >> n >> p >> s;
  N = n;
  int S = ++N;
  int T = ++N;
  int aS = ++N;
  int bS = ++N;
  init();
  for (int i = (int)1; i <= (int)n; i++) {
    int x;
    cin >> x;
    addedge(aS, i, 1, -x);
  }
  for (int i = (int)1; i <= (int)n; i++) {
    int x;
    cin >> x;
    addedge(bS, i, 1, -x);
  }
  for (int i = (int)1; i <= (int)n; i++) {
    addedge(i, T, 1, 0);
  }
  addedge(S, aS, p, 0);
  addedge(S, bS, s, 0);
  int res = min_cost_flow(S, T, p + s);
  cout << -res << endl;
  for (int i = (int)0; i <= (int)G[aS].size() - 1; i++) {
    if (G[aS][i].cap == 0 && G[aS][i].to != S) cout << G[aS][i].to << " ";
  }
  cout << endl;
  for (int i = (int)0; i <= (int)G[bS].size() - 1; i++) {
    if (G[bS][i].cap == 0 && G[bS][i].to != S) cout << G[bS][i].to << " ";
  }
  cout << endl;
}
