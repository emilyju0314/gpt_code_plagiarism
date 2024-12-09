#include <bits/stdc++.h>
using namespace std;
const long long __64inf = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2e6 + 50;
const int mod = 19930726;
int n, m, s;
vector<int> E[MAX];
long long w[MAX], ww[MAX];
vector<int> EE[MAX];
bool vis[MAX];
stack<int> stk;
long long dfn[MAX], num, col[MAX], low[MAX], f[MAX];
bool loop[MAX], back[MAX];
long long dp[MAX];
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++num;
  stk.push(u);
  vis[u] = 1;
  for (int i = 0; i < E[u].size(); i++) {
    int v = E[u][i];
    if (v == p) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (vis[v])
      low[u] = min(low[u], low[v]);
  }
  if (low[u] == dfn[u]) {
    while (!stk.empty() and stk.top() != u) {
      int v = stk.top();
      stk.pop();
      loop[u] = 1;
      f[v] = u;
      vis[v] = 0;
      back[u] = 1;
      w[u] += w[v];
      ww[u] += w[v];
      for (int i = 0; i < E[v].size(); i++) {
        if (f[E[v][i]] == E[v][i]) {
          dp[u] += dp[E[v][i]];
          EE[u].push_back(E[v][i]);
          if (back[E[v][i]]) back[u] = 1;
        }
      }
    }
    stk.pop();
    f[u] = u;
    for (int i = 0; i < E[u].size(); i++) {
      if (f[E[u][i]] == E[u][i]) {
        EE[u].push_back(E[u][i]);
        dp[u] += dp[E[u][i]];
        if (back[E[u][i]]) back[u] = 1;
      }
    }
    ww[u] += w[u];
    vis[u] = 0;
    if (back[u]) dp[u] += w[u];
  }
}
int dfs(int u, int p) {
  long long sum = ww[u];
  bool isloop = 0;
  for (int i = 0; i < EE[u].size(); i++) {
    int v = EE[u][i];
    if (v == p) continue;
    int tmp = dfs(v, u);
    sum += tmp;
    isloop |= !!tmp;
  }
  dp[u] = sum;
  return loop[u] | isloop ? sum : 0;
}
long long ans = 0;
void dfs2(int u, int p, long long sum) {
  sum += dp[u];
  if (!back[u]) sum += w[u];
  ans = max(ans, sum);
  for (int i = 0; i < EE[u].size(); i++) {
    int v = EE[u][i];
    dfs2(v, u, sum - dp[v]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", w + i);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  scanf("%d", &s);
  tarjan(s, -1);
  dfs2(s, -1, 0);
  printf("%lld\n", ans);
  return 0;
}
