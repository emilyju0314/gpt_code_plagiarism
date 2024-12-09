#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, w, pos;
} a[1250000];
int ans[150000];
int n, m;
int cmp(node a, node b) { return a.w < b.w; }
struct node2 {
  int origem, destino, w, proximo;
} e[1500000];
int cont;
int cabecalho[150000];
int vis[150000];
int dfn[150000];
int bxo[150000];
int fa[150000];
int cnt;
void add(int origem, int destino, int w) {
  e[cont].destino = destino;
  e[cont].w = w;
  e[cont].proximo = cabecalho[origem];
  cabecalho[origem] = cont++;
}
void Dfs(int u, int origem) {
  bxo[u] = dfn[u] = cnt++, vis[u] = 1;
  for (int i = cabecalho[u]; i != -1; i = e[i].proximo) {
    int v = e[i].destino;
    if (vis[v] == 1 && e[i].w != origem)
      bxo[u] = min(bxo[u], dfn[v]);
    else if (!vis[v]) {
      Dfs(v, e[i].w);
      bxo[u] = min(bxo[u], bxo[v]);
      if (bxo[v] > dfn[u]) ans[e[i].w] = 1;
    }
  }
}
int f[1250000];
int find(int a) {
  int r = a;
  while (f[r] != r) r = f[r];
  int i = a;
  int j;
  while (i != r) {
    j = f[i];
    f[i] = r;
    i = j;
  }
  return r;
}
void merge(int a, int b) {
  int A, B;
  A = find(a);
  B = find(b);
  if (A != B) {
    cabecalho[a] = cabecalho[b] = cabecalho[A] = cabecalho[B] = -1;
    vis[a] = vis[b] = vis[A] = vis[B] = 0;
    dfn[a] = dfn[b] = dfn[A] = dfn[B] = 0;
    bxo[a] = bxo[b] = bxo[A] = bxo[B] = 0;
    f[B] = A;
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    cont = 0;
    cnt = 1;
    memset(dfn, 0, sizeof(dfn));
    memset(bxo, 0, sizeof(bxo));
    memset(vis, 0, sizeof(vis));
    memset(cabecalho, -1, sizeof(cabecalho));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++)
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w), a[i].pos = i;
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
      int ss = i;
      int ee = i;
      while (ee + 1 <= m && a[ee].w == a[ee + 1].w) ee++;
      for (int j = ss; j <= ee; j++) {
        int fx = find(a[j].x);
        int fy = find(a[j].y);
        if (fx != fy) {
          ans[a[j].pos] = 2;
          add(fx, fy, a[j].pos);
          add(fy, fx, a[j].pos);
        }
      }
      for (int j = ss; j <= ee; j++) {
        int fx = find(a[j].x);
        int fy = find(a[j].y);
        if (fx != fy && vis[fx] == 0) Dfs(fx, -1);
        if (fx != fy && vis[fy] == 0) Dfs(fy, -1);
      }
      for (int j = ss; j <= ee; j++) {
        merge(a[i = j].x, a[j].y);
      }
      i = ee;
    }
    for (int i = 1; i <= m; i++) {
      if (ans[i] == 0) printf("none\n");
      if (ans[i] == 1) printf("any\n");
      if (ans[i] == 2) printf("at least one\n");
    }
  }
}
