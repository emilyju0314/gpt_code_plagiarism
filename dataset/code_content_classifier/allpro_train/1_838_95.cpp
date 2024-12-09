#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class Iter>
void rprintf(const char *fmt, Iter begin, Iter end) {
  for (bool sp = 0; begin != end; ++begin) {
    if (sp)
      putchar(' ');
    else
      sp = true;
    printf(fmt, *begin);
  }
  putchar('\n');
}
template <unsigned MOD>
struct ModInt {
  static const unsigned static_MOD = MOD;
  unsigned x;
  void undef() { x = (unsigned)-1; }
  bool isnan() const { return x == (unsigned)-1; }
  inline int geti() const { return (int)x; }
  ModInt() { x = 0; }
  ModInt(const ModInt &y) { x = y.x; }
  ModInt(int y) {
    if (y < 0 || (int)MOD <= y) y %= (int)MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned y) {
    if (MOD <= y)
      x = y % MOD;
    else
      x = y;
  }
  ModInt(long long y) {
    if (y < 0 || MOD <= y) y %= MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned long long y) {
    if (MOD <= y)
      x = y % MOD;
    else
      x = y;
  }
  ModInt &operator+=(const ModInt y) {
    if ((x += y.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt y) {
    if ((x -= y.x) & (1u << 31)) x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt y) {
    x = (unsigned long long)x * y.x % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt y) {
    x = (unsigned long long)x * y.inv().x % MOD;
    return *this;
  }
  ModInt operator-() const { return (x ? MOD - x : 0); }
  ModInt inv() const {
    unsigned a = MOD, b = x;
    int u = 0, v = 1;
    while (b) {
      int t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if (u < 0) u += MOD;
    return ModInt(u);
  }
  ModInt pow(long long y) const {
    ModInt b = *this, r = 1;
    if (y < 0) {
      b = b.inv();
      y = -y;
    }
    for (; y; y >>= 1) {
      if (y & 1) r *= b;
      b *= b;
    }
    return r;
  }
  friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
  friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
  friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
  friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
  friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
  friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
  friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};
const long long MOD = 1000000007;
const int MAX = 100;
ModInt<MOD> inv[MAX + 1], fact[MAX + 1], fact_inv[MAX + 1];
void init() {
  inv[1] = 1;
  for (int i = 2; i <= MAX; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i);
  fact[0] = fact_inv[0] = 1;
  for (int i = 1; i <= MAX; i++) {
    fact[i] = fact[i - 1] * i;
    fact_inv[i] = fact_inv[i - 1] * inv[i];
  }
}
ModInt<MOD> nCk(int n, int k) {
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}
int N, P;
int C[55];
ModInt<MOD> dp[55][55][55][55];
void MAIN() {
  scanf("%d%d", &N, &P);
  for (int i = 0, i_len = (N); i < i_len; ++i) scanf("%d", C + i);
  init();
  dp[0][0][0][0] = 1;
  for (int i = 0, i_len = (N); i < i_len; ++i)
    for (int EB = 0, EB_len = (i + 1); EB < EB_len; ++EB)
      for (int EW = 0, EW_len = (i + 1 - EB); EW < EW_len; ++EW)
        for (int OB = 0, OB_len = (i + 1 - EB - EW); OB < OB_len; ++OB) {
          ModInt<MOD> val = dp[i][EB][EW][OB];
          if (val.x == 0u) continue;
          int OW = i - EB - EW - OB;
          if (C[i] != 1) {
            for (int ow = 0, ow_len = (OW + 1); ow < ow_len; ++ow) {
              int mypath = (ow + 1) & 1;
              int nEB = EB + (mypath == 0);
              int nOB = OB + (mypath == 1);
              dp[i + 1][nEB][EW][nOB] += val * nCk(OW, ow) * (1LL << (i - OW));
            }
          }
          if (C[i] != 0) {
            for (int ob = 0, ob_len = (OB + 1); ob < ob_len; ++ob) {
              int mypath = (ob + 1) & 1;
              int nEW = EW + (mypath == 0);
              int nOW = OW + (mypath == 1);
              dp[i + 1][EB][nEW][OB] += val * nCk(OB, ob) * (1LL << (i - OB));
            }
          }
        }
  ModInt<MOD> ans = 0;
  for (int EB = 0, EB_len = (N + 1); EB < EB_len; ++EB)
    for (int EW = 0, EW_len = (N + 1 - EB); EW < EW_len; ++EW)
      for (int OB = 0, OB_len = (N + 1 - EB - EW); OB < OB_len; ++OB) {
        int OW = N - EB - EW - OB;
        int parity = (OB + OW) & 1;
        if (parity == P) ans += dp[N][EB][EW][OB];
      }
  printf("%d\n", ans.geti());
}
int main() {
  int TC = 1;
  for (int tc = 0, tc_len = (TC); tc < tc_len; ++tc) MAIN();
  return 0;
}
