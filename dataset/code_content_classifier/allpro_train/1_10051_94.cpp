#include <bits/stdc++.h>
using namespace std;
int const N = 100000;
vector<pair<int, int> > g[N + 1];
vector<int> imp;
long long cl[42][N + 1];
int dp[N + 1], n;
pair<int, long long> pa[N + 1][17];
bool vis[N + 1];
void pl(int v = 1, int p = 0, int w = 0) {
  dp[v] = dp[p] + 1;
  vis[v] = true;
  pa[v][0] = make_pair(p, w);
  int k = 1, z;
  while (k < 17 && (z = pa[v][k - 1].first))
    pa[v][k] = make_pair(pa[z][k - 1].first,
                         pa[v][k - 1].second + pa[z][k - 1].second),
    ++k;
  for (int i = 0; i < (int)(g[v].size()); ++i) {
    int u = g[v][i].first;
    if (u == p) continue;
    if (vis[u])
      imp.push_back(v), imp.push_back(u);
    else
      pl(u, v, g[v][i].second);
  }
}
long long dis(int a, int b) {
  if (dp[a] < dp[b]) swap(a, b);
  int d = dp[a] - dp[b], j = 0;
  long long an = 0;
  while (d) {
    if (d & 1) an += pa[a][j].second, a = pa[a][j].first;
    d >>= 1;
    ++j;
  }
  if (a == b) return an;
  for (int i = 16; i >= 0; --i)
    if (pa[a][i].first != pa[b][i].first)
      an += pa[a][i].second + pa[b][i].second, a = pa[a][i].first,
                                               b = pa[b][i].first;
  return an + pa[a][0].second + pa[b][0].second;
}
void bfs(int v, long long dis[]) {
  for (int i = 1; i < (int)(n + 1); ++i) dis[i] = 1e18;
  priority_queue<pair<long long, int> > q;
  q.push(make_pair(0, v));
  dis[v] = 0;
  while (!q.empty()) {
    int v = q.top().second;
    long long d = -q.top().first;
    q.pop();
    for (int i = 0; i < (int)(g[v].size()); ++i) {
      int u = g[v][i].first;
      long long nd = d + g[v][i].second;
      if (dis[u] > nd) {
        dis[u] = nd;
        q.push(make_pair(-nd, u));
      }
    }
  }
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(m); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  pl();
  sort(imp.begin(), imp.end());
  imp.resize(unique(imp.begin(), imp.end()) - imp.begin());
  for (int i = 0; i < (int)(imp.size()); ++i) bfs(imp[i], cl[i]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    long long an = dis(a, b);
    for (int i = 0; i < (int)(imp.size()); ++i)
      for (int j = 0; j < (int)(imp.size()); ++j)
        an = min(an, cl[i][a] + cl[i][imp[j]] + cl[j][b]);
    printf("%lld\n", an);
  }
}
