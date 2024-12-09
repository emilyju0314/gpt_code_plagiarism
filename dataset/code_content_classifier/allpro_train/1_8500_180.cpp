#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  vector<int> d(n);
  set<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert({0, i});
  }
  int ans = 0;
  vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    pair<int, int> now = *s.begin();
    used[now.second] = true;
    s.erase(s.begin());
    if (now.first == i) {
      ++ans;
    }
    for (int j : a[now.second]) {
      if (used[j]) {
        continue;
      }
      s.erase({d[j], j});
      ++d[j];
      s.insert({d[j], j});
    }
  }
  cout << ans - 1;
  return 0;
}
