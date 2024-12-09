#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 12;
const int MOD = 998244353;
int n, q, d, m, x[maxn + 3], a[maxn + 3], l[maxn + 3], r[maxn + 3],
    dp[5003][5003];
int dem[maxn + 3];
int t, k;
string second[2003];
map<long long, long long> w;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n;
  vector<int> chot, c;
  for (int i = 1; i <= n; i++) {
    cin >> d;
    if (chot.empty() || d != chot.back()) chot.push_back(d);
  }
  c = chot;
  reverse(chot.begin(), chot.end());
  n = chot.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (chot[i] == c[j]));
      dp[i + 1][j + 1] = max({dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j]});
    }
  int ans = 0;
  for (int i = 0; i <= n; ++i) ans = max(ans, dp[i][n - i]);
  cout << n - 1 - ans;
}
