#include <bits/stdc++.h>
using namespace std;
vector<int> w;
int n;
vector<int> vs;
int main() {
  cin >> n;
  w.resize(2 * n);
  for (int i = 0; i < 2 * n; ++i) cin >> w[i];
  sort(w.begin(), w.end());
  int ans = INT_MAX;
  vs.resize(n - 1);
  for (int j = 0; j < 2 * n; ++j) {
    for (int k = 0; k < 2 * n; ++k) {
      if (j == k) continue;
      memset(vs.data(), 0, sizeof(vs.front()) * vs.size());
      int res = 0;
      int t = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (i == j || i == k) continue;
        for (int ii = i + 1; ii < 2 * n; ++ii) {
          if (ii == j || ii == k) continue;
          vs[t] = abs(w[i] - w[ii]);
          res += vs[t++];
          i = ii;
          break;
        }
      }
      sort(vs.begin(), vs.end());
      ans = min(ans, res);
    }
  }
  cout << ans;
  return 0;
}
