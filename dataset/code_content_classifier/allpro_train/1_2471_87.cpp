#include <bits/stdc++.h>
using namespace std;
const int MAX = 31, M = 201;
double dp[M][MAX][MAX], u, ans;
int n, m, a[MAX];
int rev(int x, int a, int b) {
  if (x >= a && x <= b) x = a + b - x;
  return x;
}
int main() {
  cin >> n >> m, u = 2.0 / n / (n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; ++j) dp[0][i][j] = 1;
  for (int t = 1; t <= m; t++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j)
          for (int a = 0; a < n; ++a)
            for (int b = a; b < n; ++b)
              dp[t][i][j] += u * dp[t - 1][rev(i, a, b)][rev(j, a, b)];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans += a[i] > a[j] ? dp[m][i][j] : 1 - dp[m][i][j];
  cout << fixed << setprecision(10) << ans << endl;
}
