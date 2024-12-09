#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20 * 1000 + 1;
int a[MAXN];
int b[MAXN];
int n, m, p;
const int sq = 130;
long long int* dp[MAXN];
inline int gt(int x, int y) { return (a[x] + b[y]) % p; }
inline void upd(int i, int j) {
  long long int ans = 0;
  if (j) ans = dp[i][j - 1];
  if (i && dp[i - 1][j] > ans) ans = dp[i - 1][j];
  ans += gt(i, j);
  dp[i][j] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) {
    dp[i] = new long long int[MAXN];
    for (int j = 0; j < m; j++) upd(i, j);
    if (i && (i - 1) % sq) {
      delete dp[i - 1];
      dp[i - 1] = NULL;
    }
  }
  long long int ans = dp[n - 1][m - 1];
  cout << ans << endl;
  string path;
  int px = n - 1, py = m - 1;
  while (px || py) {
    if (!dp[px]) {
      for (int i = px + 1; dp[i]; i++) {
        delete dp[i];
        dp[i] = NULL;
      }
      for (int i = (px / sq) * sq + 1; i <= px; i++) {
        dp[i] = new long long int[MAXN];
        for (int j = 0; j <= py; j++) upd(i, j);
      }
    }
    ans -= gt(px, py);
    if (py && dp[px][py - 1] == ans)
      path += "S", py--;
    else
      path += "C", px--;
  }
  reverse((path).begin(), (path).end());
  cout << path << endl;
  return 0;
}
