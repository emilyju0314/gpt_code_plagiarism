#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int a[N], b[N];
long long mat[N][N];
const long long INF = 4e9;
void makeINF(long long C[N][N]) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) C[i][j] = INF;
}
long long C[N][N];
void mul(long long A[N][N], long long B[N][N]) {
  makeINF(C);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) A[i][j] = C[i][j];
}
long long get(int m) {
  long long I[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) I[i][j] = (i == j) ? 0 : INF;
  for (; m; m >>= 1) {
    if (m & 1) {
      mul(I, mat);
    }
    mul(mat, mat);
  }
  return I[0][0];
}
long long dp[N][N][N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  makeINF(mat);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) dp[i][j][k] = INF;
  for (int curr = 0; curr < N; curr++) {
    dp[curr][curr][0] = 0;
  }
  for (int len = 1; len <= n; len++) {
    for (int curr = 0; curr < N; curr++) {
      for (int lst = 0; lst < N; lst++) {
        if (curr + 1 < N)
          dp[curr][lst][len] =
              min(dp[curr][lst][len], dp[curr + 1][lst][len - 1] + a[n - len]);
        if (curr - 1 >= 0)
          dp[curr][lst][len] =
              min(dp[curr][lst][len], dp[curr - 1][lst][len - 1] + b[n - len]);
      }
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) mat[i][j] = dp[i][j][n];
  cout << get(m);
}
