#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  char c = getchar();
  int x = 0;
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return x;
}
const int S = 1e5 + 5;
const double pi = acos(-1.0);
struct cop {
  double r, i;
  cop(double _r = 0.0, double _i = 0.0) { r = _r, i = _i; }
  cop operator+(cop x) const { return cop(r + x.r, i + x.i); }
  cop operator-(cop x) const { return cop(r - x.r, i - x.i); }
  cop operator*(cop x) const {
    return cop(r * x.r - i * x.i, r * x.i + i * x.r);
  }
} a[S], b[S];
namespace FFT {
int m, r[S], l;
void init(int x) {
  for (m = 1, l = 0; m <= x; ++l, m <<= 1)
    ;
  for (int i = 0; i < m; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
void fft(cop* a, int f) {
  for (int i = 0; i < m; ++i)
    if (i < r[i]) std::swap(a[i], a[r[i]]);
  for (int i = 1; i < m; i <<= 1) {
    const cop wn(cos(pi / i), sin(pi / i) * f);
    for (int j = 0; j < m; j += (i << 1)) {
      cop w(1, 0);
      for (int k = 0; k < i; ++k, w = w * wn) {
        cop v1 = a[j + k], v2 = w * a[i + j + k];
        a[j + k] = v1 + v2, a[i + j + k] = v1 - v2;
      }
    }
  }
  if (f == -1)
    for (int i = 0; i < m; i++) a[i].r /= m;
}
void mult() {
  fft(a, 1), fft(b, 1);
  for (int i = 0; i < m; ++i) a[i] = a[i] * b[i];
  fft(a, -1);
}
}  // namespace FFT
const int N = 105, M = 20005;
int n, m, t, x, u[N], v[N], w[N], d[N][N];
double p[N][M], s[N][M], f[N][M], g[N][M];
void cdq(int l, int r) {
  if (l == r) {
    for (int i = 1; i < n; ++i) f[i][l] = 1e20;
    for (int i = 1; i <= m; ++i)
      f[u[i]][l] =
          min(f[u[i]][l], g[i][l] + w[i] + s[i][t - l + 1] * (d[v[i]][n] + x));
    return;
  }
  int mid = l + r >> 1;
  cdq(mid + 1, r);
  FFT::init(r - l + 1);
  for (int x = 1; x <= m; ++x) {
    for (int i = 0; i < FFT::m; ++i) a[i].r = a[i].i = b[i].r = b[i].i = 0;
    for (int i = mid + 1; i <= r; ++i) a[i - mid - 1].r = f[v[x]][i];
    for (int i = 1; i <= r - l; ++i) b[r - l - i].r = p[x][i];
    FFT::mult();
    for (int i = l; i <= mid; ++i) g[x][i] += a[i - mid - 1 + r - l].r;
  }
  cdq(l, mid);
}
int main() {
  n = gi(), m = gi(), t = gi(), x = gi();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) d[i][j] = 1e9;
  for (int i = 1; i <= m; ++i) {
    u[i] = gi(), v[i] = gi(), w[i] = gi(), d[u[i]][v[i]] = w[i];
    for (int j = 1; j <= t; ++j) p[i][j] = (double)gi() / 100000;
    for (int j = t; j; --j) s[i][j] = s[i][j + 1] + p[i][j];
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      if (d[i][k] != 1e9)
        for (int j = 1; j <= n; ++j)
          if (d[k][j] != 1e9) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cdq(0, t), printf("%.10lf\n", f[1][0]);
}
