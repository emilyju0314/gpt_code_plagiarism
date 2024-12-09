#include <bits/stdc++.h>
using namespace std;
const bool debug = false;
const int maxn = 2e5 + 7;
const int start = 1e4;
const long double eps = 1e-9;
const int inf = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  vector<pair<int, pair<int, int>>> good = {
      {0, {inf, inf}}, {0, {-inf, -inf}}, {0, {-inf, -inf}}, {0, {inf, inf}}};
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
    if (good[0].second.first > x) good[0] = {i, p[i]};
    if (good[1].second.second < y) good[1] = {i, p[i]};
    if (good[2].second.first < x) good[2] = {i, p[i]};
    if (good[3].second.second > y) good[3] = {i, p[i]};
  }
  sort(good.begin(), good.end());
  int ans2 = 0;
  for (int i = 0; i < 4; i++) {
    ans2 += abs(good[i].second.first - good[(i + 1) % 4].second.first) +
            abs(good[i].second.second - good[(i + 1) % 4].second.second);
  }
  vector<bool> mask = {0, 0, 1, 1};
  int ans1 = 0;
  do {
    vector<pair<int, int>> ng;
    for (int i = 0; i < 4; i++) {
      if (mask[i]) ng.push_back(good[i].second);
    }
    for (int j = 0; j < n; j++) {
      ng.push_back(p[j]);
      int sum = 0;
      for (int i = 0; i < 3; i++) {
        sum += abs(ng[i].first - ng[(i + 1) % 3].first) +
               abs(ng[i].second - ng[(i + 1) % 3].second);
      }
      ans1 = max(ans1, sum);
      ng.pop_back();
    }
  } while (next_permutation(mask.begin(), mask.end()));
  cout << ans1 << " ";
  for (int i = 0; i < n - 3; i++) {
    cout << ans2 << " ";
  }
  return 0;
}
