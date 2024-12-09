#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MN = 1 << 20;
void fwht(long long *a, bool invert) {
  for (int len = 2; len <= MN; len <<= 1) {
    for (int i = 0; i < MN; i += len) {
      for (int j = 0; j < len / 2; j++) {
        long long u = a[i + j], v = a[i + j + len / 2];
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
      }
    }
  }
  if (invert)
    for (int i = 0; i < MN; i++) a[i] /= MN;
}
long long fa[MN], fb[MN];
void multiply(long long *a, long long *b, long long *res) {
  for (int i = 0; i < MN; i++) fa[i] = a[i];
  for (int i = 0; i < MN; i++) fb[i] = b[i];
  fwht(fa, false);
  fwht(fb, false);
  for (int i = 0; i < MN; i++) fa[i] *= fb[i];
  fwht(fa, true);
  for (int i = 0; i < MN; i++) res[i] = fa[i];
}
int N;
long long A[MN], B[MN];
int main() {
  scanf("%d", &N);
  scanf("\n");
  for (int i = 0; i < (1 << N); i++) {
    char t;
    scanf("%c", &t);
    A[i] = t == '1';
  }
  multiply(A, A, B);
  int ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    int p = 1;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) continue;
      p = p * 2 % mod;
    }
    ans += 1LL * p * B[i] % mod;
    ans %= mod;
  }
  ans = 1LL * ans * 3 % mod;
  printf("%d", ans);
}
