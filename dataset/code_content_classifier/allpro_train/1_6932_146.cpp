#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
int n;
int a[maxn], s[maxn][maxn];
map<int, vector<pair<int, int>>> m;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    s[i][i] = a[i];
    m[a[i]].push_back({i, i});
    for (int j = i + 1; j < n; j++) {
      s[i][j] = s[i][j - 1] + a[j];
      m[s[i][j]].push_back({i, j});
    }
  }
  auto f = [](const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
  };
  vector<pair<int, int>> ans;
  for (auto item : m) {
    sort(item.second.begin(), item.second.end(), f);
    int ed = -1;
    vector<pair<int, int>> v;
    for (auto seg : item.second) {
      if (seg.first <= ed) continue;
      v.push_back({seg});
      ed = seg.second;
    }
    if (v.size() > ans.size()) ans = v;
  }
  cout << ans.size() << "\n";
  for (auto item : ans) {
    cout << item.first + 1 << " " << item.second + 1 << "\n";
  }
  return 0;
}
