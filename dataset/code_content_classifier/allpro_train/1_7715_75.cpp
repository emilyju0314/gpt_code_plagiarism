#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 77, mod = 998244353;
long long f[N], g[N], h[N];
int n, cnt, ls[N];
struct E {
  int to, next;
} e[N];
void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].next = ls[u];
  ls[u] = cnt;
}
void dfs(int u) {
  if (!ls[u]) {
    g[u] = 1;
    return;
  }
  h[u] = 1;
  for (int i = ls[u]; i; i = e[i].next) {
    int v = e[i].to;
    dfs(v);
    g[u] = (g[u] * (f[v] + 2 * g[v] + h[v]) + f[u] * (f[v] + g[v])) % mod;
    f[u] = (f[u] * (g[v] + h[v]) + h[u] * (f[v] + g[v])) % mod;
    h[u] = h[u] * (g[v] + h[v]) % mod;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2, x; i <= n; i++) scanf("%d", &x), add(x, i);
  dfs(1);
  printf("%lld", (g[1] + h[1]) % mod);
}
