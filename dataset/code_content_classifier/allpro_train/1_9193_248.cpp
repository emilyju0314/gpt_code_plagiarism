#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infLL = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 200000 + 5;
int psz;
struct Edge {
  int v, w;
  Edge *next;
} pool[maxn * 2], *head[maxn];
int n, k;
int sz[maxn];
long long f[maxn][2], B;
long long g[2];
void add_edge(int u, int v, int w) {
  Edge *i = pool + psz++;
  i->v = v, i->w = w, i->next = head[u], head[u] = i;
}
void dfs(int u, int p) {
  sz[u] = 1;
  f[u][0] = infLL, f[u][1] = 0;
  for (Edge *i = head[u]; i; i = i->next) {
    int v = i->v, w = i->w;
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    g[0] = min(f[u][0] + f[v][0], f[u][1] + f[v][1] + w);
    g[1] = min(f[u][1] + f[v][0], f[u][0] + f[v][1] + w);
    f[u][0] = g[0], f[u][1] = g[1];
    B += (long long)w * min(sz[v], n - sz[v]);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &k);
    n = 2 * k, psz = 0;
    memset(head, 0, sizeof(Edge *) * n);
    for (int i = 0; i < (n - 1); ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      --u, --v;
      add_edge(u, v, w);
      add_edge(v, u, w);
    }
    B = 0;
    dfs(0, 0);
    printf("%lld %lld\n", f[0][0], B);
  }
  return 0;
}
