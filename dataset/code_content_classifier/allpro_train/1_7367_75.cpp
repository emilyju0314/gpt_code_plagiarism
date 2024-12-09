#include <bits/stdc++.h>
inline int read() {
  int ret, cc, sign = 1;
  while (!isdigit(cc = getchar())) sign = cc == '-' ? -1 : sign;
  ret = cc - 48;
  while (isdigit(cc = getchar())) ret = cc - 48 + ret * 10;
  return ret * sign;
}
const int MOD = 998244353;
const int G = 3;
const int MAXN = 600010;
inline int add(int a, int b) { return (a += b) >= MOD ? a - MOD : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + MOD : a; }
inline int mul(int a, int b) { return 1ll * a * b % MOD; }
inline int qpow(int a, int p) {
  int ret = 1;
  for (p += (p < 0) * (MOD - 1); p; p >>= 1, a = mul(a, a))
    if (p & 1) ret = mul(ret, a);
  return ret;
}
inline std::vector<int> operator*(const std::vector<int>&,
                                  const std::vector<int>&);
int fac[MAXN];
int inv[MAXN];
int main() {
  int n = read(), K = read(), L = read();
  n = n << 1 | 1, fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  inv[n] = qpow(fac[n], MOD - 2);
  for (int i = n; i >= 1; --i) inv[i - 1] = mul(inv[i], i);
  n >>= 1;
  std::vector<int> A(n + 1), B(n + 1);
  for (int i = 0; i <= n; ++i) {
    A[i] = inv[i] * (i >= K);
    B[i] = i & 1 ? MOD - inv[i] : inv[i];
  }
  A = A * B;
  int ans = 0;
  for (int i = K, pw = qpow(2, K); i <= n; ++i, pw = mul(pw, 2)) {
    int cof = mul(pw, mul(fac[i], fac[i]));
    cof = mul(cof, mul(inv[i << 1 | 1], inv[n - i]));
    ans = add(ans, mul(cof, A[i]));
  }
  ans = mul(ans, fac[n]);
  printf("%d\n", mul(ans, L));
}
int rev[MAXN];
int W[MAXN];
inline int getrev(int n) {
  int len = 1, cnt = 0;
  while (len < n) len <<= 1, ++cnt;
  for (int i = 0; i < len; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
  return len;
}
inline void NTT(std::vector<int>& a, int n, int opt) {
  a.resize(n);
  for (int i = 0; i < n; ++i)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int i = (W[0] = 1); i < n; i <<= 1) {
    int wn = qpow(G, opt * (MOD - 1) / (i << 1));
    for (int k = i - 2; k >= 0; k -= 2) W[k + 1] = mul(W[k] = W[k >> 1], wn);
    for (int j = 0, p = i << 1; j < n; j += p) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = mul(W[k], a[j + k + i]);
        a[j + k] = add(x, y), a[j + k + i] = sub(x, y);
      }
    }
  }
  if (opt == -1)
    for (int i = 0, r = qpow(n, MOD - 2); i < n; ++i) a[i] = mul(a[i], r);
}
inline std::vector<int> operator*(const std::vector<int>& lhs,
                                  const std::vector<int>& rhs) {
  std::vector<int> A(lhs), B(rhs);
  int len = A.size() + B.size() - 1;
  int bln = getrev(len);
  NTT(A, bln, 1), NTT(B, bln, 1);
  for (int i = 0; i < bln; ++i) A[i] = mul(A[i], B[i]);
  NTT(A, bln, -1), A.resize(len);
  return A;
}
