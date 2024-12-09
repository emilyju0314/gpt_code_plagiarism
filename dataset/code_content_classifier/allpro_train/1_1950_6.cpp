#include <bits/stdc++.h>
using namespace std;
int n, z;
long long x, y, f[401][401], a[401], tot, ww[1000001], p, aa[301], Ff[301][301];
long long e[100001];
inline void ff() {
  long long w[9][9];
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      for (int k = 1; k <= 3; k++) {
        w[i][j] = w[i][j] + (f[i][k] * f[k][j]) % p;
        w[i][j] %= p;
      }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) f[i][j] = w[i][j];
}
inline void fff() {
  long long w[9][9];
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      for (int k = 1; k <= 3; k++) {
        w[i][j] = w[i][j] + (Ff[i][k] * Ff[k][j]) % p;
        w[i][j] %= p;
      }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) Ff[i][j] = w[i][j];
}
inline void ef() {
  long long w[9];
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      w[i] = w[i] + (e[j] * Ff[j][i]) % p;
      w[i] %= p;
    }
  for (int i = 1; i <= 3; i++) e[i] = w[i];
}
inline void af() {
  long long w[9];
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      w[i] = w[i] + (a[j] * f[j][i]) % p;
      w[i] %= p;
    }
  for (int i = 1; i <= 3; i++) a[i] = w[i];
}
int main() {
  scanf("%d%I64d%I64d%I64d", &n, &x, &y, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &ww[i]);
  tot = 0;
  for (int i = 1; i <= n; i++) tot += ww[i];
  a[1] = tot % p;
  a[2] = ww[1];
  a[3] = ww[n] % p;
  f[1][1] = 3;
  f[2][1] = p - 1;
  f[3][1] = p - 1;
  f[1][2] = 0;
  f[2][2] = 1;
  f[3][2] = 0;
  f[1][3] = 0;
  f[2][3] = 0;
  f[3][3] = 1;
  long long xx = x;
  while (x) {
    if (x & 1) af();
    x >>= 1;
    ff();
  }
  e[1] = 1;
  e[2] = 1;
  Ff[1][1] = 0;
  Ff[1][2] = 1;
  Ff[2][1] = 1;
  Ff[2][2] = 1;
  long long xxx = xx;
  xxx--;
  while (xxx > 0) {
    if (xxx & 1) ef();
    xxx >>= 1;
    fff();
  }
  if (xx != 0)
    a[3] = (ww[n] * (e[2] % p) + ww[n - 1] * (e[1] % p)) % p;
  else
    a[3] = ww[n] % p;
  f[1][1] = 3;
  f[2][1] = p - 1;
  f[3][1] = p - 1;
  f[1][2] = 0;
  f[2][2] = 1;
  f[3][2] = 0;
  f[1][3] = 0;
  f[2][3] = 0;
  f[3][3] = 1;
  while (y) {
    if (y & 1) af();
    y >>= 1;
    ff();
  }
  printf("%I64d\n", a[1] % p);
}
