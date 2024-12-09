#include <bits/stdc++.h>
using namespace std;
const int maxN = 542;
const long long INF = 1000000000000000LL;
void remin(long long& a, long long b) { a = min(a, b); }
struct Hungarian {
  long long *C[maxN], pot[maxN * 2], mluz[maxN * 2];
  int *part, n, ctr, qtop, qback, vis[maxN * 2], vluz[maxN * 2], Q[maxN];
  inline void aug(int x, int y) {
    while (x != 0) part[y] = x, swap(part[x], y), x = vluz[x];
  }
  inline void ins(int v, int prev) {
    for (int j = n + 1; j < (n * 2 + 1); j++) {
      long long luz = (C[v][(j)-n] - pot[v] - pot[j]);
      if (mluz[j] > luz) mluz[j] = luz, vluz[j] = v;
    }
    vis[v] = vis[part[v]] = ctr;
    Q[qback++] = v;
    vluz[v] = prev;
  }
  long long f(int nn, long long C_in[maxN][maxN], int* part_out) {
    n = nn;
    part = part_out;
    for (int i = 0; i < (n * 2 + 1); i++) vis[i] = part[i] = pot[i] = 0;
    for (int i = 0; i < (n + 1); i++) C[i] = C_in[i];
    for (ctr = 1; ctr <= n; ctr++) {
      fill(mluz + n + 1, mluz + n * 2 + 1, INF);
      ins(ctr, qback = qtop = 0);
      while (true) {
        for (int x = Q[qtop]; qtop != qback; qtop++) {
          for (int j = n + 1; j < (n * 2 + 1); j++)
            if (vis[j] != ctr and (C[x][(j)-n] - pot[x] - pot[j]) == 0) {
              if (part[j] == 0) {
                aug(x, j);
                goto Break;
              }
              ins(part[j], x);
            }
        }
        long long mn = INF;
        for (int j = n + 1; j < (n * 2 + 1); j++)
          if (vis[j] != ctr) remin(mn, mluz[j]);
        for (int i = 1; i < (n + 1); i++)
          if (vis[i] == ctr) pot[i] += mn;
        for (int j = n + 1; j < (n * 2 + 1); j++)
          vis[j] == ctr ? pot[j] -= mn : mluz[j] -= mn;
        for (int j = n + 1; j < (n * 2 + 1); j++)
          if (vis[j] != ctr and mluz[j] == 0) {
            if (part[j] == 0) {
              aug(vluz[j], j);
              goto Break;
            }
            ins(part[j], vluz[j]);
          }
      }
    Break:;
    }
    long long cost = 0;
    for (int i = 1; i < (n + 1); i++) cost += C[i][part[i] - n];
    return cost;
  }
} alg;
long long C[maxN][maxN];
int sm[maxN * 2];
int main() {
  int n;
  scanf("%d", &n);
  long long res = 0;
  for (int i = 1; i < (n + 1); i++) {
    long long a;
    scanf("%lld", &a);
    long long b;
    scanf("%lld", &b);
    int k;
    scanf("%d", &k);
    for (int j = 1; j < (n + 1); j++) {
      C[i][j] = min(k, j - 1) * b;
      C[i][j] = min(C[i][j], a);
    }
    res += a;
  }
  res -= alg.f(n, C, sm);
  printf("%lld\n", res);
  return 0;
}
