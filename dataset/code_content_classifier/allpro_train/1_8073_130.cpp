#include <bits/stdc++.h>
using namespace std;
int cnt[1000007];
int main() {
  int t = 1;
  while (t--) {
    int a, b, k, x, xx, m, n, i, j, aa, z, nn, mm, bb, y,
        p = 0, pp, d, dd, tt, f = 0, c, cc, l = 0, r = 0, res = 0, ans, ff = 0;
    cc = 1000000 + 1, c = 0;
    cin >> n >> m;
    int ar[n + 2], br[n + 2], cr[m + 2], dr[m + 2];
    for (int i = 0; i < n; i++) {
      cin >> ar[i] >> br[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> cr[i] >> dr[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ar[i] <= cr[j]) {
          cnt[cr[j] - ar[i]] = max(cnt[cr[j] - ar[i]], dr[j] - br[i] + 1);
        }
      }
    }
    for (i = 1000000; i >= 0; i--) {
      c = max(c, cnt[i]);
      cc = min(cc, c + i);
    }
    cout << cc << '\n';
  }
  return 0;
}
