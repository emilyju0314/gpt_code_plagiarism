#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long comb[64][64];
long long Free(int k, int bs) {
  if (bs < 0 || bs > k) return 0;
  return comb[k][bs];
}
long long Solve(long long right, int bs) {
  if (right == 0) return 0;
  int pos;
  for (pos = 60; !(right & (1LL << pos)); pos--)
    ;
  long long res = Free(pos, bs);
  res += Solve(right - (1LL << pos), bs - 1);
  return res;
}
int main() {
  for (int i = 0; i < 64; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; j++)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }
  scanf("%I64d%I64d", &n, &t);
  if (t & (t - 1)) {
    printf("0\n");
    return 0;
  }
  int lt = 0;
  while (t > 1) t >>= 1, lt++;
  int bits = lt + 1;
  ((void)0);
  long long ans = Solve(n + 2, bits) - Solve(2, bits);
  printf("%I64d\n", ans);
  return 0;
}
