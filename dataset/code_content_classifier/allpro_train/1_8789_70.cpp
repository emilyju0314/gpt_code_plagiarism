#include <bits/stdc++.h>
template <typename T>
inline bool MIN(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool MAX(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
using namespace std;
int n;
double p;
double A[55][55], B[55][55], f[1010][55];
int main() {
  scanf("%d%lf", &n, &p);
  p /= 1e9;
  for (int i = 1; i <= 50; ++i) {
    A[i][1] = p, A[i][2] = 1 - p;
    B[i][2] = 1 - p;
    for (int j = 2; j <= 50; ++j) {
      A[i][j] += A[i][j - 1] * A[i - 1][j - 1];
      if (j > 2) B[i][j] = B[i][j - 1] * A[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= 50; ++j) {
      double all = 0;
      if (j == 1) {
        for (int k = 2; k <= 50; ++k) {
          double t =
              i == 1 ? 0 : B[min(i - 1, 50)][k] * (1 - A[min(i - 2, 50)][k]);
          all += t;
          f[i][j] += f[i - 1][k] * t;
        }
      } else {
        for (int k = 1; k < j; ++k) {
          double t =
              i == 1 ? 0 : A[min(i - 1, 50)][k] * (1 - A[min(i - 2, 50)][k]);
          all += t;
          f[i][j] += f[i - 1][k] * t;
        }
      }
      if (all) f[i][j] /= all;
      f[i][j] += j;
    }
  }
  double ans = 0;
  for (int i = 1; i <= 50; ++i) {
    ans += A[min(n, 50)][i] * (1 - A[min(n - 1, 50)][i]) *
           (f[min(n, 1000)][i] +
            (n > 1000 ? (n - 1000) * (f[1000][i] - f[999][i]) : 0));
  }
  printf("%.12lf\n", ans);
  return 0;
}
