#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n), cnt(101, 0);
  for (auto& x : v) cin >> x, ++cnt[x];
  int D, mx{0};
  bool flag;
  for (int i{0}; i < static_cast<int>(cnt.size()); ++i)
    if (mx < cnt[i])
      mx = cnt[i], D = i, flag = false;
    else if (mx == cnt[i])
      flag = true;
  if (flag) {
    cout << n << '\n';
    return;
  }
  int ans{};
  for (int V{1}; V <= 100; ++V) {
    unordered_map<int, int> presum{};
    presum.emplace(0, 0);
    if (V == D) continue;
    int ps{0};
    for (int i{0}; i < n; ++i) {
      if (v[i] == D) ++ps;
      if (v[i] == V) --ps;
      auto it{presum.find(ps)};
      if (it != presum.end())
        ans = max(ans, i + 1 - (it->second));
      else
        presum.emplace(ps, i + 1);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t{1};
  while (t--) solve();
  return 0;
}
