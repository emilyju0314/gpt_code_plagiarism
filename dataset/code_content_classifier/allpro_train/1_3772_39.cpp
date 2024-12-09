#include <bits/stdc++.h>
int mypow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % 998244353;
    y >>= 1;
    x = 1ll * x * x % 998244353;
  }
  return res;
}
void FWT_xor(int* o, int n, bool op) {
  int inv2 = mypow(2, 998244353 - 2);
  for (int i = 2, x, y; i <= n; i <<= 1)
    for (int p = i >> 1, j = 0; j < n; j += i)
      for (int k = j; k < j + p; ++k) {
        x = o[k], y = o[k + p];
        o[k] = x + y;
        if (o[k] >= 998244353) o[k] -= 998244353;
        o[k + p] = x - y;
        if (o[k + p] < 0) o[k + p] += 998244353;
        if (!op)
          o[k] = 1ll * o[k] * inv2 % 998244353,
          o[k + p] = 1ll * o[k + p] * inv2 % 998244353;
      }
}
char o[22][100010];
int n, m, N;
int one[1 << 20], num[1 << 20], ans[1 << 20];
int main() {
  scanf("%d%d", &n, &m);
  N = 1 << n;
  for (int i = 1; i < N; ++i) one[i] = one[i ^ i & -i] + 1;
  for (int i = 1; i < N; ++i) one[i] = std::min(one[i], n - one[i]);
  for (int i = 0; i < n; ++i) scanf("%s", o[i]);
  for (int i = 0, tmp; i < m; ++i) {
    tmp = 0;
    for (int j = 0; j < n; ++j) tmp = (tmp << 1 | o[j][i] ^ '0');
    ++num[tmp];
  }
  FWT_xor(one, N, 1);
  FWT_xor(num, N, 1);
  for (int i = 0; i < N; ++i) ans[i] = 1ll * one[i] * num[i] % 998244353;
  FWT_xor(ans, N, 0);
  for (int i = 1; i < N; ++i) ans[0] = std::min(ans[0], ans[i]);
  printf("%d\n", ans[0]);
}
