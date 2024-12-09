#include <bits/stdc++.h>
using namespace std;
map<int, int> chosen;
map<int, set<int>> flowers;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m, k, n, s;
  cin >> m >> k >> n >> s;
  for (int i = 0; i < m; i++) {
    int fl;
    cin >> fl;
    flowers[fl].insert(i);
  }
  for (int i = 0; i < s; i++) {
    int b;
    cin >> b;
    chosen[b]++;
  }
  for (int i = 0; i < k * n; i += k) {
    int last = -1;
    bool ok = true;
    set<int> se;
    for (auto aa : chosen) {
      int pos = i - 1;
      for (int j = 0; j < (aa.second); ++j) {
        auto it = flowers[aa.first].upper_bound(pos);
        if (it == flowers[aa.first].end()) {
          ok = false;
          break;
        }
        pos = *it;
        se.insert(pos);
        last = max(last, pos);
      }
    }
    if (ok && i / k + (m - last - 1) / k >= n - 1) {
      int del = k - s;
      vector<int> ans;
      for (int j = i; j < last; j++) {
        if (se.find(j) == se.end()) {
          if (del == 0)
            ans.push_back(j);
          else
            del--;
        }
      }
      cout << ans.size() << "\n";
      for (int x : ans) cout << x + 1 << " ";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
