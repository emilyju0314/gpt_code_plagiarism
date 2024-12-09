#include <bits/stdc++.h>
using namespace std;
int n;
int _hash[5050], p[5050];
int dp[5050][5050], sum[5050], v[5050];
bool x[5050][5050];
char s[5050];
int f(int x) {
  if (x >= 1000000007)
    return x - 1000000007;
  else
    return x;
}
bool bigger(int x1, int y1, int x2, int y2) {
  int pos = 0;
  int l = 1;
  int r = (y1 - x1 + 1);
  while (l <= r) {
    int m = (l + r) / 2;
    int hash1 = _hash[x1 + m - 1] - (1LL * _hash[x1 - 1] * p[m]) % 1000000007;
    int hash2 = _hash[x2 + m - 1] - (1LL * _hash[x2 - 1] * p[m]) % 1000000007;
    if (hash1 < 0) hash1 += 1000000007;
    if (hash2 < 0) hash2 += 1000000007;
    if (hash1 == hash2) {
      pos = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  if (pos + 1 > (y1 - x1 + 1)) return false;
  return s[x2 + pos] > s[x1 + pos];
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = (1LL * p[i - 1] * 666013) % 1000000007;
  for (int i = 1; i <= n; i++)
    _hash[i] = (1LL * _hash[i - 1] * 666013 + s[i]) % 1000000007;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j++)
      x[i][j] = bigger(j - 2 * i + 1, j - i, j - i + 1, j);
  }
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) sum[i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; s[i] != '0' && i + j - 1 <= n; j++) {
      int pos = i + j - 1;
      dp[j][pos] = sum[j - 1];
      if (x[j][pos]) dp[j][pos] = f(dp[j][pos] + dp[j][i - 1]);
    }
    sum[0] = dp[0][i];
    for (int j = 1; j <= n; j++) sum[j] = f(dp[j][i] + sum[j - 1]);
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) sol = f(sol + dp[i][n]);
  printf("%d", sol);
  return 0;
}
