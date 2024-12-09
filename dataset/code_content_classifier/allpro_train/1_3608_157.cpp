#include <bits/stdc++.h>
using namespace std;
const int B = 100010;
int f[B], rev[B], P, N, p[20], cnt, num[B][20];
int qpow(int a, int x) {
  int res = 1;
  while (x) {
    if (x & 1) res = (long long)res * a % P;
    a = (long long)a * a % P;
    x >>= 1;
  }
  return res;
}
void solve() {
  int phi = P, tp = P;
  f[0] = rev[0] = 1;
  for (int i = 2; i <= tp / i; i++) {
    if (tp % i == 0) {
      p[++cnt] = i;
      phi = phi / i * (i - 1);
      while (tp % i == 0) tp /= i;
    }
  }
  if (tp > 1) phi = phi / tp * (tp - 1), p[++cnt] = tp;
  for (int i = 1; i <= N; i++) {
    int x = i;
    for (int j = 1; j <= cnt; j++) {
      num[i][j] = num[i - 1][j];
      while (x % p[j] == 0) num[i][j]++, x /= p[j];
    }
    f[i] = (long long)f[i - 1] * x % P;
    rev[i] = qpow(f[i], phi - 1);
  }
}
int C(int x, int y) {
  if (y < 0) return 0;
  int res = 1;
  res = (long long)f[x] * rev[y] % P * rev[x - y] % P;
  for (int i = 1; i <= cnt; i++)
    res =
        (long long)res * qpow(p[i], num[x][i] - num[y][i] - num[x - y][i]) % P;
  return res;
}
int main() {
  int L, R, ans = 0;
  scanf("%d%d%d%d", &N, &P, &L, &R);
  R = min(N, R);
  solve();
  for (int i = 0; i <= N - L; i++)
    ans = (ans +
           1LL * (C(N - i, (N - i - L) >> 1) - C(N - i, (N - i - R - 1) >> 1)) *
               C(N, i)) %
          P;
  printf("%d\n", ans);
  return 0;
}
