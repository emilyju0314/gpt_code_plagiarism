#include <bits/stdc++.h>
using namespace std;
int n, q, par[100005][18], type[100005], iss[100005][18], isp[100005][18],
    dep[100005];
int trace(int x) {
  if (!x) return 0;
  if (dep[x]) return dep[x];
  return dep[x] = trace(par[x][0]) + 1;
}
int up(int x, int y) {
  for (int i = (0); i < (18); i++)
    if (y & 1 << i) x = par[x][i];
  return x;
}
int lca(int x, int y) {
  int dx = dep[x], dy = dep[y];
  if (dx > dy) {
    swap(x, y);
    swap(dx, dy);
  }
  y = up(y, dy - dx);
  for (int i = (18 - 1); i >= (0); i--) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  if (x != y) {
    x = par[x][0];
  }
  return x;
}
int iss_up(int x, int y) {
  bool ret = 1;
  for (int i = (0); i < (18); i++)
    if (y & 1 << i) {
      ret &= iss[x][i];
      x = par[x][i];
    }
  return ret;
}
int isp_up(int x, int y) {
  bool ret = 1;
  for (int i = (0); i < (18); i++)
    if (y & 1 << i) {
      ret &= isp[x][i];
      x = par[x][i];
    }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%d %d", &par[i][0], &type[i]);
    if (par[i][0] < 0) par[i][0] = 0;
    if (type[i] == 0) iss[i][0] = 1;
    if (type[i] == 1) isp[i][0] = 1;
  }
  for (int i = (1); i <= (n); i++)
    if (!dep[i]) trace(i);
  for (int j = (1); j < (18); j++) {
    for (int i = (1); i <= (n); i++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
      iss[i][j] = iss[i][j - 1] && iss[par[i][j - 1]][j - 1];
      isp[i][j] = isp[i][j - 1] && isp[par[i][j - 1]][j - 1];
    }
  }
  scanf("%d", &q);
  while (q--) {
    int t, x, y, dx, dy;
    scanf("%d %d %d", &t, &x, &y);
    dx = dep[x];
    dy = dep[y];
    if (t == 1) {
      if (x == y || dx >= dy || !iss_up(y, dy - dx) || up(y, dy - dx) != x) {
        puts("NO");
      } else {
        puts("YES");
      }
    } else {
      int z = lca(x, y);
      int dz = dep[z];
      if (z != 0 && z != y && iss_up(x, dx - dz) && isp_up(y, dy - dz)) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
}
