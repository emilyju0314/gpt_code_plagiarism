#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
const int inf = 0x3f3f3f3f;
struct Edge {
  int from, to, cap, flow, cost;
};
struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool inq[maxn];
  int dis[maxn], path[maxn], a[maxn];
  void init(int n) { this->n = n; }
  void add(int from, int to, int cap, int cost) {
    edges.push_back((Edge){from, to, cap, 0, cost});
    edges.push_back((Edge){to, from, 0, 0, -cost});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  bool Bellman_Ford(int s, int t, int &flow, int &cost) {
    for (int i = 0; i <= n; i++) dis[i] = inf;
    memset(inq, 0, sizeof inq);
    dis[s] = 0, inq[s] = true, path[s] = 0, a[s] = inf;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      inq[u] = false;
      for (int i = 0; i < G[u].size(); i++) {
        Edge &e = edges[G[u][i]];
        if (e.cap > e.flow && dis[e.to] > dis[u] + e.cost) {
          dis[e.to] = dis[u] + e.cost;
          path[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) {
            que.push(e.to);
            inq[e.to] = true;
          }
        }
      }
    }
    if (dis[t] == inf) return false;
    flow += a[t];
    cost += dis[t] * a[t];
    for (int u = t; u != s; u = edges[path[u]].from) {
      edges[path[u]].flow += a[t];
      edges[path[u] ^ 1].flow -= a[t];
    }
    return true;
  }
  int mcmf(int s, int t) {
    int flow = 0, cost = 0;
    while (Bellman_Ford(s, t, flow, cost))
      ;
    return cost;
  }
} ans;
char s[maxn];
int a[maxn], b[maxn];
int main() {
  int n;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int S = 0, T = n / 2 + 26 + 1;
  ans.init(T);
  for (int i = 1; i <= n; i++) b[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) ans.add(S, i + 1, b[i], 0);
  for (int i = 1; i <= n / 2; i++) {
    if (s[i] == s[n - i + 1]) {
      int c = s[i] - 'a', p = max(a[i], a[n - i + 1]);
      ans.add(c + 1, i + 26, 1, -p);
    } else {
      ans.add(s[i] - 'a' + 1, i + 26, 1, -a[i]);
      ans.add(s[n - i + 1] - 'a' + 1, i + 26, 1, -a[n - i + 1]);
    }
    for (int j = 0; j < 26; j++)
      if (j != s[i] - 'a' && j != s[n - i + 1] - 'a')
        ans.add(j + 1, i + 26, 1, 0);
    ans.add(i + 26, T, 2, 0);
  }
  printf("%d\n", -ans.mcmf(S, T));
  return 0;
}
