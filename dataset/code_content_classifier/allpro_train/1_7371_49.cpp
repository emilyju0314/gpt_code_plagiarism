#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    ++cnt[val];
  }
  vector<int> cntOfCnts(n + 1, 0);
  for (auto &p : cnt) {
    for (int i = 1; i <= p.second; ++i) {
      ++cntOfCnts[i];
    }
  }
  for (int i = 2; i <= n; ++i) {
    cntOfCnts[i] += cntOfCnts[i - 1];
  }
  pair<int, int> res = {1, 1};
  for (int len = 1; len <= n && len <= cnt.size(); ++len) {
    for (int width = 1; 1LL * width * len <= n && width <= cnt.size();
         ++width) {
      if (cntOfCnts[min(len, width)] >= len * width) {
        if (res.first * res.second < len * width) {
          res.first = len;
          res.second = width;
        }
      }
    }
  }
  if (res.first > res.second) swap(res.first, res.second);
  vector<vector<int>> val_by_cnt(n + 1);
  for (auto p : cnt) {
    val_by_cnt[p.second].push_back(p.first);
  }
  cout << res.first * res.second << '\n'
       << res.first << " " << res.second << '\n';
  vector<vector<int>> ans(res.first, vector<int>(res.second));
  int x = 0, y = 0;
  for (int i = n; i >= 1; i--)
    for (auto val : val_by_cnt[i])
      for (int j = 0; j < min(i, res.first); ++j) {
        if (ans[x][y] != 0) x = (x + 1) % res.first;
        if (ans[x][y] == 0) ans[x][y] = val;
        x = (x + 1) % res.first;
        y = (y + 1) % res.second;
      }
  for (int i = 0; i < res.first; ++i) {
    for (int j = 0; j < res.second; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
}
