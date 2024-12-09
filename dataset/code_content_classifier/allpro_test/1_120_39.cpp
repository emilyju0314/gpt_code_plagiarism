#include <bits/stdc++.h>
using namespace std;
int d[200001][20] = {};
int main() {
  for (int i = 1; i <= 200000; ++i) {
    for (int j = 0; j < 20; ++j) {
      d[i][j] = d[i - 1][j];
      d[i][j] += (((i >> j) & 1) == 0);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = INT_MAX;
    for (int i = 0; i < 20; ++i) {
      ans = min(ans, d[r][i] - d[l - 1][i]);
    }
    cout << ans << endl;
  }
}
