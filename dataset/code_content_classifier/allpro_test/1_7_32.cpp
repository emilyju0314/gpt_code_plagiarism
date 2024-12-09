#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long mod = 998244353;
int n, m;
string a, b;
void prefix_func(string &s, vector<int> &v) {
  int n = s.size();
  v.assign(n, 0);
  for (int i = 1; i < n; i++) {
    int j = v[i - 1];
    while (j >= 0 && s[j] != s[i]) {
      j = j == 0 ? -1 : v[j - 1];
    }
    v[i] = j + 1;
  }
}
void solve() {
  cin >> n >> m;
  cin >> a >> b;
  vector<int> v;
  prefix_func(b, v);
  int mx = n - m + 1;
  vector<int> va(n);
  int cnt = 0;
  vector<vector<vector<int> > > dp(
      2, vector<vector<int> >(m + 1, vector<int>(mx + 1, 1000)));
  int x = 0;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    x ^= 1;
    vector<vector<int> > jfin(m, vector<int>(2, -1));
    for (int j = 0; j < m; j++) {
      for (int cnt = 0; cnt <= mx; cnt++) {
        dp[x][j][cnt] = 1000;
      }
    }
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        jfin[j][0] = j + 1;
        jfin[j][1] = j == 0 ? 0 : jfin[v[j - 1]][1];
      } else {
        jfin[j][1] = j + 1;
        jfin[j][0] = j == 0 ? 0 : jfin[v[j - 1]][0];
      }
    }
    for (int j = 0; j < m; j++) {
      for (int cnt = 0; cnt < mx; cnt++) {
        if (dp[x ^ 1][j][cnt] == 1000) continue;
        int cr1 = jfin[j][0], cr2 = jfin[j][1];
        if (cr1 == m) {
          cr1 = v[cr1 - 1];
        }
        if (cr2 == m) {
          cr2 = v[cr2 - 1];
        }
        dp[x][cr1][cnt + (jfin[j][0] == m)] =
            min(dp[x][cr1][cnt + (jfin[j][0] == m)], dp[x ^ 1][j][cnt]);
        dp[x][cr2][cnt + (jfin[j][1] == m)] =
            min(dp[x][cr2][cnt + (jfin[j][1] == m)], 1 + dp[x ^ 1][j][cnt]);
      }
    }
  }
  vector<int> ans(n - m + 2, -1);
  for (int j = 0; j < m; j++) {
    for (int cnt = 0; cnt <= mx; cnt++) {
      if (dp[x][j][cnt] == 1000) continue;
      ans[cnt] = ans[cnt] == -1 ? dp[x][j][cnt] : min(ans[cnt], dp[x][j][cnt]);
    }
  }
  for (int i = (int)0; i != (int)n - m + 2; i = i + 1) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
