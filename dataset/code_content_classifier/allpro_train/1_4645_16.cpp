#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int MAXN = (1 << 19) + 5;
const double pi = acos(-1);
int n;
int maxn;
long long b[MAXN], c[MAXN], a[MAXN];
long long mo;
long long A[MAXN], B[MAXN], mi[MAXN], Mi[MAXN];
int N;
long long d[MAXN];
long long b1[MAXN], c1[MAXN], d1[MAXN];
long long mul(long long x, long long y) {
  long long t = double(1) * x * y / mo;
  long long ret = x * y - t * mo;
  ret = (ret % mo + mo) % mo;
  return ret;
}
long long quickmi(long long x, long long tim) {
  long long ret = 1;
  x = (x % mo + mo) % mo;
  for (; tim; tim /= 2, x = mul(x, x))
    if (tim & 1) ret = mul(ret, x);
  return ret;
}
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
long long dec(long long x, long long y) { return x < y ? x - y + mo : x - y; }
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
bool isprime(long long x) {
  int u = sqrt(x);
  for (int i = 2; i <= u; i++)
    if (x % i == 0) return 0;
  return 1;
}
void DFT(long long *a) {
  for (int i = 0, j = 0; i < N; i++) {
    if (i < j) swap(a[i], a[j]);
    int x = N >> 1;
    for (; (j ^ x) < j; x >>= 1) j ^= x;
    j ^= x;
  }
  for (int i = 1, d = 1; i < N; i <<= 1, d++)
    for (int j = 0; j < N; j += (i << 1))
      for (int k = 0; k < i; k++) {
        long long l = a[j + k], r = mul(a[i + j + k], mi[(maxn >> d) * k]);
        a[i + j + k] = l < r ? l - r + mo : l - r;
        a[j + k] = l + r >= mo ? l + r - mo : l + r;
      }
}
void IDFT(long long *a) {
  DFT(a);
  reverse(a + 1, a + N);
  long long ny = quickmi(N, mo - 2);
  for (int i = 0; i <= N - 1; i++) a[i] = mul(a[i], ny);
}
void dft(long long *a) {
  N = 1;
  while (N <= n * 3) N <<= 1;
  for (int i = 0; i <= N - 1; i++) A[i] = B[i] = 0;
  for (int i = 0; i <= n - 1; i++) {
    int w = 1ll * i * i % (n * 2);
    w = (n * 2 - w) % (n * 2);
    A[i] = mul(Mi[w], a[i]);
  }
  for (int i = 0; i <= n * 2; i++) {
    int w = 1ll * i * i % (n * 2);
    B[i] = Mi[w];
  }
  reverse(A, A + n + 1);
  DFT(A), DFT(B);
  for (int i = 0; i <= N - 1; i++) A[i] = mul(A[i], B[i]);
  IDFT(A);
  for (int i = 0; i <= n - 1; i++) {
    a[i] = A[i + n];
    int w = 1ll * i * i % (n * 2);
    w = (n * 2 - w) % (n * 2);
    a[i] = mul(a[i], Mi[w]);
  }
}
void idft(long long *a) {
  dft(a);
  reverse(a + 1, a + n);
  long long ny = quickmi(n, mo - 2);
  for (int i = 0; i <= n - 1; i++) a[i] = mul(a[i], ny);
}
void prepare() {
  long long ad = 1;
  while (ad <= n * 3) ad <<= 1;
  maxn = ad;
  ad = ad * n * 2 / gcd(n * 2, ad);
  mo = int(1e9) / ad * ad + ad + 1;
  for (; !isprime(mo); mo += ad)
    ;
  int g;
  for (g = 2;; g++) {
    bool yes = 1;
    int u = sqrt(mo - 1);
    for (int i = 2; i <= u; i++)
      if ((mo - 1) % i == 0) {
        yes &= quickmi(g, i) != 1;
        yes &= quickmi(g, (mo - 1) / i) != 1;
      }
    if (yes) break;
  }
  mi[0] = 1;
  mi[1] = quickmi(g, (mo - 1) / maxn);
  for (int i = 2; i <= maxn; i++) mi[i] = mul(mi[i - 1], mi[1]);
  Mi[0] = 1;
  Mi[1] = quickmi(g, (mo - 1) / (n * 2));
  for (int i = 2; i <= n * 2; i++) Mi[i] = mul(Mi[i - 1], Mi[1]);
  for (int i = 0; i <= n - 1; i++) b1[i] = b[i];
  dft(b1);
  for (int i = 0; i <= n - 1; i++) c1[i] = -(c[i] - c[0]) / 2;
  dft(c1);
  for (int i = 1; i <= n - 1; i++) c1[i] = mul(c1[i], quickmi(b1[i], mo - 2));
}
long long solve(long long x) {
  d1[0] = mul(dec(c1[0], mul(x, n)), quickmi(b1[0], mo - 2));
  for (int i = 1; i <= n - 1; i++) d1[i] = c1[i];
  idft(d1);
  for (int i = 0; i <= n - 1; i++) d[i] = d1[i];
  return d1[0];
}
long long ans[10];
int main() {
  n = get();
  for (int i = 0; i <= n - 1; i++) b[i] = get();
  for (int i = 0; i <= n - 1; i++) c[i] = get();
  reverse(b + 1, b + n);
  prepare();
  long long v0 = solve(0), v1 = solve(1);
  if (v0 == v1) return printf("0\n"), 0;
  long long k = (mo - mul(v0, quickmi(v1 - v0, mo - 2))) % mo;
  solve(k);
  if (d[0] != 0) return printf("0\n"), 0;
  for (int i = 0; i <= n - 1; i++)
    if (d[i] > mo / 2) d[i] = d[i] - mo;
  long long A = 0, B = 0, C = 0;
  for (int i = 0; i <= n - 1; i++) {
    int j = (n - i) % n;
    long long v = d[i] - b[j];
    A++;
    B = B + 2ll * v;
    C = C + v * v;
  }
  C = C - c[0];
  if (B * B - 4ll * A * C < 0) return printf("0\n"), 0;
  long long delt = sqrt(B * B - 4ll * A * C);
  if (B * B - 4ll * A * C != delt * delt) return printf("0\n"), 0;
  long long x0 = (-B + delt) / A / 2, x1 = (-B - delt) / A / 2;
  if (x0 > x1) swap(x0, x1);
  if (x0 * A * 2 == delt - B || x0 * A * 2 == -B - delt) ans[++ans[0]] = x0;
  if (x0 != x1) {
    if (x1 * A * 2 == delt - B || x1 * A * 2 == -B - delt) ans[++ans[0]] = x1;
  }
  printf("%I64d\n", ans[0]);
  for (int j = 1; j <= ans[0]; j++) {
    long long a0 = ans[j];
    for (int i = 0; i <= n - 1; i++)
      printf("%I64d%c", d[i] + a0, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
