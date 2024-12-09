#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 3;
  vector<int> x(n), y(n);
  for (int i = 0; i < (n); ++i) cin >> x[i] >> y[i];
  auto xsort = x, ysort = y;
  sort(xsort.begin(), xsort.end());
  sort(ysort.begin(), ysort.end());
  vector<pair<int, int>> pts;
  for (int xx = xsort[0]; xx < (xsort[2] + 1); ++xx) {
    pts.emplace_back(xx, ysort[1]);
  }
  for (int i = 0; i < (3); ++i) {
    long long ylo = min(y[i], ysort[1] + 1), yhi = max(ysort[1] - 1, y[i]);
    for (int yy = ylo; yy < (yhi + 1); ++yy) {
      if (yy != ysort[1]) {
        pts.emplace_back(x[i], yy);
      }
    }
  }
  cout << pts.size() << "\n";
  for (auto pt : pts) {
    cout << pt.first << " " << pt.second << "\n";
  }
}
