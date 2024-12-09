#include <bits/stdc++.h>
int wu[19 + 1], wv[19 + 1];
long long power(int a, int k) {
  long long b = a, p = 1;
  while (k) {
    if (k & 1) p = p * b % 469762049;
    b = b * b % 469762049;
    k >>= 1;
  }
  return p;
}
void init() {
  int l, u, v;
  v = power(u = power(3, 469762049 - 1 >> 19), 469762049 - 2);
  wu[19] = u, wv[19] = v;
  for (l = 19 - 1; l >= 0; l--) {
    u = (long long)u * u % 469762049, v = (long long)v * v % 469762049;
    wu[l] = u, wv[l] = v;
  }
}
void ntt(int *aa, int n_, int inverse) {
  int i, j, b, l, r;
  for (i = 0, j = 1; j < n_; j++) {
    int tmp;
    b = n_ >> 1;
    while ((i ^= b) < b) b >>= 1;
    if (i < j) tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
  }
  for (l = 1; 1 << l <= n_; l++) {
    int n = 1 << l, m = n >> 1;
    long long u = inverse ? wv[l] : wu[l], w = 1;
    for (r = 0; r < m; r++) {
      for (i = r; (j = i + m) < n_; i += n) {
        int a = aa[i], b = aa[j] * w % 469762049;
        if ((aa[i] = a + b) >= 469762049) aa[i] -= 469762049;
        if ((aa[j] = a - b) < 0) aa[j] += 469762049;
      }
      w = w * u % 469762049;
    }
  }
}
int main() {
  static int aa[(1 << 19)], bb[(1 << 19)], cc[500000 + 1];
  int k, n, n_, y, q, i, j;
  init();
  scanf("%d%d%d", &k, &n, &y), n++, k++;
  while (k--) {
    scanf("%d", &i);
    aa[i] = bb[n - 1 - i] = 1;
  }
  n_ = 1;
  while (n_ < n * 2 - 1) n_ <<= 1;
  ntt(aa, n_, 0);
  ntt(bb, n_, 0);
  for (i = 0; i < n_; i++) aa[i] = (long long)aa[i] * bb[i] % 469762049;
  ntt(aa, n_, 1);
  for (i = 1; i < n; i++)
    if (aa[n - 1 + i] > 0)
      for (j = i + y; j <= 500000; j += i + y) cc[j] = i + y;
  scanf("%d", &q);
  while (q--) {
    int l;
    scanf("%d", &l), l /= 2;
    printf("%d ", l < 0 || cc[l] == 0 ? -1 : cc[l] * 2);
  }
  printf("\n");
  return 0;
}
