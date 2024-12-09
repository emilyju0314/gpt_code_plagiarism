#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long int INF = LLONG_MAX;
const long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k, z;
    cin >> n >> k >> z;
    vector<long long int> a(n);
    for (long long int i = 0; i <= n - 1; i++) cin >> a[i];
    vector<long long int> suma(n);
    suma[0] = a[0];
    for (long long int i = 1; i <= n - 1; i++) suma[i] = a[i] + suma[i - 1];
    vector<vector<long long int> > dp(n, vector<long long int>(z + 1, -1));
    for (long long int i = 0; i <= n - 1; i++) dp[i][0] = suma[i];
    long long int ans = dp[k][0];
    for (long long int i = 1; i <= z; i++) {
      for (long long int j = 0; j <= n - 1; j++) {
        if (j + 1 < n) dp[j][i] = max(dp[j][i], a[j] + dp[j + 1][i - 1]);
        if (j - 1 >= 0) dp[j][i] = max(dp[j][i], a[j] + dp[j - 1][i]);
        if (j > k - 2 * i) continue;
        ans = max(ans, dp[j][i]);
      }
    }
    cout << ans << endl;
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
