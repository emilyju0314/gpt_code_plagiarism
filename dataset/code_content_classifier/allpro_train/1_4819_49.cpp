#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
int n, m;
long long dp[1ll << 23];
vector<int> v[23];
long long go(long long msk) {
  long long all1 = 1ll << n;
  all1--;
  if (msk == all1) return 0;
  if (dp[msk] != -1) return dp[msk];
  long long ans = n + 1;
  for (int i = 0; i < n; i++) {
    if (msk == 0 || (msk & 1 << i)) {
      int newmsk = msk;
      newmsk |= 1 << i;
      for (int j = 0; j < v[i].size(); j++) {
        newmsk |= 1 << v[i][j];
      }
      if (newmsk != msk) ans = min(ans, go(newmsk) + 1);
    }
  }
  return dp[msk] = ans;
}
void trace(long long msk) {
  long long all1 = 1ll << n;
  all1--;
  if (msk == all1) return;
  long long ans = go(msk);
  for (int i = 0; i < n; i++) {
    if (msk == 0 || (msk & 1 << i)) {
      int newmsk = msk;
      newmsk |= 1 << i;
      for (int j = 0; j < v[i].size(); j++) {
        newmsk |= 1 << v[i][j];
      }
      if (newmsk != msk) {
        if (ans == 1 + go(newmsk)) {
          cout << i + 1 << " ";
          trace(newmsk);
          return;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if (m == (n * (n - 1) / 2)) {
    cout << 0 << "\n";
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  long long ans = go(0);
  cout << ans << "\n";
  trace(0);
  cout << endl;
  return 0;
}
