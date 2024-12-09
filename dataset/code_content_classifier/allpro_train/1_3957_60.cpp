#include <bits/stdc++.h>
using namespace std;
const int N = 504;
int dp[N][N], minim[N][N];
int sump[N];
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  string s;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      sump[j] = sump[j - 1] + (s[j - 1] == '1');
      minim[i][j] = 1e9 + 7;
    }
    minim[i][0] = 1e9 + 7;
    minim[i][sump[m]] = 0;
    for (int a = 0; a <= m; ++a)
      for (int b = a + 1; b <= m; ++b)
        minim[i][sump[a] + sump[m] - sump[b]] =
            min(minim[i][sump[a] + sump[m] - sump[b]], b - a);
  }
  int ans(1e9 + 7);
  for (int i = 1; i <= n; ++i) {
    for (int lipsa = 0; lipsa <= k; ++lipsa) {
      dp[i][lipsa] = 1e9 + 7;
      for (int azi = 0; azi <= m && azi <= lipsa; ++azi)
        dp[i][lipsa] =
            min(dp[i][lipsa], dp[i - 1][lipsa - azi] + minim[i][azi]);
      if (i == n) ans = min(ans, dp[i][lipsa]);
    }
  }
  cout << ans;
  return 0;
}
