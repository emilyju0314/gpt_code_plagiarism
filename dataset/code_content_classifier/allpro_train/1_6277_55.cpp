#include <bits/stdc++.h>
const int mod = 1000000007;
int mul(int a, int b) { return a * (long long)b % mod; }
int pow(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b >>= 1;
  }
  return s;
}
struct complex {
  double x, y;
  complex(double a = 0, double b = 0) {
    x = a;
    y = b;
  }
};
complex operator+(complex a, complex b) {
  return complex(a.x + b.x, a.y + b.y);
}
complex operator-(complex a, complex b) {
  return complex(a.x - b.x, a.y - b.y);
}
complex operator*(complex a, complex b) {
  return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
void swap(complex& a, complex& b) {
  complex c = a;
  a = b;
  b = c;
}
int rev[65536], N;
complex w[16][65536];
void pre(int n) {
  int i, j, k;
  for (N = 1, k = 0; N < n; N <<= 1) k++;
  for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
  k = 0;
  for (i = 2; i <= N; i <<= 1) {
    for (j = 0; j < i; j++)
      w[k][j] = complex(cos(j * M_PI / (i / 2)), sin(j * M_PI / (i / 2)));
    k++;
  }
}
void fft(complex* a, int on) {
  int i, j, k, f;
  complex t, wi;
  for (i = 0; i < N; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  f = 0;
  for (i = 2; i <= N; i <<= 1) {
    for (j = 0; j < N; j += i) {
      for (k = 0; k < i >> 1; k++) {
        wi = w[f][k];
        wi.y *= on;
        t = wi * a[i / 2 + j + k];
        a[i / 2 + j + k] = a[j + k] - t;
        a[j + k] = a[j + k] + t;
      }
    }
    f++;
  }
  if (on == -1) {
    for (i = 0; i < N; i++) a[i].x /= N;
  }
}
complex A[65536], B[65536], C[65536], D[65536];
void mul(int* a, int* b, int n) {
  int i;
  complex t;
  for (i = 0; i < N; i++) {
    A[i] = a[i] >> 15;
    B[i] = a[i] & 32767;
    C[i] = b[i] >> 15;
    D[i] = b[i] & 32767;
  }
  fft(A, 1);
  fft(B, 1);
  fft(C, 1);
  fft(D, 1);
  for (i = 0; i < N; i++) {
    t = A[i] * D[i] + B[i] * C[i];
    A[i] = A[i] * C[i];
    C[i] = B[i] * D[i];
    B[i] = t;
  }
  fft(A, -1);
  fft(B, -1);
  fft(C, -1);
  memset(a, 0, (n + 1) << 2);
  for (i = 0; i <= n; i++)
    a[i] = ((llround(A[i].x) % mod << 30) + (llround(B[i].x) % mod << 15) +
            llround(C[i].x) % mod) %
           mod;
}
int ta[65536];
void trans(int* a, int* b, int n, int p) {
  int i, t;
  memset(ta, 0, sizeof(ta));
  t = 1;
  for (i = 0; i <= n; i++) {
    ta[i] = mul(a[i], t);
    t = mul(t, p);
  }
  mul(ta, b, n);
  memcpy(a, ta, sizeof(ta));
}
int fac[30010], rfac[30010];
int binom(int n, int k) { return mul(fac[n], mul(rfac[k], rfac[n - k])); }
int f[65536], g[65536];
int main() {
  long long n;
  int k, i, b, ans;
  scanf("%I64d%d", &n, &k);
  if (n > k) {
    putchar('0');
    return 0;
  }
  fac[0] = 1;
  for (i = 1; i <= k; i++) fac[i] = mul(fac[i - 1], i);
  rfac[k] = pow(fac[k], mod - 2);
  for (i = k; i > 0; i--) rfac[i - 1] = mul(rfac[i], i);
  for (i = 1; i <= k; i++) f[i] = rfac[i];
  g[0] = 1;
  pre(k << 1 | 1);
  b = 2;
  while (n) {
    if (n & 1) trans(g, f, k, b);
    trans(f, f, k, b);
    b = mul(b, b);
    n >>= 1;
  }
  ans = 0;
  for (i = n; i <= k; i++)
    ans = (ans + mul(mul(g[i], fac[i]), binom(k, i))) % mod;
  printf("%d", (ans + mod) % mod);
}
