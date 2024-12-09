#include <bits/stdc++.h>
using namespace std;
namespace NTT {
const int N = 600100, P = 998244353;
int qpow(int x, int y) {
  int res(1);
  while (y) {
    if (y & 1) res = 1ll * res * x % P;
    x = 1ll * x * x % P;
    y >>= 1;
  }
  return res;
}
int r[N];
void ntt(int *x, int lim, int opt) {
  int i, j, k, m, gn, g, tmp;
  for (i = 0; i < lim; ++i)
    if (r[i] < i) swap(x[i], x[r[i]]);
  for (m = 2; m <= lim; m <<= 1) {
    k = m >> 1;
    gn = qpow(3, (P - 1) / m);
    for (i = 0; i < lim; i += m) {
      g = 1;
      for (j = 0; j < k; ++j, g = 1ll * g * gn % P) {
        tmp = 1ll * x[i + j + k] * g % P;
        x[i + j + k] = (x[i + j] - tmp + P) % P;
        x[i + j] = (x[i + j] + tmp) % P;
      }
    }
  }
  if (opt == -1) {
    reverse(x + 1, x + lim);
    int inv = qpow(lim, P - 2);
    for (i = 0; i < lim; ++i) x[i] = 1ll * x[i] * inv % P;
  }
}
int A[20][N], B[N], C[N];
};  // namespace NTT
using namespace NTT;
int res;
int num[3000010];
int sum[200010];
bool cmp(int a, int b) { return a > b; }
int dfs(int a, int b, int tot) {
  int olen = num[b] + 1;
  if (a) olen -= num[a - 1];
  int len = 1;
  while (len < olen) len <<= 1;
  if (a == b) {
    for (int i = 0; i < olen; i++) A[tot][i] = 1;
    for (int i = olen; i < len; i++) A[tot][i] = 0;
    return olen;
  }
  int r = ((a + b) >> 1) + 1;
  int l = a;
  int len1 = dfs(r, b, tot);
  for (int i = len1; i < len; i++) A[tot][i] = 0;
  int len2 = dfs(a, r - 1, tot + 1);
  for (int i = len2; i < len; i++) A[tot + 1][i] = 0;
  for (int j = 0; j < len; ++j)
    NTT::r[j] = (j & 1) * (len >> 1) + (NTT::r[j >> 1] >> 1);
  ntt(A[tot], len, 1);
  ntt(A[tot + 1], len, 1);
  for (int i = 0; i < len; ++i) A[tot][i] = 1ll * A[tot][i] * A[tot + 1][i] % P;
  ntt(A[tot], len, -1);
  return len;
}
int main() {
  int n;
  scanf("%d", &n);
  res = n / 2;
  int nd = 0;
  for (int i = 0; i < n; i++) {
    int u;
    scanf("%d", &u);
    num[u]++;
  }
  for (int i = 0; i < 3000010; i++) {
    if (num[i]) num[nd++] = num[i];
  }
  for (int i = 1; i < nd; i++) {
    num[i] += num[i - 1];
  }
  int len = 1;
  while (len < n * 2) len <<= 1;
  dfs(0, nd - 1, 0);
  printf("%d\n", A[0][res]);
  return 0;
}
