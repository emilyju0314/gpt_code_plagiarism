#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const long long mod = 1e9 + 7;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
int a[201];
int dp[201][201][1001];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    sort(a + 1, a + n + 1);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        int t = j * (a[i] - a[i - 1]);
        for (int k = 0; k <= m - t; k++) {
          dp[i][j][k + t] =
              (dp[i][j][k + t] + (long long)dp[i - 1][j][k] * (j + 1) % mod) %
              mod;
          if (j > 0)
            dp[i][j - 1][k + t] =
                (dp[i][j - 1][k + t] + (long long)dp[i - 1][j][k] * j % mod) %
                mod;
          dp[i][j + 1][k + t] = (dp[i][j + 1][k + t] + dp[i - 1][j][k]) % mod;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = (ans + dp[n][0][i]) % mod;
    cout << ans << endl;
  }
  return 0;
}
