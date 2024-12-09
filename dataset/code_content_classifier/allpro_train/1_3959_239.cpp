#include <bits/stdc++.h>
using namespace std;
const int N = 66;
int a[4][N], n;
vector<pair<int, pair<int, int> > > ans;
pair<int, int> nex(int x, int y) {
  if (x == 1) {
    if (y < n - 1) return {x, y + 1};
    return {2, n - 1};
  }
  if (y) return {x, y - 1};
  return {1, 0};
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> n >> k;
  for (int i = 0; i < (4); i++)
    for (int j = 0; j < (n); j++) cin >> a[i][j];
  int tes = 200;
  while (tes--) {
    int tx = -1, ty = -1;
    for (int i = 0; i < (n); i++)
      if (a[1][i] == 0) {
        tx = 1;
        ty = i;
      } else if (a[2][i] == 0) {
        tx = 2;
        ty = i;
      }
    for (int i = 0; i < (n); i++) {
      if (a[0][i] == a[1][i] and a[0][i]) {
        ans.push_back({a[0][i], {0, i}});
        a[1][i] = 0;
      }
      if (a[3][i] == a[2][i] and a[2][i]) {
        ans.push_back({a[2][i], {3, i}});
        a[2][i] = 0;
      }
    }
    if (tx != -1) {
      int o = 2 * n - 1;
      while (o--) {
        int x = nex(tx, ty).first;
        int y = nex(tx, ty).second;
        if (a[x][y]) {
          ans.push_back({a[x][y], {tx, ty}});
          a[tx][ty] = a[x][y];
          a[x][y] = 0;
        }
        tx = x;
        ty = y;
      }
    }
  }
  for (int i = 0; i < (n); i++)
    if (a[1][i] or a[2][i]) return cout << -1 << endl, 0;
  cout << ans.size() << endl;
  for (auto u : ans)
    cout << u.first << ' ' << u.second.first + 1 << ' ' << u.second.second + 1
         << endl;
  return 0;
}
