#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
char n[101];
int len;
long long f[2][2][101][10][10][1 << 4][1 << 4];
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int calc(int a, int b) {
  if (a == 1 && b == 1) {
    long long ret = 0;
    for (int i = 0; n[i]; i++) ret = (ret * 10 + n[i] - '0') % MOD;
    return ret;
  }
  int px[10], py[10], pn = 0;
  for (int i = 0; i < 10; i++) px[i] = py[i] = 0;
  for (int tx = a, ty = b; tx < 10 && ty < 10; tx += a, ty += b, pn++)
    px[tx] = 1 << pn, py[ty] = 1 << pn;
  memset(f, 0, sizeof(f));
  f[0][0][0][0][0][0][0] = 1;
  f[0][1][0][0][0][0][0] = 1;
  f[1][0][0][0][0][0][0] = 1;
  f[1][1][0][0][0][0][0] = 1;
  int TS = (1 << pn);
  for (int i = 0; i < len; i++) {
    int d = n[len - i - 1] - '0';
    for (int p = 0; p < a; p++) {
      for (int q = 0; q < b; q++) {
        for (int X = 0; X < TS; X++) {
          for (int Y = 0; Y < TS; Y++) {
            for (int cx = 0; cx <= 1; cx++) {
              for (int cy = 0; cy <= 1; cy++) {
                f[cx][cy][i][p][q][X][Y] %= MOD;
              }
            }
            for (int k = 0; k <= 9; k++) {
              int A = p + a * k, B = q + b * k;
              int Al = A % 10, Bl = B % 10;
              f[0][0][i + 1][A / 10][B / 10][X | px[Al]][Y | py[Bl]] +=
                  f[0][0][i][p][q][X][Y];
              if (Al <= d)
                f[1][0][i + 1][A / 10][B / 10][X | px[Al]][Y | py[Bl]] +=
                    f[Al == d][0][i][p][q][X][Y];
              if (Bl <= d)
                f[0][1][i + 1][A / 10][B / 10][X | px[Al]][Y | py[Bl]] +=
                    f[0][Bl == d][i][p][q][X][Y];
              if (Al <= d && Bl <= d)
                f[1][1][i + 1][A / 10][B / 10][X | px[Al]][Y | py[Bl]] +=
                    f[Al == d][Bl == d][i][p][q][X][Y];
            }
          }
        }
      }
    }
  }
  long long ret = 0;
  for (int X = 0; X < TS; X++)
    for (int Y = 0; Y < TS; Y++) {
      (ret += X & Y ? f[1][1][len][0][0][X][Y] % MOD : 0) %= MOD;
    }
  return ret;
}
int main() {
  scanf("%s", n);
  len = strlen(n);
  long long ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (gcd(i, j) != 1) continue;
      ans += calc(i, j);
    }
  }
  printf("%d\n", int(ans % MOD));
  return 0;
}
