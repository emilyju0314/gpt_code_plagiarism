#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
long long dp[maxn][2], ans;
int u, v, w, n, d[maxn], D, be[maxn];
vector<int> F[maxn], H[maxn];
bool vis[maxn];
struct oyyj_queue {
  priority_queue<long long> p, q;
  int sz;
  long long sum;
  void push(long long x) {
    p.push(x);
    ++sz;
    sum += x;
  }
  void del(long long x) {
    q.push(x);
    --sz;
    sum -= x;
  }
  void fix() {
    while (!p.empty() && !q.empty() && p.top() == q.top()) p.pop(), q.pop();
  }
  long long top() {
    fix();
    return p.top();
  }
  void pop() {
    fix();
    sum -= p.top();
    p.pop();
    --sz;
  }
  bool empty() { return !sz; }
} wyl[maxn];
struct DSY {
  int v, w;
};
vector<DSY> G[maxn];
inline bool operator<(DSY a, DSY b) { return d[a.v] < d[b.v]; }
inline void add(int u, int v, int w) { G[u].push_back((DSY){v, w}); }
void dfs(int u, int fa) {
  int fxk = d[u] - D;
  long long tot = 0;
  vis[u] = 1;
  while (wyl[u].sz > fxk) wyl[u].pop();
  vector<long long> v1, v2;
  while (be[u] < G[u].size() && d[G[u][be[u]].v] <= D) ++be[u];
  for (int i = (be[u]); i <= ((int)G[u].size() - 1); ++i) {
    int v = G[u][i].v, w = G[u][i].w;
    if (vis[v] || v == fa || d[v] <= D) continue;
    dfs(v, u);
    if (dp[v][1] + w <= dp[v][0])
      --fxk, tot += dp[v][1] + w;
    else
      tot += dp[v][0], wyl[u].push(dp[v][1] + w - dp[v][0]),
          v2.push_back(dp[v][1] + w - dp[v][0]);
  }
  while (!wyl[u].empty() && wyl[u].sz > fxk)
    v1.push_back(wyl[u].top()), wyl[u].pop();
  dp[u][0] = wyl[u].sum + tot;
  --fxk;
  while (!wyl[u].empty() && wyl[u].sz > fxk)
    v1.push_back(wyl[u].top()), wyl[u].pop();
  dp[u][1] = wyl[u].sum + tot;
  for (long long x : v1) wyl[u].push(x);
  for (long long x : v2) wyl[u].del(x);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); ++i)
    scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, w), ++d[u], ++d[v];
  for (int i = (1); i <= (n); ++i) sort(G[i].begin(), G[i].end());
  for (int i = (1); i <= (n); ++i) F[d[i]].push_back(i);
  for (int i = (1); i <= (n); ++i)
    for (int j = (0); j <= (d[i] - 1); ++j) H[j].push_back(i);
  for (int i = (0); i <= (n - 1); ++i) {
    D = i;
    ans = 0;
    for (int u : F[i])
      for (auto x : G[u]) {
        if (d[x.v] < i) continue;
        wyl[x.v].push(x.w);
      }
    for (int u : H[i])
      if (!vis[u]) dfs(u, 0), ans += dp[u][0];
    for (int u : H[i]) vis[u] = 0;
    printf("%lld ", ans);
  }
  return 0;
}
