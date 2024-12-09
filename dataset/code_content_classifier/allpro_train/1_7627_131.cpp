#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, h, i, j, k;
double f[505][505], g[25][505], p[505][505];
vector<int> GG[25];
int q, z;
double an[505];
int num(int x, int y) { return (x - 1) * (a) + y; }
void Gau() {
  int ii, jj, kk;
  double u;
  for (ii = 1; ii <= e; ii++) {
    if (fabs(f[ii][ii]) < 1e-7) {
      for (jj = ii + 1; jj <= e; jj++)
        if (fabs(f[jj][ii]) > 1e-6) {
          for (kk = 1; kk <= e; kk++) swap(f[ii][kk], f[jj][kk]);
          for (kk = 1; kk <= a; kk++) swap(g[kk][jj], g[kk][ii]);
        }
    }
    if (fabs(f[ii][ii]) > 1e-7) {
      for (jj = ii + 1; jj <= e; jj++)
        if (fabs(f[jj][ii]) >= 1e-7) {
          u = f[ii][ii] / f[jj][ii];
          for (kk = 1; kk <= e; kk++) f[jj][kk] *= u;
          for (kk = 1; kk <= e; kk++) f[jj][kk] -= f[ii][kk];
          for (kk = 1; kk <= a; kk++) g[kk][jj] *= u;
          for (kk = 1; kk <= a; kk++) g[kk][jj] -= g[kk][ii];
        }
    }
  }
}
void Get_An(int x) {
  int ii, jj, kk;
  double u;
  for (ii = e; ii >= 1; ii--) {
    u = g[x][ii] / f[ii][ii];
    for (jj = ii - 1; jj >= 1; jj--) g[x][jj] -= u * f[jj][ii];
    if (ii == num(q, z)) {
      printf("%.10lf ", u);
      break;
    }
  }
}
int main() {
  scanf("%d%d", &a, &b);
  scanf("%d%d", &q, &z);
  for (i = 1; i <= b; i++) {
    scanf("%d%d", &c, &d);
    GG[c].push_back(d);
    GG[d].push_back(c);
  }
  for (i = 1; i <= a; i++) scanf("%lf", &p[i][i]);
  for (i = 1; i <= a; i++) {
    k = GG[i].size();
    for (j = 0; j < GG[i].size(); j++)
      p[i][GG[i][j]] = (1 - p[i][i]) / (double)k;
  }
  for (i = 1; i <= a; i++) GG[i].push_back(i);
  for (i = 1; i <= a; i++) g[i][num(i, i)] = 1;
  for (i = 1; i <= a * a; i++) f[i][i] = 1;
  for (i = 1; i <= a; i++)
    for (j = 1; j <= a; j++)
      if (i != j) {
        for (k = 1; k <= a; k++)
          for (e = 1; e <= a; e++)
            f[num(i, j)][num(k, e)] += -(p[i][k] * p[j][e]);
      }
  e = a * a;
  Gau();
  for (i = 1; i <= a; i++) Get_An(i);
  printf("\n");
  return 0;
}
