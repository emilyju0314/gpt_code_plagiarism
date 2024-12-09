#include <bits/stdc++.h>
using namespace std;
long long dp[4 * 100005], dp2[4 * 100005];
vector<pair<int, int> > g[4 * 100005];
int st[4 * 100005], par[4 * 100005];
int child[4 * 100005][2];
vector<int> node;
void build(int n, int s, int e, int p) {
  par[n] = p;
  if (s == e) return;
  int mid = (s + e) / 2;
  child[n][0] = n * 2;
  child[n][1] = n * 2 + 1;
  build(n * 2, s, mid, n);
  build(n * 2 + 1, mid + 1, e, n);
}
void find_node(int n, int s, int e, int l, int r) {
  if (s > r || l > e) return;
  if (l <= s && e <= r) {
    node.push_back(n);
    return;
  }
  int mid = (s + e) / 2;
  find_node(n * 2, s, mid, l, r);
  find_node(n * 2 + 1, mid + 1, e, l, r);
}
int main() {
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  int n, q, s;
  scanf("%d%d%d", &n, &q, &s);
  build(1, 1, n, 0);
  find_node(1, 1, n, s, s);
  s = node[0];
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      node.clear();
      find_node(1, 1, n, a, a);
      a = node[0];
      node.clear();
      find_node(1, 1, n, b, b);
      b = node[0];
      g[a].push_back(pair<int, int>(b, c));
    } else {
      int a, l, r, c;
      scanf("%d%d%d%d", &a, &l, &r, &c);
      node.clear();
      find_node(1, 1, n, a, a);
      a = node[0];
      node.clear();
      find_node(1, 1, n, l, r);
      if (t == 2) {
        for (int j = 0; j < node.size(); j++)
          g[a].push_back(pair<int, int>(node[j], c));
      } else {
        for (int j = 0; j < node.size(); j++)
          g[node[j]].push_back(pair<int, int>(a, c));
      }
    }
  }
  dp[s] = 0;
  priority_queue<pair<long long, int> > pq;
  pq.push(pair<long long, int>(0, s));
  while (!pq.empty()) {
    long long val = -pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dp[u] != val) continue;
    for (int i = 0; i < 2; i++) {
      if (child[u][i] == 0) continue;
      int v = child[u][i];
      if (dp[v] == -1 || dp[v] > dp[u])
        dp[v] = dp[u], pq.push(pair<long long, int>(-dp[v], v));
    }
    int cur = u;
    while (cur != 0) {
      if (dp2[cur] != -1 && dp2[cur] < dp[u]) break;
      dp2[cur] = dp[u];
      for (int i = 0; i < g[cur].size(); i++) {
        int v = g[cur][i].first;
        int w = g[cur][i].second;
        if (dp[v] == -1 || dp[v] > dp[u] + w)
          dp[v] = dp[u] + w, pq.push(pair<long long, int>(-dp[v], v));
      }
      cur = par[cur];
    }
  }
  pq.push(pair<long long, int>(0, s));
  for (int i = 1; i <= n; i++) {
    node.clear();
    find_node(1, 1, n, i, i);
    int cur = node[0];
    long long val = dp[cur];
    while (cur != 0) {
      if (val == -1)
        val = dp[cur];
      else if (dp[cur] != -1 && dp[cur] < val)
        val = dp[cur];
      cur = par[cur];
    }
    printf("%lld ", val);
  }
  printf("\n");
}
