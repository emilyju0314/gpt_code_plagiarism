#include <bits/stdc++.h>
using namespace std;
double f[205][205][105];
double X[205][205][105];
double s[205][205][105];
double t[205][205][105];
struct tp {
  int hp, dt, l, r, span;
  double p;
} A, B;
int h, n = 0, L, R;
int a[1005];
double XX, XXX;
int main() {
  scanf("%d%d%d%d%d", &A.hp, &A.dt, &A.l, &A.r, &h);
  B.p = h / 100.0;
  if (h == 100) {
    printf("0\n");
    exit(0);
  }
  scanf("%d%d%d%d%d", &B.hp, &B.dt, &B.l, &B.r, &h);
  A.p = h / 100.0;
  if (h == 100) {
    printf("1\n");
    exit(0);
  }
  A.span = A.r - A.l + 1;
  B.span = B.r - B.l + 1;
  for (int i = 1; i <= A.dt * B.dt; ++i) {
    if (i % A.dt == 0 || i % B.dt == 0) a[++n] = i;
    if (i % A.dt == 0 && i % B.dt == 0) break;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= A.hp; ++j) {
      f[j][0][i] = 1;
      if (j > 1)
        t[j][0][i] = t[j - 1][0][i] + f[j][0][i];
      else
        t[j][0][i] = f[j][0][i];
      s[j][0][i] = f[j][0][i];
    }
    for (int j = 1; j <= B.hp; ++j) {
      f[0][j][i] = 0;
      s[0][j][i] = s[0][j - 1][i] + f[i][j][i];
      t[0][j][i] = f[0][j][i];
    }
  }
  for (int i = 1; i <= A.hp; ++i)
    for (int j = 1; j <= B.hp; ++j) {
      for (int k = 1; k < n; ++k) {
        if (a[k] % A.dt == 0) {
          L = j - A.l;
          R = j - A.r;
          if (L <= 0)
            X[i][j][k] = f[i][0][k + 1];
          else if (R > 0)
            X[i][j][k] = (s[i][L][k + 1] - s[i][R - 1][k + 1]) / A.span;
          else
            X[i][j][k] = (s[i][L][k + 1] - R * f[i][0][k + 1]) / A.span;
          X[i][j][k] *= 1 - B.p;
        } else {
          L = i - B.l;
          R = i - B.r;
          if (L <= 0)
            X[i][j][k] = f[0][j][k + 1];
          else if (R > 0)
            X[i][j][k] = (t[L][j][k + 1] - t[R - 1][j][k + 1]) / B.span;
          else
            X[i][j][k] = (t[L][j][k + 1] - R * f[0][j][k + 1]) / B.span;
          X[i][j][k] *= 1 - A.p;
        }
      }
      for (int k = A.l; k <= A.r; ++k) {
        if (k >= j)
          X[i][j][n] += f[i][0][1] * (1 - B.p) * A.p / A.span;
        else
          X[i][j][n] += f[i][j - k][1] * (1 - B.p) * A.p / A.span;
      }
      for (int k = B.l; k <= B.r; ++k) {
        if (k >= i)
          X[i][j][n] += f[0][j][1] * (1 - A.p) * B.p / B.span;
        else
          X[i][j][n] += f[i - k][j][1] * (1 - A.p) * B.p / B.span;
      }
      for (int k = A.l; k <= A.r; ++k) {
        if (k >= j)
          X[i][j][n] += (1 - A.p) * (1 - B.p) / A.span;
        else {
          L = i - B.l;
          R = i - B.r;
          if (L > 0) {
            if (R > 0)
              X[i][j][n] += (1 - A.p) * (1 - B.p) *
                            (t[L][j - k][1] - t[R - 1][j - k][1]) / A.span /
                            B.span;
            else
              X[i][j][n] +=
                  (1 - A.p) * (1 - B.p) * (t[L][j - k][1]) / A.span / B.span;
          }
        }
      }
      XX = X[i][j][n], XXX = A.p * B.p;
      for (int k = n - 1; k >= 1; --k) {
        if (a[k] % A.dt == 0)
          XX *= B.p, XXX *= B.p;
        else
          XX *= A.p, XXX *= A.p;
        XX += X[i][j][k];
      }
      f[i][j][1] = XX / (1 - XXX);
      XX = f[i][j][1];
      for (int k = n; k > 1; --k) {
        XXX = 1;
        if (a[k] % A.dt == 0) XXX *= B.p;
        if (a[k] % B.dt == 0) XXX *= A.p;
        f[i][j][k] = XXX * XX + X[i][j][k];
        XX = f[i][j][k];
      }
      for (int k = 1; k <= n; ++k) {
        s[i][j][k] = s[i][j - 1][k] + f[i][j][k];
        t[i][j][k] = t[i - 1][j][k] + f[i][j][k];
      }
    }
  printf("%.9lf\n", f[A.hp][B.hp][n]);
  return 0;
}
