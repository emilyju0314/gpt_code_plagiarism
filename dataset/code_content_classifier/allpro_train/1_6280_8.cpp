#include <bits/stdc++.h>
using namespace std;
int n;
struct edge {
  int u, v, next;
} edges[210000 * 2];
int head[210000], nCount = 0;
void AddEdge(int U, int V) {
  edges[++nCount].u = U;
  edges[nCount].v = V;
  edges[nCount].next = head[U];
  head[U] = nCount;
}
double f[210000];
int size[210000];
void getsize(int u) {
  size[u] = 1;
  for (int p = head[u]; p != -1; p = edges[p].next) {
    int v = edges[p].v;
    getsize(v);
    size[u] += size[v];
  }
}
void DFS(int u) {
  int son = 0;
  for (int p = head[u]; p != -1; p = edges[p].next) son++;
  double tmp;
  if (son == 1) {
    for (int p = head[u]; p != -1; p = edges[p].next) {
      int v = edges[p].v;
      f[v] = f[u] + 1;
      DFS(v);
    }
    return;
  }
  tmp = (double)(son - 1) * (double)son / 2.0;
  for (int i = son - 1; i <= son; i++) tmp /= (double)i;
  for (int p = head[u]; p != -1; p = edges[p].next) {
    int v = edges[p].v;
    f[v] = f[u] + tmp * (double)(size[u] - size[v] - 1) + 1;
    DFS(v);
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int par;
    scanf("%d", &par);
    AddEdge(par, i);
  }
  getsize(1);
  f[1] = 1;
  DFS(1);
  for (int i = 1; i <= n; i++) printf("%.7lf ", f[i]);
  printf("\n");
  return 0;
}
