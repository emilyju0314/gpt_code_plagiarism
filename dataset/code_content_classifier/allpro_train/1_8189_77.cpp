#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long long dp[4000][4000];
long long mn[4000][4000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  set<long long> uss;
  long long a[n];
  long long b[n];
  long long sm = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] - i;
    uss.insert(a[i]);
  }
  vector<long long> us;
  for (auto i : uss) {
    us.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < us.size(); j++) {
      dp[i + 1][j] = mn[i][j] + abs(us[j] - a[i]);
      mn[i + 1][j] = dp[i + 1][j];
      if (j) mn[i + 1][j] = min(mn[i + 1][j], mn[i + 1][j - 1]);
    }
  }
  cout << mn[n][us.size() - 1];
}
