#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 10 + 2, M_MAX = 100 + 10;
inline int GetOne(int x) {
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
  x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
  return x;
}
int now[N_MAX], pre[M_MAX], son[M_MAX], tot = 0;
inline void add(int a, int b) {
  pre[++tot] = now[a];
  now[a] = tot;
  son[tot] = b;
}
inline void con(int a, int b) {
  add(a, b);
  add(b, a);
}
int N, M, K, dp[1 << (N_MAX)][1 << (N_MAX)];
int main() {
  scanf("%d%d%d", &N, &M, &K);
  tot = 0;
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    int status = (1 << a) | (1 << b);
    con(a, b);
    dp[status][status] = 1;
  }
  for (int i = 0; i < (1 << N); ++i)
    for (int j = i; j > 0; j = (j - 1) & i)
      for (int x = dp[i][j] ? 0 : N; x < N; ++x)
        for (int p = ((1 << x) & i) ? now[x] : 0; p; p = pre[p]) {
          int s = son[p];
          if ((1 << s) & i) continue;
          int tmp = (1 << s) | (j & (~(1 << x)));
          if (tmp >> s + 1) continue;
          dp[i | (1 << s)][tmp] += dp[i][j];
        }
  int res = 0;
  for (int i = 0; i < (1 << N); ++i)
    if (GetOne(i) == K) res += dp[(1 << N) - 1][i];
  printf("%d\n", res);
  return 0;
}
