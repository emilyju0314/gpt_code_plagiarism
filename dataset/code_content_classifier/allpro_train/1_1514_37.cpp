#include <bits/stdc++.h>
using namespace std;
void Freopen() {
  freopen(
      "title"
      ".in",
      "r", stdin);
  freopen(
      "title"
      ".out",
      "w", stdout);
}
int read() {
  int g = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    g = g * 10 + ch - '0';
    ch = getchar();
  }
  return g * f;
}
const int N = 505;
int n, m, k, st[N], top, tag[N], v[N][N], d[N];
long double a[N][N << 1];
struct matrix {
  long double mat[N][N];
  long double *operator[](const int a) { return mat[a]; }
  matrix() { memset(mat, 0, sizeof(mat)); }
  matrix operator*(const matrix &oth) {
    matrix re;
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (n); j++)
        for (int k = (1); k <= (n); k++)
          re.mat[i][j] += mat[i][k] * oth.mat[k][j];
    return re;
  }
  matrix operator+(const matrix &oth) {
    matrix re;
    for (int i = (0); i <= (top); i++)
      for (int j = (0); j <= (top); j++)
        for (int k = (0); k <= (top); k++)
          re.mat[i][j] += mat[i][k] * oth.mat[k][j];
    return re;
  }
} I, U, A;
matrix inv(matrix &b) {
  matrix c;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++) a[i][j] = b[i][j], a[i][j + n] = 0;
    a[i][i + n] = 1;
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (i); j <= (n); j++)
      if (a[j][i]) {
        if (j ^ i)
          for (int k = (1); k <= (n << 1); k++) swap(a[j][k], a[i][k]);
        break;
      }
    long double re = 1. / a[i][i];
    for (int j = (1); j <= (n << 1); j++) a[i][j] = a[i][j] * re;
    for (int j = (1); j <= (n); j++)
      if (i ^ j) {
        re = a[j][i];
        for (int k = (i); k <= (n << 1); k++) a[j][k] -= re * a[i][k];
      }
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) c[i][j] = a[i][j + n];
  return c;
}
signed main() {
  n = read(), m = read(), k = read();
  for (int i = (1); i <= (n); i++) {
    tag[i] = read();
    if (tag[i]) st[++top] = i;
  }
  for (int i = (1); i <= (m); i++) {
    int x = read(), y = read();
    v[x][y]++;
    v[y][x]++;
    d[x]++;
    d[y]++;
  }
  for (int i = (1); i <= (n); i++) I[i][i] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (tag[j]) U[i][j] = 1. * v[i][j] / d[i];
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (!tag[j]) I[i][j] -= 1. * v[i][j] / d[i];
  I = inv(I);
  U = I * U;
  for (int i = (1); i <= (top); i++) A[0][i] = U[1][st[i]];
  for (int i = (1); i <= (top); i++)
    for (int j = (1); j <= (top); j++) I[i][j] = U[st[i]][st[j]];
  k -= 2;
  while (k) {
    if (k & 1) A = A + I;
    I = I + I;
    k >>= 1;
  }
  return cout << fixed << setprecision(8) << A[0][top], signed();
}
