#include <bits/stdc++.h>
using namespace std;
const int M = 101;
int n, m;
long long K;
char c[M * 2];
struct Prior {
  int i, minval;
} p[M * 2];
void inc(long long& x, long long y) {
  x += y;
  if (x > K) x = K;
}
long long cal() {
  long long dp[2][M] = {0};
  dp[0][0] = 1;
  for (int i = 1; i <= n + m - 1; i++) {
    int now = i & 1, pre = 1 - now;
    memset(dp[now], 0, sizeof dp[now]);
    for (int j = 0; j <= (n + m - 1) / 2; j++) {
      if (c[i] != ')' && j > 0) inc(dp[now][j], dp[pre][j - 1]);
      if (c[i] != '(' && j + 1 <= (n + m - 1) / 2)
        inc(dp[now][j], dp[pre][j + 1]);
    }
  }
  return dp[(n + m - 1) & 1][0];
}
int main() {
  scanf("%d%d%I64d", &n, &m, &K);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      if (p[i + j - 1].minval == 0 || p[i + j - 1].minval > x) {
        p[i + j - 1].minval = x;
      }
      p[i + j - 1].i = i + j - 1;
    }
  }
  sort(p + 1, p + n + m, [&](Prior a, Prior b) { return a.minval < b.minval; });
  for (int i = 1; i <= n + m - 1; i++) {
    int pos = p[i].i;
    c[pos] = '(';
    long long num = cal();
    if (num < K) {
      c[pos] = ')';
      K -= num;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%c", c[i + j - 1]);
    }
    puts("");
  }
}
