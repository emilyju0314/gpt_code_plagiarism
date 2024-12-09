#include <bits/stdc++.h>
const int P = 998244353, g = 3;
inline int pow(int a, int n) {
  int c = 1;
  for (; n; n >>= 1, a = (long long)a * a % P)
    if (n & 1) c = (long long)c * a % P;
  return c;
}
const int inv_g = pow(g, P - 2);
int rev[2097152];
inline void init(int n) {
  for (int i = 1; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
}
inline void mod(int &x) {
  if (x >= P) x -= P;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline void fft(int n, int *A, int type) {
  for (int i = 0; i < n; i++)
    if (rev[i] < i) swap(A[rev[i]], A[i]);
  for (int l = 2; l <= n; l <<= 1) {
    int Wn = pow(type == 1 ? g : inv_g, (P - 1) / l), mid = l >> 1;
    for (int p = 0; p < n; p += l) {
      int W = 1;
      for (int i = 0; i < mid; i++, W = (long long)W * Wn % P) {
        int temp = (long long)W * A[p + mid + i] % P;
        mod(A[p + mid + i] = A[p + i] - temp + P);
        mod(A[p + i] = A[p + i] + temp);
      }
    }
  }
}
inline void dft(int n, int *A) { fft(n, A, 1); }
inline void idft(int n, int *A) {
  fft(n, A, -1);
  for (int i = 0, inv_n = pow(n, P - 2); i < n; i++)
    A[i] = (long long)A[i] * inv_n % P;
}
int n, m, a[1000002], A[2097152], T[1000002], k;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), A[a[i]] = T[a[i]] = 1;
  A[0] = 1;
  init(2097152);
  dft(2097152, A);
  for (int i = 0; i < 2097152; i++) A[i] = (long long)A[i] * A[i] % P;
  idft(2097152, A);
  for (int i = 1; i <= m; i++)
    if ((!!A[i]) != T[i]) {
      printf("NO");
      return 0;
    } else if (A[i] == 2)
      k++;
  printf("YES\n%d\n", k);
  for (int i = 1; i <= m; i++)
    if (A[i] == 2) printf("%d ", i);
  return 0;
}
