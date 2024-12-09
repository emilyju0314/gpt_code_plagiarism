#include <bits/stdc++.h>
using namespace std;
long long Ans, F[20][10][10], G[20][10][10];
struct Num {
  long long x;
  int A[20];
  void Tran1(int t = 0) {
    if (t) {
      for (long long t = x; t; t /= 10) A[++*A] = t % 10;
    } else {
      int tot = *A;
      *A = 0;
      for (long long t = x; t; t /= 10) A[++*A] = t % 10;
      for (int i = (*A) + 1; i <= tot; i++) A[i] = 0;
      *A = tot;
    }
  }
  void Tran2() {
    x = 0;
    for (int i = *A; i >= 1; i--) (x *= 10) += A[i];
  }
  int Max(int d) {
    int ret = 0;
    for (int i = d; i <= *A; i++) ret = max(ret, A[i]);
    return ret;
  }
} N;
int main() {
  scanf("%I64d", &N.x);
  N.Tran1(1);
  for (int i = 0; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
      if (i || j) {
        if (i <= j)
          F[1][i][j] = 1, G[1][i][j] = 0;
        else
          F[1][i][j] = 0, G[1][i][j] = j;
      }
  for (int d = 2; d <= 19; d++)
    for (int i = 0; i <= 9; i++)
      for (int j = 0; j <= 9; j++) {
        int x = 9, y = j;
        long long ret = 0;
        for (;;) {
          ret += F[d - 1][max(i, x)][y];
          y = G[d - 1][max(i, x)][y];
          if (max(i, max(x, y)) == y && y) y = 0, ret++;
          if (!x) break;
          y = y + 10 - max(i, max(x, y));
          x--;
          ret++;
        }
        F[d][i][j] = ret;
        G[d][i][j] = y;
      }
  if (N.Max(1) == N.A[1] && N.A[1]) N.x -= N.A[1], N.A[1] = 0, Ans++;
  for (int i = 2; i <= N.A[0]; i++) {
    if (N.A[i]) {
      int t = N.Max(1);
      N.x -= t;
      N.Tran1();
      Ans++;
    } else
      continue;
    for (;;) {
      Ans += F[i - 1][N.Max(i)][N.A[1]];
      N.A[1] = G[i - 1][N.Max(i)][N.A[1]];
      for (int k = 2; k <= i - 1; k++) N.A[k] = 0;
      N.Tran2();
      if (N.Max(1) == N.A[1] && N.A[1]) N.x -= N.A[1], N.A[1] = 0, Ans++;
      if (!N.A[i]) break;
      N.x -= N.Max(1);
      N.Tran1();
      Ans++;
    }
  }
  if (N.A[1]) Ans++;
  printf("%I64d\n", Ans);
}
