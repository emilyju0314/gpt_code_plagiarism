#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 30;
struct node {
  int u, v, next;
  long long w, p, c;
} edge[maxn << 1];
int Next[maxn], cnt = 0;
long long sum[maxn] = {0};
void link(int u, int v, long long w, long long p) {
  edge[cnt] = {u, v, Next[u], w, p, 0};
  Next[u] = cnt++;
}
void dfs(int u) {
  for (int i = Next[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    dfs(v);
    sum[u] += sum[v];
    long long tmp = min({edge[i].w - 1, edge[i].p, edge[i].p - sum[v]});
    if (tmp < 0) {
      puts("-1");
      exit(0);
    }
    edge[i].w -= tmp;
    edge[i].p -= tmp;
    edge[i].c = tmp;
    sum[u] += edge[i].w;
  }
}
long long dfs2(int u, long long x) {
  long long use = 0;
  for (int i = Next[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    long long tmp = min(edge[i].c, x);
    edge[i].w += tmp;
    edge[i].p += tmp;
    x -= tmp;
    use += tmp;
    long long val = dfs2(v, min(x, edge[i].p - sum[v]));
    x -= val;
    use += val;
  }
  return use;
}
int main() {
  int n, a, b;
  long long c, d;
  scanf("%d", &n);
  memset(Next, -1, sizeof(Next));
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%lld%lld", &a, &b, &c, &d);
    link(a, b, c, d);
  }
  dfs(1);
  dfs2(1, 1LL << 60);
  printf("%d\n", n);
  for (int i = 0; i < cnt; ++i)
    printf("%d %d %lld %lld\n", edge[i].u, edge[i].v, edge[i].w, edge[i].p);
  return 0;
};
