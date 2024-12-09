#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int mod = 1e9 + 7;
struct edge {
  int to, next;
  long long w;
} e[maxn << 1];
int head[maxn], now, n, vis[maxn];
long long w[maxn], dp[maxn], ans;
void add(int u, int v, long long val) {
  e[now].to = v, e[now].w = val;
  e[now].next = head[u], head[u] = now++;
}
void dfs(int u, int fa) {
  ans = max(ans, dp[u]);
  vis[u] = 1;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa || vis[v]) continue;
    dfs(v, u);
    ans = max(ans, dp[u] + dp[v] - e[i].w);
    dp[u] = max(dp[u], w[u] + dp[v] - e[i].w);
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
    dp[i] = w[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    long long co;
    scanf("%d%d%lld", &u, &v, &co);
    add(u, v, co);
    add(v, u, co);
  }
  dfs(1, -1);
  printf("%lld\n", ans);
  return 0;
}
