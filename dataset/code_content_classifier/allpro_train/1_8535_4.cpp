#include <bits/stdc++.h>
using namespace std;
int n, m, d[6][6];
vector<pair<int, int> > ke[123456];
pair<int, int> b[123456];
int len[123456], c[123456];
int cal(int n) {
  for (int i = 0; i < n; i++) c[i] = n;
  for (int x = 1; x <= 40; x++) {
    d[0][0] = d[1][0] = -1;
    d[0][1] = d[1][1] = n;
    for (int i = n - 1; i >= 0; i--) {
      if (b[i].second % x != 0) continue;
      int y = b[i].first % x;
      if (d[0][0] != y)
        c[i] = min(c[i], d[0][1]);
      else
        c[i] = min(c[i], d[1][1]);
      if (d[0][0] != y) {
        d[1][0] = d[0][0];
        d[1][1] = d[0][1];
      }
      d[0][0] = y;
      d[0][1] = i;
    }
  }
  int ans = 0;
  int r = n;
  for (int i = n - 1; i >= 0; i--) {
    r = min(r, c[i]);
    ans = max(ans, r - i);
  }
  return ans;
}
int solve_(vector<pair<int, int> > a) {
  int ans = 0;
  int l = 0;
  while (l < (int)a.size()) {
    int r = l + 1;
    while (r < (int)a.size() && a[r].first == a[r - 1].first + 1) r++;
    int k = 0;
    while (l < r) {
      b[k++] = make_pair(a[l].second, len[a[l].first]);
      l++;
    }
    ans = max(ans, cal(k));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> len[i];
    for (int j = 0; j < len[i]; j++) {
      int x;
      cin >> x;
      ke[x - 1].push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < m; i++) cout << solve_(ke[i]) << endl;
  return 0;
}
