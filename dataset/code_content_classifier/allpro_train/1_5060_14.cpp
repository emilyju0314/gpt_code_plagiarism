#include <bits/stdc++.h>
using namespace std;
const int N = 8;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
struct matric {
  long long val[(1 << N)][(1 << N)];
};
int a[N];
matric mas[N][20];
long long G[N][(1 << N)];
matric art(matric &A, matric &B, int n) {
  matric answ;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      answ.val[i][j] = 0;
      for (int h = 0; h < n; h++) {
        answ.val[i][j] += (A.val[i][h] * B.val[h][j]) % mod;
        answ.val[i][j] %= mod;
      }
    }
  }
  return answ;
}
matric binpow(int i, int n, int sz) {
  matric pat;
  bool flag = false;
  for (int j = 16; j >= 0; j--) {
    if (((n >> j) & 1) == 0) continue;
    if (flag)
      pat = art(pat, mas[i][j], sz);
    else
      pat = mas[i][j];
    flag = true;
  }
  return pat;
}
int main() {
  int n = 7;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << i); j++) {
      for (int h = 0; h < (1 << i); h++) {
        long long a = 0, b = 1;
        for (int t = 1; t <= i; t++) {
          long long c, d;
          c = (a + b) % mod;
          if (((j >> (t - 1)) & 1) && ((h >> (t - 1)) & 1))
            d = a;
          else
            d = (a + b) % mod;
          a = c;
          b = d;
        }
        mas[i][0].val[j][h] = b;
      }
    }
    for (int j = 1; j <= 16; j++) {
      mas[i][j] = art(mas[i][j - 1], mas[i][j - 1], (1 << i));
    }
  }
  int sz = 0;
  int ss = 0;
  long long answ;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    if (sz == 0)
      G[i][(1 << i) - 1] = 1;
    else {
      int delta = 0;
      for (int j = ss; j < i; j++) delta += (1 << j);
      for (int j = 0; j < (1 << ss); j++) G[i][j + delta] = G[ss][j];
    }
    sz = (1 << i);
    ss = i;
    matric P = binpow(i, a[i], sz);
    long long massive[(1 << N)];
    for (int j = 0; j < sz; j++) {
      massive[j] = 0;
      for (int h = 0; h < sz; h++) {
        massive[j] += (G[i][h] * P.val[h][j]) % mod;
        massive[j] %= mod;
      }
    }
    for (int j = 0; j < sz; j++) G[i][j] = massive[j];
    answ = G[i][sz - 1];
  }
  cout << answ << endl;
  return 0;
}
