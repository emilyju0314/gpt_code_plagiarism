#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxp = 100005;
static int plist[maxp / 3], pmask[maxp + 1], pcnt;
static inline void init_primes() {
  for (int i = 1; i <= maxp; ++i) pmask[i] = i;
  for (int i = 2; i <= maxp; ++i) {
    if (pmask[i] == i) {
      plist[pcnt++] = i;
    }
    for (int j = 0; j < pcnt; ++j) {
      const long long t = (long long)plist[j] * i;
      if (t > maxp) break;
      pmask[t] = plist[j];
      if (i % plist[j] == 0) {
        break;
      }
    }
  }
}
static long long pv[1024];
int pc[1024];
static inline int factorize(long long n) {
  if (n <= 0) {
    return 0;
  }
  int top = 0;
  if (n <= maxp) {
    while (n != 1) {
      int now = pmask[n];
      int c = 0;
      while (n % now == 0) n /= now, ++c;
      if (c) pv[top] = now, pc[top++] = c;
    }
  } else {
    for (int i = 0; i < pcnt; ++i) {
      const long long p = plist[i];
      const long long test = p * p;
      if (p > n) break;
      int c = 0;
      while (n % p == 0) n /= p, ++c;
      if (c) pv[top] = p, pc[top++] = c;
    }
    if (n != 1) pv[top] = n, pc[top++] = 1;
  }
  return top;
}
template <long long P>
struct moder {
  static long long inv(long long x) {
    long long result = 1;
    int n = P - 2;
    x %= P;
    for (; n; n >>= 1, x = x * x % P)
      if (n & 1) result = result * x % P;
    return result;
  }
  static long long* fac;
  static void init_fac() {
    fac = new long long[500000];
    fac[0] = 1;
    for (int i = 1; i < 500000; ++i) fac[i] = fac[i - 1] * i % P;
  }
  static void destroy_fac() { delete[] fac; }
  static long long s(int x) { return x & 1 ? -1 : 1; }
  static long long comb(long long m, long long n) {
    long long pp = 0;
    long long dist = m - n;
    for (long long x = P; x <= m; x *= P) pp += m / x - n / x - dist / x;
    if (pp) return 0;
    long long l = 1, r = 1;
    for (long long x = m; x; x /= P) l = l * s(x / P) * fac[x % P] % P;
    for (long long x = n; x; x /= P) r = r * s(x / P) * fac[x % P] % P;
    for (long long x = dist; x; x /= P) r = r * s(x / P) * fac[x % P] % P;
    l = (l + P) % P;
    r = (r + P) % P;
    long long t = (inv(r) * l % P + P) % P;
    return t;
  }
};
template <long long P>
long long* moder<P>::fac;
moder<1000000007> oml;
int main() {
  init_primes();
  oml.init_fac();
  map<int, int> mem;
  int n = Rint();
  for (int i = 0; i < n; ++i) {
    int v = Rint();
    if (v == 1) continue;
    int top = factorize(v);
    for (int j = 0; j < top; ++j) mem[pv[j]] += pc[j];
  }
  long long ans = 1;
  for (map<int, int>::iterator iter = mem.begin(); iter != mem.end(); ++iter) {
    long long v = oml.comb(n + iter->second - 1, iter->second);
    ans = ans * v % 1000000007;
  }
  printf("%I64d\n", ans);
  return 0;
}
