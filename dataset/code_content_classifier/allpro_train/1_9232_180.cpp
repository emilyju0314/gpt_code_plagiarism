#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
void read() { freopen("in", "r", stdin); }
int A[33], B[33], C[33];
long long dp[33][2][2][2], sum[33][2][2][2];
long long query(int x, int y, int z) {
  if (x < 0 || y < 0 || z < 0) return 0;
  for (int i = 0; i <= 31; i++) {
    A[i] = (x >> (31 - i)) & 1;
    B[i] = (y >> (31 - i)) & 1;
    C[i] = (z >> (31 - i)) & 1;
  }
  memset(dp, 0, sizeof dp);
  memset(sum, 0, sizeof sum);
  dp[0][1][1][1] = 1;
  for (int i = 0; i < 32; i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          long long val = dp[i][a][b][c];
          long long s = sum[i][a][b][c];
          for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
              int z = x ^ y;
              if (A[i] == 0 && a == 1 && x == 1) continue;
              if (B[i] == 0 && b == 1 && y == 1) continue;
              if (C[i] == 0 && c == 1 && z == 1) continue;
              dp[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)] +=
                  val;
              dp[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)] %=
                  mod;
              sum[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)] +=
                  s;
              sum[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)] +=
                  (1ll * (z << (31 - i)) * val % mod);
              sum[i + 1][a & (A[i] == x)][b & (B[i] == y)][c & (C[i] == z)] %=
                  mod;
            }
          }
        }
      }
    }
  }
  long long ret = 0;
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      for (int c = 0; c < 2; c++) ret += dp[32][a][b][c] + sum[32][a][b][c];
  ret %= mod;
  return ret;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int x1, x2, y1, y2, k;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    long long ans = 0;
    x2--, y2--, x1--, y1--, k--;
    ans += query(x2, y2, k);
    ans += query(x1 - 1, y1 - 1, k);
    ans -= query(x2, y1 - 1, k);
    ans -= query(x1 - 1, y2, k);
    ans %= mod;
    ans += mod;
    ans %= mod;
    printf("%lld\n", ans);
  }
  return 0;
}
