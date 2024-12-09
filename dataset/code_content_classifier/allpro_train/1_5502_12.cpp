#include <bits/stdc++.h>
using namespace std;
int a[10010], mat[110][110];
int main() {
  int N, M, Q, i, j, r, c, x, id, rr, cc;
  scanf("%d %d %d", &N, &M, &Q);
  for (i = 0; i < N * M; i++) {
    a[i] = i;
  }
  for (i = 0; i < Q; i++) {
    scanf("%d", &id);
    if (id == 1) {
      scanf("%d", &r);
      r--;
      r *= M;
      int fi = a[r];
      for (j = 0; j < M - 1; j++) {
        a[r + j] = a[r + j + 1];
      }
      a[r + j] = fi;
    }
    if (id == 2) {
      scanf("%d", &c);
      c--;
      int fi = a[c];
      for (j = 0; j < N - 1; j++) {
        a[M * j + c] = a[M * (j + 1) + c];
      }
      a[M * j + c] = fi;
    }
    if (id == 3) {
      scanf("%d %d %d", &r, &c, &x);
      r--;
      c--;
      rr = a[r * M + c] / M;
      cc = a[r * M + c] % M;
      mat[rr][cc] = x;
    }
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      if (j)
        printf(" %d", mat[i][j]);
      else
        printf("%d", mat[i][j]);
    }
    puts("");
  }
  return 0;
}
