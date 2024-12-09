#include <bits/stdc++.h>
using namespace std;
int C[4005 + 5][4005 + 5];
void init() {
  memset(C, 0, sizeof(C));
  for (int i = 0; i < 4005 + 1; i++) C[i][i] = C[i][0] = 1;
  for (int i = 2; i <= 4005; ++i)
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
}
bool used[4005 + 5];
int memo[4005 + 5];
int dp(int n) {
  if (n == 0) return 1;
  if (used[n]) return memo[n];
  used[n] = 1;
  int &dev = memo[n] = 0;
  for (int k = 0; k < n; ++k)
    dev = (dev + (long long)C[n - 1][k] * (long long)dp(k)) % 1000000007;
  return dev;
}
int main() {
  init();
  int n;
  while (scanf("%d", &n) == 1) {
    long long ans = 0;
    for (int u = 1; u <= n; ++u)
      ans = (ans + (long long)C[n][u] * (long long)dp(n - u)) % 1000000007;
    cout << ans << '\n';
  }
}
