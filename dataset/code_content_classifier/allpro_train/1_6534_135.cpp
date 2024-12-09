#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void Open() {}
const int N = 800050;
namespace FFT {
int pos[N];
struct comp {
  double r, i;
  comp(double _r = 0, double _i = 0) : r(_r), i(_i) {}
  comp operator+(const comp& x) { return comp(r + x.r, i + x.i); }
  comp operator-(const comp& x) { return comp(r - x.r, i - x.i); }
  comp operator*(const comp& x) {
    return comp(r * x.r - i * x.i, i * x.r + r * x.i);
  }
  comp conj() { return comp(r, -i); }
} A[N], B[N];
const double pi = acos(-1.0);
void FFT(comp a[], int n, int t) {
  for (int i = 1; i < n; ++i)
    if (pos[i] > i) swap(a[i], a[pos[i]]);
  for (int d = 0; (1 << d) < n; ++d) {
    int m = 1 << d, m2 = m << 1;
    double o = pi * 2 / m2 * t;
    comp _w(cos(o), sin(o));
    for (int i = 0; i < n; i += m2) {
      comp w(1, 0);
      for (int j = 0; j < m; ++j) {
        comp &A = a[i + j + m], &B = a[i + j], t = w * A;
        A = B - t;
        B = B + t;
        w = w * _w;
      }
    }
  }
  if (t == -1)
    for (int i = 0; i < n; ++i) a[i].r /= n;
}
void mul(int* a, int* b, int* c, int k) {
  int i, j;
  for (i = 0; i < k; ++i) A[i] = comp(a[i], b[i]);
  j = __builtin_ctz(k) - 1;
  for (int i = 0; i < k; ++i) {
    pos[i] = pos[i >> 1] >> 1 | ((i & 1) << j);
  }
  FFT(A, k, 1);
  for (int i = 0; i < k; ++i) {
    j = (k - i) & (k - 1);
    B[i] = (A[i] * A[i] - (A[j] * A[j]).conj()) * comp(0, -0.25);
  }
  FFT(B, k, -1);
  for (int i = 0; i < k; ++i) {
    c[i] += (B[i].r + 0.5);
  }
}
}  // namespace FFT
using namespace FFT;
char s1[N], s2[N];
int s[N], t[N];
int f[222];
int a[4][N], b[4][N], c[N];
int main() {
  f['A'] = 0, f['T'] = 1, f['G'] = 2, f['C'] = 3;
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s1, s2);
  for (int i = 0; i < n; i++) s[i] = f[s1[i]], a[s[i]][i] = 1;
  for (int i = 0; i < m; i++) t[i] = f[s2[i]], b[t[i]][n - i] = 1;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++) {
      if (s[j] != i) continue;
      int st = j - 1;
      while (st >= max(0, j - k) && a[i][st] == 0) a[i][st] = 1, st--;
      st = j + 1;
      while (st <= min(n - 1, j + k) && a[i][st] == 0) a[i][st] = 1, st++;
    }
  int len = 1;
  while (len < 2 * n) len <<= 1;
  for (int i = 0; i < 4; i++) {
    mul(a[i], b[i], c, len);
  }
  int ans = 0;
  for (int i = n; i < n + n; i++) ans += (c[i] == m);
  printf("%d\n", ans);
  return 0;
}
