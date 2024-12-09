#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAXE = 300005 << 1;
struct Edge {
  int v, next;
} E[MAXE];
int head[MAXN], tot;
void add(int u, int v) {
  E[tot].v = v;
  E[tot].next = head[u];
  head[u] = tot++;
  E[tot].v = u;
  E[tot].next = head[v];
  head[v] = tot++;
}
int S[MAXE], vis[MAXE], top;
void dfs(int u) {
  for (int p = head[u]; ~p; p = head[u]) {
    head[u] = E[p].next;
    if (vis[p]) continue;
    vis[p] = vis[p ^ 1] = true;
    dfs(E[p].v);
    S[top++] = p;
  }
}
void init() {
  memset(head, -1, sizeof(head));
  memset(vis, 0, sizeof(vis));
  tot = top = 0;
}
int ind[MAXN];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  init();
  for (int i = 0, u, v; i < M; ++i) {
    scanf("%d%d", &u, &v);
    ++ind[u];
    ++ind[v];
    add(u, v);
  }
  for (int i = 1, j = 0; i <= N; ++i)
    if (ind[i] & 1) {
      if (j) {
        add(j, i);
        ++M;
        j = 0;
      } else
        j = i;
    }
  if (M & 1) {
    add(1, 1);
    ++M;
  }
  dfs(1);
  printf("%d\n", top);
  while (~--top)
    printf("%d %d\n", E[S[top] ^ (top & 1)].v, E[S[top] ^ (~top & 1)].v);
  return 0;
}
