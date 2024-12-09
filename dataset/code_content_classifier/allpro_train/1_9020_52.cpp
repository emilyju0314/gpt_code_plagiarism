#include <bits/stdc++.h>
int n, F[1 << 20], bit[1 << 20];
long long a[22], sum[1 << 20];
int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    if (!a[i]) n--, i--;
  }
  for (int i = 1; i < 1 << n; ++i) {
    bit[i] = bit[i ^ i & -i] + 1;
    for (int j = 0; j < n; ++j)
      if (i >> j & 1) sum[i] += a[j];
    int hb = i;
    while (hb != (hb & -hb)) hb ^= hb & -hb;
    for (int s = i - 1 & i; s & hb; s = s - 1 & i)
      F[i] = max(F[i], F[s] + F[i ^ s]);
    for (int s = i - 1 & i; s & hb && !F[i]; s = s - 1 & i)
      F[i] = !(sum[i ^ s] - sum[s] - bit[i] - 1 & 1 ||
               sum[s] - sum[i ^ s] <= -bit[i] || sum[s] - sum[i ^ s] >= bit[i]);
  }
  printf("%d\n", n - F[(1 << n) - 1]);
}
