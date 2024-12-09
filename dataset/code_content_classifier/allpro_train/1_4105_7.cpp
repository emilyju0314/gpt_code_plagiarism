#include <bits/stdc++.h>
using namespace std;
int parent[1111111][22];
int depp[1111111];
int n, fu, fv, value, x, query;
int jump(int u, int k) {
  for (int i = 20; i >= 0; i--)
    if ((1 << i) <= k) {
      k -= (1 << i);
      u = parent[u][i];
    }
  return u;
}
int lca(int u, int v) {
  if (depp[u] > depp[v]) u = jump(u, depp[u] - depp[v]);
  if (depp[v] > depp[u]) v = jump(v, depp[v] - depp[u]);
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  return parent[u][0];
}
int dis(int u, int v) { return depp[u] + depp[v] - depp[lca(u, v)] * 2; }
void build(int u) {
  n++;
  parent[n][0] = u;
  depp[n] = depp[u] + 1;
  for (int i = 1; i <= 20; i++)
    if (parent[parent[n][i - 1]][i - 1])
      parent[n][i] = parent[parent[n][i - 1]][i - 1];
    else
      break;
  if (dis(n, fu) > value) value = dis(n, fu), fv = n;
  if (dis(n, fv) > value) value = dis(n, fv), fu = n;
}
int main() {
  memset(parent, 0, sizeof(parent));
  for (int i = 2; i <= 4; i++) parent[i][0] = 1, depp[i] = 1;
  depp[1] = 0;
  cin >> query;
  value = 2;
  fu = 2;
  fv = 3;
  n = 4;
  for (int i = 1; i <= query; i++) {
    scanf("%d", &x);
    build(x);
    build(x);
    printf("%d\n", value);
  }
  return 0;
}
