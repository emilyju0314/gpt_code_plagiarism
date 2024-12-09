#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
int n, m, K, w;
char A[1000 + 9][10 + 9][10 + 9];
int G[1000 + 9][1000 + 9];
int vis[1000 + 9];
int S[1000 + 9], M[1000 + 9];
int Z[1000 + 9], U[1000 + 9];
int main() {
  read_file();
  while (scanf("%d %d %d %d\n", &n, &m, &K, &w) != EOF) {
    for (int k = 0; k < K; k++) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%c\n", &A[k][i][j]);
    }
    for (int p = 0; p < K; p++) {
      G[p][p] = 0;
      for (int q = p + 1; q < K; q++) {
        int d = 0;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) d += A[p][i][j] != A[q][i][j];
        G[p][q] = G[q][p] = d * w;
      }
    }
    for (int i = 0; i < K; i++) {
      M[i] = n * m;
      U[i] = -1;
      S[i] = 0;
      for (int j = 0; j < K; j++) S[i] += G[i][j];
    }
    int ans = 0;
    memset(vis, 0, sizeof vis);
    for (int itr = 0; itr < K; itr++) {
      int cho = -1;
      for (int i = 0; i < K; i++) {
        if (vis[i]) continue;
        if (cho == -1 || M[cho] > M[i]) cho = i;
      }
      assert(cho != -1);
      ans += M[cho];
      vis[cho] = 1;
      Z[itr] = cho;
      for (int i = 0; i < K; i++) {
        if (vis[i]) continue;
        S[i] -= G[i][cho];
        if (M[i] > G[i][cho]) M[i] = G[i][cho], U[i] = cho;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < K; i++) printf("%d %d\n", Z[i] + 1, U[Z[i]] + 1);
    printf("\n");
  }
}
