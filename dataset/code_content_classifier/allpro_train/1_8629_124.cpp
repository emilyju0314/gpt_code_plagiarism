#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
#pragma warning(disable : 4996)
using namespace std;
const int M = 1005, N = 55, mod = 1e9 + 7;
bitset<M> c[N];
long long int dp[M][M];
bool us[M];
int main() {
  dp[0][0] = 1;
  for (int i = 1; i < M; i++) {
    for (int j = 1; j < M; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % mod;
    }
  }
  int m, n;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      scanf(" %c", &a);
      c[i][j] = a - '0';
    }
  }
  long long int ans = 1;
  for (int i = 0; i < m; i++) {
    if (us[i]) continue;
    bitset<M> r;
    for (int j = 0; j < m; j++) r[j] = 1;
    for (int j = 0; j < n; j++) {
      r &= c[j][i] ? c[j] : ~c[j];
    }
    for (int j = 0; j < m; j++) {
      if (r[j]) us[j] = 1;
    }
    long long int t = 0, ct = r.count();
    for (int j = 0; j <= ct; j++) t = (t + dp[ct][j]) % mod;
    ans = ans * t % mod;
  }
  printf("%lld", ans);
  return 0;
}
