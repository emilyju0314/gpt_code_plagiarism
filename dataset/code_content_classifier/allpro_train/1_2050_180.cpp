#include <bits/stdc++.h>
using namespace std;
long long modd = 1e9 + 7;
const int N = 700 + 9;
char s[N];
int num[N];
long long dp[N][12][N][2];
long long pw10[N];
int n;
void add(long long& x, long long y) { x = (x + y) % modd; }
long long solve() {
  pw10[0] = 1;
  for (int i = 1; i <= n; ++i) pw10[i] = pw10[i - 1] * 10 % modd;
  for (int i = 1; i <= n; ++i) num[i] = s[i] - '0';
  for (int k = 0; k <= 9; ++k) {
    dp[0][k][0][1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int k = 1; k <= 9; ++k) {
      for (int j = 0; j <= i; ++j) {
        for (int fg = 0; fg <= 1; ++fg) {
          int lim = fg ? num[i + 1] : 9;
          for (int p = 0; p <= lim; ++p) {
            int tj = j;
            if (p >= k) ++tj;
            add(dp[i + 1][k][tj][fg && p == lim], dp[i][k][j][fg]);
          }
        }
      }
    }
  }
  long long res = 0;
  for (int k = 1; k <= 9; ++k) {
    long long tem = 1;
    for (int i = 1; i <= n; ++i) {
      res =
          (res + (dp[n][k][i][0] + dp[n][k][i][1]) % modd * tem % modd) % modd;
      tem = (tem * 10 + 1) % modd;
    }
  }
  return res;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  printf("%lld", solve());
  return 0;
}
