#include <bits/stdc++.h>
using namespace std;
long long a[100005];
double dp[100005][105];
double comb(int n, int r) {
  double ans = 1.0;
  for (int i = n - r + 1; i <= n; ++i) ans = (ans * (1.0 * i));
  for (int i = 1; i <= r; ++i) ans = (ans / (1.0 * i));
  return ans;
}
long long b[100005];
double Ans[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    b[i] = a[i];
    dp[i][a[i]] = 1.0;
    if (a[i] == 0) Ans[0] += 1.0;
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k);
    double temp[105];
    for (int j = 0; j <= a[u]; ++j) temp[j] = 0;
    for (int j = a[u]; j >= 0; --j) {
      for (int l = 0; l <= min(k, j); ++l) {
        int qw = b[u] - j;
        int qe = qw - (k - l);
        if (qw < 0) continue;
        if (qe < 0) continue;
        double ans = comb(j, l) * comb(qw, k - l);
        ans = ans / (1.0 * comb(b[u], k));
        temp[j - l] = temp[j - l] + dp[u][j] * ans;
      }
    }
    Ans[i] = Ans[i - 1];
    Ans[i] -= dp[u][0];
    for (int j = 0; j <= a[u]; ++j) dp[u][j] = temp[j];
    Ans[i] += dp[u][0];
    b[v] += k;
    b[u] -= k;
    printf("%.9f\n", Ans[i]);
  }
  return 0;
}
