#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int out = 0, fh = 1;
  char jp = getchar();
  while ((jp > '9' || jp < '0') && jp != '-') jp = getchar();
  if (jp == '-') fh = -1, jp = getchar();
  while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
  return out * fh;
}
void print(int x) {
  if (x >= 10) print(x / 10);
  putchar('0' + x % 10);
}
void write(int x, char c) {
  if (x < 0) putchar('-'), x = -x;
  print(x);
  putchar(c);
}
const int P = 1e9 + 7;
int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
void inc(int &a, int b) { a = add(a, b); }
int mul(int a, int b) { return 1LL * a * b % P; }
const int N = 1e5 + 10, K = 350;
int n, m, x, dp[2][K][K], id;
int main() {
  n = read(), m = read(), x = read();
  if (n > m) return puts("0"), 0;
  dp[id = 0][0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n; ++j)
      for (int k = 0; j + k <= n; ++k) dp[id ^ 1][j][k] = 0;
    for (int j = 0; j <= n; ++j)
      for (int k = 0; j + k <= n; ++k)
        if (dp[id][j][k]) {
          if (i != x) inc(dp[id ^ 1][j][k], dp[id][j][k]);
          if (j + k + 1 <= n) inc(dp[id ^ 1][j + 1][k], dp[id][j][k]);
          if (i != x && j && k < n) inc(dp[id ^ 1][j - 1][k + 1], dp[id][j][k]);
          if (j + k + 1 <= n) inc(dp[id ^ 1][j][k + 1], dp[id][j][k]);
        }
    id ^= 1;
  }
  int ans = dp[id][0][n];
  for (int i = 2; i <= n; ++i) ans = mul(ans, i);
  write(ans, '\n');
  return 0;
}
