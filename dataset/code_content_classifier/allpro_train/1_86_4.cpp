#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e6 + 500;
const long long int mod = 998244353;
int dep[maxn], low[maxn], ans[maxn], dp[maxn];
int head[maxn], cnt;
int n, k;
struct C {
  int next, to;
} E[maxn];
void add(int x, int y) {
  E[cnt].to = y;
  E[cnt].next = head[x];
  head[x] = cnt++;
}
void dfs1(int u, int fa) {
  low[u] = 0x7f7f7f7f;
  dep[u] = dep[fa] + 1;
  if (head[u] == -1) {
    low[u] = dep[u];
    dp[u] = 1;
  } else {
    for (int i = head[u]; i + 1; i = E[i].next) {
      int v = E[i].to;
      dfs1(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] - k <= dep[u]) dp[u] += dp[v];
    }
  }
}
int dfs(int u, int fa) {
  if (head[u] == -1) return 1;
  int ans = 0;
  for (int i = head[u]; i + 1; i = E[i].next) {
    int v = E[i].to;
    int temp = dp[u];
    if (low[v] - k <= dep[u]) temp -= dp[v];
    ans = max(ans, temp + dfs(v, u));
  }
  return ans;
}
int main() {
  int x;
  scanf("%d%d", &n, &k);
  memset(head, -1, sizeof head);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &x);
    add(x, i);
  }
  dfs1(1, 0);
  printf("%d\n", dfs(1, 0));
}
