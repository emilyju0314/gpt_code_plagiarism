#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    vector<int> b(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
      mp[a[i]].push_back(i);
    }
    map<int, int> dp;
    int ans = 0;
    for (auto c : mp) {
      dp[c.first] = mp[c.first].size();
      if (!mp[c.first - 1].empty() and mp[c.first - 1].back() < mp[c.first][0])
        dp[c.first] = dp[c.first - 1] + dp[c.first];
      int cnt = 0;
      for (auto d : mp[c.first - 1]) {
        if (d < mp[c.first][0]) cnt++;
      }
      dp[c.first] = max(dp[c.first], cnt + (int)mp[c.first].size());
      ans = max(ans, dp[c.first]);
      cnt = 0;
      for (auto d : mp[c.first]) {
        if (!mp[c.first - 1].empty() and d > mp[c.first - 1].back()) cnt++;
      }
      ans = max(ans, dp[c.first - 1] + cnt);
      vector<pair<int, int>> pr;
      for (auto it : mp[c.first - 1]) pr.push_back({it, 0});
      for (auto it : mp[c.first]) pr.push_back({it, 1});
      sort(pr.begin(), pr.end());
      int c1 = 0, c2 = 0;
      for (auto d : pr) {
        if (d.second == 0)
          c1++;
        else
          c2++;
        c2 = max(c2, c1);
      }
      ans = max(ans, c2);
    }
    n = n - ans;
    cout << n << endl;
  }
  return 0;
}
