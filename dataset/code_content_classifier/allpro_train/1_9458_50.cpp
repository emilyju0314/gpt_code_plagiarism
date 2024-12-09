#include <bits/stdc++.h>
using namespace std;
vector<pair<int, string> > ans, rans;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int cnt = 4 * n * m - 2 * n - 2 * m;
  if (cnt < k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (m > 1) ans.push_back({m - 1, "R"});
    if (m > 1) ans.push_back({m - 1, "L"});
    ans.push_back({1, "D"});
  }
  if (m > 1) ans.push_back({m - 1, "R"});
  for (int i = 1; i < m; ++i) {
    if (n > 1) ans.push_back({n - 1, "U"});
    if (n > 1) ans.push_back({n - 1, "D"});
    ans.push_back({1, "L"});
  }
  if (n > 1) ans.push_back({n - 1, "U"});
  for (int i = 0; i < ans.size(); ++i) {
    if (cnt + ans[i].first >= k) {
      rans.push_back({k - cnt, ans[i].second});
      break;
    }
    rans.push_back(ans[i]);
    cnt += ans[i].first;
  }
  cout << rans.size() << endl;
  for (int i = 0; i < rans.size(); ++i)
    cout << rans[i].first << ' ' << rans[i].second << endl;
}
