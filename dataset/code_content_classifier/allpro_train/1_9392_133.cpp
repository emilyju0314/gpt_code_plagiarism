#include <bits/stdc++.h>
using namespace std;
int ne[220000], v[220000], e[220000];
int ne2[220000], v2[220000], e2[220000];
int nn;
int nn2;
void add(int x, int y) { ne[++nn] = e[x], e[x] = nn, v[nn] = y; }
void add2(int x, int y) { ne2[++nn2] = e2[x], e2[x] = nn2, v2[nn2] = y; }
int num1[220000], num2[220000];
int fa[220000];
int r[220000];
int n;
void dfs2(int x) {
  for (int i = e[x]; i; i = ne[i])
    if (v[i] != fa[x]) {
      fa[v[i]] = x;
      dfs2(v[i]);
    }
}
int rt[220000];
void dfs1(int x) {
  if (x == 1 || fa[x] == 1) rt[x] = 1;
  for (int i = e[x]; i; i = ne[i])
    if (fa[x] != v[i]) {
      int y = v[i];
      for (int j = e[y]; j; j = ne[j])
        if (fa[y] != v[j]) add2(x, v[j]);
      dfs1(y);
    }
}
int op;
int yy[220000];
void dfs3(int x, int z) {
  if (z != r[x]) {
    z ^= 1;
    op++;
    yy[x] = 1;
  }
  for (int i = e2[x]; i; i = ne2[i]) {
    dfs3(v2[i], z);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    add(b, a);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &num1[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &num2[i]), r[i] = num1[i] ^ num2[i];
  dfs2(1);
  dfs1(1);
  for (int i = 1; i <= n; i++)
    if (rt[i]) {
      dfs3(i, 0);
    }
  printf("%d\n", op);
  for (int i = 1; i <= n; i++)
    if (yy[i]) printf("%d\n", i);
}
