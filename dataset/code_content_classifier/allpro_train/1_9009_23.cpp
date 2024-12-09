#include <bits/stdc++.h>
int read() {
  char ch = '!';
  int res = 0, f = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = 1;
  }
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return f ? -res : res;
}
const int Mod = 490019, P = Mod - 1;
const double pi = acos(-1.0);
const int N = (1 << 20) + 7;
int qpow(int x, long long y) {
  int tms = 1;
  while (y) {
    if (y & 1) tms = 1ll * tms * x % Mod;
    x = 1ll * x * x % Mod, y >>= 1;
  }
  return tms;
}
int Len, L, Lm, r[N];
struct complex {
  double x, y;
} w[N];
inline complex operator+(const complex &a, const complex &b) {
  return {a.x + b.x, a.y + b.y};
}
inline complex operator-(const complex &a, const complex &b) {
  return {a.x - b.x, a.y - b.y};
}
inline complex operator*(const complex &a, const complex &b) {
  return {a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y};
}
inline complex conj(const complex &a) { return {a.x, -a.y}; }
void Init(int n) {
  for (L = 1, Lm = -1; L < n; L <<= 1, ++Lm)
    ;
  for (int i = 0; i < L; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << Lm);
  for (int i = 1; i < L; i <<= 1)
    for (int j = 0; j < i; j++)
      w[i + j] = (complex){cos(j * pi / i), sin(j * pi / i)};
}
void FFT(complex *p) {
  for (int i = 0; i < L; i++)
    if (i < r[i]) std::swap(p[i], p[r[i]]);
  for (int i = 1, s = 2; i < L; i <<= 1, s <<= 1)
    for (int j = 0; j < L; j += s)
      for (int k = 0, o = i; k < i; ++k, ++o) {
        auto x = p[j + k], y = w[o] * p[i + j + k];
        p[j + k] = x + y, p[i + j + k] = x - y;
      }
}
void Mul(int n, int m, int *f, int *g, int *h) {
  static complex a[N], b[N], A[N], B[N], C[N], D[N];
  Init(n + m + 1);
  for (int i = 0; i < L; i++)
    a[i] = (complex){(double)(f[i] & 0x7fff), (double)(f[i] >> 15)};
  for (int i = 0; i < L; i++)
    b[i] = (complex){(double)(g[i] & 0x7fff), (double)(g[i] >> 15)};
  FFT(a), FFT(b);
  for (int i = 0, j; i < L; i++) {
    j = (L - i) & (L - 1);
    auto da = (a[i] + conj(a[j])) * (complex){0.5, 0},
         db = (a[i] - conj(a[j])) * (complex){0, -0.5};
    auto dc = (b[i] + conj(b[j])) * (complex){0.5, 0},
         dd = (b[i] - conj(b[j])) * (complex){0, -0.5};
    A[j] = da * dc, B[j] = da * dd, C[j] = db * dc, D[j] = db * dd;
  }
  for (int i = 0; i < L; i++) a[i] = A[i] + B[i] * (complex){0, 1};
  for (int i = 0; i < L; i++) b[i] = C[i] + D[i] * (complex){0, 1};
  FFT(a), FFT(b);
  for (int i = 0; i < L; i++) {
    long long da = (long long)(a[i].x / L + 0.5) % Mod,
              db = (long long)(a[i].y / L + 0.5) % Mod;
    long long dc = (long long)(b[i].x / L + 0.5) % Mod,
              dd = (long long)(b[i].y / L + 0.5) % Mod;
    h[i] = (da + (db + dc << 15) + (dd << 30)) % Mod;
  }
}
int n, m, A[N], B[N], F[N], G[N], H[N], pw[N], ipw[N], C, ans;
int main() {
  n = read(), m = read(), C = read();
  for (int i = 0; i < n; ++i) {
    int t = 1ll * i * i % P;
    A[t] = (A[t] + read()) % Mod;
  }
  for (int i = 0; i < m; ++i) {
    int t = 1ll * i * i % P * i % P;
    B[t] = (B[t] + read()) % Mod;
  }
  pw[0] = 1;
  for (int i = 1; i < Mod; ++i) pw[i] = 1ll * pw[i - 1] * C % Mod;
  ipw[0] = 1, ipw[1] = qpow(C, Mod - 2);
  for (int i = 2; i < Mod; ++i) ipw[i] = 1ll * ipw[i - 1] * ipw[1] % Mod;
  for (int i = 0; i < 2 * P; ++i) F[i] = pw[1ll * (i) * ((i)-1) / 2 % P];
  for (int i = 0; i < P; ++i)
    G[P - 1 - i] = 1ll * B[i] * ipw[1ll * (i) * ((i)-1) / 2 % P] % Mod;
  Mul(P, P, F, G, H);
  for (int i = 0; i < P; ++i)
    ans = (ans + 1ll * ipw[1ll * (i) * ((i)-1) / 2 % P] * H[P - 1 + i] % Mod *
                     A[i] % Mod) %
          Mod;
  std::cout << ans;
  return 0;
}
