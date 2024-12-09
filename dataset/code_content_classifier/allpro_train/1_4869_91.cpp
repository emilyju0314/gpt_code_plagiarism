#include <bits/stdc++.h>
using namespace std;
const int N = 2000009, M = 1000000007;
int n, x, pos, fac[N], inv_fac[N];
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % M;
    b >>= 1, a = 1ll * a * a % M;
  }
  return res;
}
void init() {
  scanf("%d %d %d", &n, &x, &pos);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % M;
  inv_fac[n] = ksm(fac[n], M - 2);
  for (int i = n - 1; i >= 0; i--)
    inv_fac[i] = 1ll * inv_fac[i + 1] * (i + 1) % M;
}
int binom(int n, int m) {
  if (n < m) return 0;
  return 1ll * fac[n] * inv_fac[n - m] % M;
}
void work() {
  int l = 0, r = n, mid, A = 0, B = 0;
  while (l < r) {
    mid = l + r >> 1;
    if (mid <= pos)
      l = mid + 1;
    else
      A++, r = mid;
    if (mid < pos) B++;
  }
  printf("%lld\n",
         1ll * binom(n - x, A) * binom(x - 1, B) % M * fac[n - A - B - 1] % M);
}
int main() {
  init(), work();
  return 0;
}
