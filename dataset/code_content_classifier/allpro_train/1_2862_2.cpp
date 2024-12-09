#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
int n;
int row[1001], col[1001];
int revrow[1001], revcol[1001];
int ans[1005][4];
int cnt = 0;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> row[i];
  for (int i = 1; i <= n; ++i) cin >> col[i];
  for (int i = 1; i <= n; ++i) {
    revrow[row[i]] = i;
    revcol[col[i]] = i;
  }
  for (int i = n; i >= 2; --i) {
    int x1 = revrow[i], x2 = row[i], y1 = revcol[i], y2 = col[i];
    ans[cnt][0] = i, ans[cnt][1] = y2, ans[cnt][2] = x2, ans[cnt][3] = i;
    if (!(ans[cnt][0] == ans[cnt][2] && ans[cnt][1] == ans[cnt][3])) ++cnt;
    row[x1] = x2, col[y1] = y2, revrow[x2] = x1, revcol[y2] = y1;
  }
  cout << cnt << '\n';
  for (int i = 0; i < cnt; ++i) {
    cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' '
         << ans[i][3] << '\n';
  }
  return 0;
}
