#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int P = 998244353, N = 200050, M = 54;
int size[1 << 20], C[205][205];
inline int count(long long w) {
  static int r;
  r = 0;
  if (w) r += size[w & 1048575], w >>= 20;
  if (w) r += size[w & 1048575], w >>= 20;
  if (w) r += size[w & 1048575], w >>= 20;
  if (w) r += size[w & 1048575], w >>= 20;
  return r;
}
int n, m, temp = 1;
long long B[M];
inline void Ins(long long x) {
  int i, j;
  for (i = m - 1; i >= 0; --i)
    if (x >> i & 1) {
      if (B[i]) {
        x ^= B[i];
        continue;
      }
      B[i] = x;
      for (j = 0; j < i; ++j)
        if (B[i] >> j & 1) B[i] ^= B[j];
      for (j = i + 1; j < m; ++j)
        if (B[j] >> i & 1) B[j] ^= B[i];
      return;
    }
  temp <<= 1, temp %= P;
}
int cnt;
long long v[M];
namespace subtask1 {
int ans[M];
inline void dfs(int dep, long long x) {
  if (dep > cnt) {
    ++ans[count(x)];
    return;
  }
  dfs(dep + 1, x);
  dfs(dep + 1, x ^ v[dep]);
}
inline void solve() {
  dfs(1, 0);
  for (int i = 0; i <= m; ++i) cout << (long long)ans[i] * temp % P << ' ';
  cout << '\n';
}
}  // namespace subtask1
const int L = 1 << 18;
int F[L], A[L];
int ans[M];
void FWT(int *A, int n) {
  register int i, j, k, x, y;
  for (i = 1; i < n; i <<= 1)
    for (j = 0; j < n; j += i << 1)
      for (k = j; k < i + j; ++k)
        x = A[k], y = A[k + i], A[k] = (x + y >= P) ? (x + y - P) : (x + y),
        A[k + i] = (x < y) ? (x + P - y) : (x - y);
}
void IFWT(int *A, int n) {
  register int i, j, k, x, y;
  for (i = 1; i < n; i <<= 1)
    for (j = 0; j < n; j += i << 1)
      for (k = j; k < i + j; ++k) {
        x = A[k], y = A[k + i], A[k] = (x + y >= P) ? (x + y - P) : (x + y),
        A[k + i] = (x < y) ? (x + P - y) : (x - y);
        A[k] = (A[k] & 1) ? (A[k] + P >> 1) : (A[k] >> 1);
        A[k + i] = (A[k + i] & 1) ? (A[k + i] + P >> 1) : (A[k + i] >> 1);
      }
}
int cnt2;
long long v2[M];
vector<long long> GG[M];
inline void dfs2(int dep, long long v) {
  if (dep > cnt2) {
    GG[count(v >> 18)].push_back(v & (L - 1));
    return;
  }
  dfs2(dep + 1, v);
  dfs2(dep + 1, v ^ v2[dep]);
}
int cnt3;
long long v3[M];
inline void dfs3(int dep, long long v) {
  if (dep > cnt3) {
    ++A[v];
    return;
  }
  dfs3(dep + 1, v);
  dfs3(dep + 1, v ^ v3[dep]);
}
int main() {
  int i, j;
  long long x;
  for (i = 0; i < 1 << 20; ++i) size[i] = size[i >> 1] + (i & 1);
  for (i = 0; i <= 200; ++i)
    for (j = 0; j <= 200; ++j) {
      if (i > j)
        C[i][j] = 0;
      else if (i == j)
        C[i][j] = 1;
      else if (!j)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % P;
    }
  read(n), read(m);
  while (n--) read(x), Ins(x);
  cnt = 0;
  for (i = 0; i < m; ++i)
    if (B[i]) v[++cnt] = B[i];
  if (cnt <= 26) {
    subtask1::solve();
    return 0;
  }
  for (i = 1; i <= cnt; ++i)
    if (v[i] < L)
      v3[++cnt3] = v[i];
    else
      v2[++cnt2] = v[i];
  dfs3(1, 0);
  dfs2(1, 0);
  FWT(A, L);
  for (i = 0; i < m; ++i)
    if (GG[i].size()) {
      for (j = 0; j < L; ++j) F[j] = 0;
      for (j = 0; j < GG[i].size(); ++j) ++F[GG[i][j]];
      FWT(F, L);
      for (j = 0; j < L; ++j) F[j] = (long long)F[j] * A[j] % P;
      IFWT(F, L);
      for (j = 0; j < L; ++j) ans[i + size[j]] = (ans[i + size[j]] + F[j]) % P;
    }
  for (i = 0; i <= m; ++i) cout << (long long)ans[i] * temp % P << ' ';
  cout << '\n';
  return 0;
}
