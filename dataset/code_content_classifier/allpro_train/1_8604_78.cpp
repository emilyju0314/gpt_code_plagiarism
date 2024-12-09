#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ans;
  for (int i = 0; i < m; i++) ans.emplace_back(1, i + 1);
  for (int i = 1; i < n; i++) ans.emplace_back(i + 1, 1);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  return 0;
}
