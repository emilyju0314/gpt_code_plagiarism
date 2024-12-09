#include <bits/stdc++.h>
using namespace std;
long long powi(long long a, long long b) {
  long long c = 1;
  for (; b; b /= 2, a = a * a % 998244353)
    if (b & 1) c = c * a % 998244353;
  return c;
}
void NTT(long long A[], int n, int fl = 1) {
  for (int i = 1; i < n; ++i) {
    int k = 0;
    for (int p = 1, q = n >> 1; p < n; p <<= 1, q >>= 1)
      if (p & i) k += q;
    if (i < k) swap(A[i], A[k]);
  }
  for (int i = 2; i <= n; i <<= 1) {
    long long wi = powi(3, (998244353 - 1) / i);
    if (fl == -1) wi = powi(wi, 998244353 - 2);
    for (int j = 0; j < n; j += i) {
      long long w = 1;
      for (int k = j; k < j + i / 2; ++k) {
        long long u = A[k], v = (A[k + i / 2] * w) % 998244353;
        A[k] = (u + v) % 998244353;
        A[k + i / 2] = (u - v + 998244353) % 998244353;
        (w *= wi) %= 998244353;
      }
    }
  }
  if (fl == -1)
    for (int i = 0; i < n; ++i) (A[i] *= powi(n, 998244353 - 2)) %= 998244353;
}
long long tmp1[600000], tmp2[600000], tmp5[600000], tmp3[600000], tmp6[600000];
void GET_INV(long long A[], long long B[], int n) {
  B[0] = powi(A[0], 998244353 - 2);
  for (int p = 1; p < n; p <<= 1) {
    for (int i = 0; i < (p << 1); ++i) tmp1[i] = A[i];
    for (int i = (p << 1); i < (p << 2); ++i) tmp1[i] = 0;
    for (int i = p; i < (p << 2); ++i) B[i] = 0;
    NTT(tmp1, p << 2);
    NTT(B, p << 2);
    for (int i = 0; i < (p << 2); ++i)
      B[i] = (2 - B[i] * tmp1[i] % 998244353 + 998244353) % 998244353 * B[i] %
             998244353;
    NTT(B, p << 2, -1);
    for (int i = p << 1; i < (p << 2); ++i) B[i] = 0;
  }
}
void sqrt(long long A[], long long B[], int n) {
  long long inv2 = powi(2, 998244353 - 2);
  for (long long i = 0; i < 998244353; ++i)
    if (i * i % 998244353 == A[0]) {
      B[0] = i;
      break;
    }
  for (int p = 1; p < n; p <<= 1) {
    for (int i = 0; i < (p << 1); ++i) tmp3[i] = A[i];
    for (int i = (p << 1); i < (p << 2); ++i) tmp3[i] = 0;
    GET_INV(B, tmp2, p << 1);
    NTT(tmp2, p << 2);
    NTT(tmp3, p << 2);
    NTT(B, p << 2);
    for (int i = 0; i < (p << 2); ++i)
      tmp5[i] = (B[i] * B[i] % 998244353 + tmp3[i]) % 998244353;
    NTT(tmp5, p << 2, -1);
    for (int i = p << 1; i < (p << 2); ++i) tmp5[i] = 0;
    NTT(tmp5, p << 2);
    for (int i = 0; i < (p << 2); ++i)
      B[i] = tmp5[i] % 998244353 * (inv2 * tmp2[i] % 998244353) % 998244353;
    NTT(B, p << 2, -1);
    for (int i = p << 1; i < (p << 2); ++i) B[i] = 0;
  }
}
int n, m, nn;
long long C[600000], F[600000];
void debug() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> C[i];
  sqrt(C, F, n);
  for (int i = 0; i < n; ++i) cout << F[i] << " ";
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    C[a] = 1;
  }
  nn = 1;
  while (nn <= m) nn *= 2;
  nn *= 2;
  for (int i = 0; i <= m; ++i) C[i] = (-4 * C[i] + 998244353) % 998244353;
  C[0]++;
  sqrt(C, tmp6, m + 1);
  tmp6[0] = (tmp6[0] + 1) % 998244353;
  for (int i = m + 2; i <= m * 5; ++i) tmp6[i] = 0;
  GET_INV(tmp6, F, m + 1);
  for (int i = 0; i <= m; ++i) F[i] = (F[i] * 2) % 998244353;
  for (int i = 1; i <= m; ++i) printf("%I64d\n", F[i]);
}
