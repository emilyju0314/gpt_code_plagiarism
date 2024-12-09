#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
const int Inv2 = 500000004;
const int Data0 = 1;
const int Data1 = 4;
long long e[17][17], f[17][17], s[17], t[17];
int L, R;
void Assign(long long a[][17], long long b[][17]) {
  for (int i = 16; i >= 0; --i)
    for (int j = 16; j >= 0; --j) a[i][j] = b[i][j];
}
void Assign(long long a[], long long b[]) {
  for (int i = 16; i >= 0; --i) a[i] = b[i];
}
void Mult(long long a[][17], long long b[][17]) {
  long long c[17][17];
  memset(c, 0, sizeof(c));
  for (int i = 16; i >= 0; --i)
    for (int j = 16; j >= 0; --j)
      for (int k = 16; k >= 0; --k)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % Mod;
  for (int i = 16; i >= 0; --i)
    for (int j = 16; j >= 0; --j) a[i][j] = c[i][j];
}
void Mult(long long a[], long long b[][17]) {
  long long c[17];
  memset(c, 0, sizeof(c));
  for (int i = 16; i >= 0; --i)
    for (int j = 16; j >= 0; --j) c[j] = (c[j] + a[i] * b[i][j]) % Mod;
  for (int i = 16; i >= 0; --i) a[i] = c[i];
}
long long work(int N) {
  if (N == 0) return Data0 * 2;
  if (N == 1) return (Data0 + Data1) * 2;
  Assign(t, s);
  Assign(f, e);
  for (N--; N; N >>= 1) {
    if (N & 1) Mult(t, f);
    Mult(f, f);
  }
  return t[16];
}
int main() {
  scanf("%d%d", &L, &R);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k) {
        if (i == j) continue;
        if ((i ^ 1) == j) continue;
        if (j == k) continue;
        if ((j ^ 1) == k) continue;
        if (min(min(i, j), k) == 0 && max(max(i, j), k) == 2 && i + j + k == 3)
          continue;
        e[i * 4 + j][j * 4 + k] = 1;
      }
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) e[i * 4 + j][16] = 1;
  e[16][16] = 1;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) {
      if (i == j) continue;
      if ((i ^ 1) == j) continue;
      s[i * 4 + j] = 1;
    }
  s[16] = (Data0 + Data1) * 2;
  long long ans1 = work(R);
  long long ans2 = work(L - 1);
  long long ans3 = 0;
  long long ans4 = 0;
  int LL = (L + 2) / 2, RR = (R + 1) / 2;
  LL = max(LL, 2);
  if (LL <= RR) {
    ans3 = work(RR);
    ans4 = work(LL - 1);
  }
  long long ans = (ans1 - ans2 + ans3 - ans4) % Mod;
  ans += Mod;
  ans %= Mod;
  ans *= Inv2;
  ans %= Mod;
  printf("%I64d\n", ans);
  return 0;
}
