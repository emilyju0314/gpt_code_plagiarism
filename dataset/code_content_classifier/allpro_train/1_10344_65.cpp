#include <bits/stdc++.h>
using namespace std;
int a[100002];
int b[100002];
vector<int> bb[100010];
int d[100002][306];
int minb[306];
int n, m, s, e;
int main(void) {
  cin >> n >> m >> s >> e;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    bb[b[i]].push_back(i);
  }
  for (int i = 0; i < 305; ++i) minb[i] = 1000000000;
  int ans = 0;
  vector<int>::iterator it;
  for (int i = 0; i < n; ++i) {
    for (int j = 305; j >= 1; --j) {
      d[i][j] = -1;
      if (j == 1) {
        if (bb[a[i]].size() > 0) {
          minb[1] = min(minb[1], bb[a[i]][0]);
          d[i][j] = bb[a[i]][0];
        }
      } else {
        it = upper_bound(bb[a[i]].begin(), bb[a[i]].end(), minb[j - 1]);
        if (it != bb[a[i]].end()) {
          minb[j] = min(minb[j], *it);
          d[i][j] = *it;
        }
      }
      if (d[i][j] != -1) {
        if (d[i][j] + i + 2 + j * e <= s) {
          ans = max(ans, j);
        }
      }
    }
  }
  cout << ans << endl;
}
