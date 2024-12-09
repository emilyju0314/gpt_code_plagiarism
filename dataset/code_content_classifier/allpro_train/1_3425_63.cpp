#include <bits/stdc++.h>
using namespace std;
const int N = 128;
int n, x;
double P[N];
double A[N][N];
double B[N][N];
double C[N][N];
void mul(double a[][N], double b[][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double temp = 0;
      for (int k = 0; k < N; k++) temp += a[i][k] * b[k][j];
      C[i][j] = temp;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) a[i][j] = C[i][j];
}
void power(int n) {
  while (n) {
    if (n & 1) mul(B, A);
    mul(A, A);
    n >>= 1;
  }
}
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i <= x; i++) {
    scanf("%lf", P + i);
  }
  for (int i = 0; i < N; i++) {
    B[i][i] = 1;
    for (int j = 0; j < N; j++) A[i][j] = P[i ^ j];
  }
  power(n);
  printf("%.8lf\n", 1 - B[0][0]);
  return 0;
}
