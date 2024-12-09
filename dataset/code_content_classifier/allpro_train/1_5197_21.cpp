#include <bits/stdc++.h>
using namespace std;
int a[22][22];
pair<int, int> p[22 * 22];
int n, m, cnt;
vector<vector<int> > ans;
void change(vector<pair<int, int> > k) {
  int s = k.size();
  ans.push_back({}), cnt++;
  for (int i = (0); i <= (s - 1); i++) {
    ans[cnt].push_back(a[k[i].first][k[i].second]);
    p[a[k[i].first][k[i].second]] = {k[(i + 1) % s].first,
                                     k[(i + 1) % s].second};
  }
  for (int i = (s - 1); i >= (1); i--)
    swap(a[k[i].first][k[i].second], a[k[i - 1].first][k[i - 1].second]);
}
void move(int id, int dir) {
  int x = p[id].first, y = p[id].second;
  if (dir == 0 || dir == 1) {
    int _x = (x == n ? -1 : 1);
    int _y = (dir ? 1 : -1);
    change({{x, y}, {x, y + _y}, {x + _x, y + _y}, {x + _x, y}});
  }
  if (dir == 2 || dir == 3) {
    int _x = (dir == 2 ? -1 : 1);
    int _y = (y == m ? -1 : 1);
    change({{x, y}, {x + _x, y}, {x + _x, y + _y}, {x, y + _y}});
  }
}
void transfer(int id, int x, int y) {
  while (p[id].second > y) move(id, 0);
  while (p[id].second < y) move(id, 1);
  while (p[id].first > x) move(id, 2);
  while (p[id].first < x) move(id, 3);
}
void exchange1(int x, int y) {
  int _x = (x > 1 ? -1 : 1);
  int dir = (x > 1 ? 2 : 3);
  move(a[x][y - 1], dir);
  move(a[x][y - 2], dir);
  change({{x, y},
          {x + _x, y},
          {x + _x, y - 1},
          {x + _x, y - 2},
          {x, y - 2},
          {x, y - 1}});
}
void exchange2(int x, int y) {
  move(a[x][y], 2);
  move(a[x - 1][y], 2);
  change({{x, y},
          {x, y + 1},
          {x - 1, y + 1},
          {x - 2, y + 1},
          {x - 2, y},
          {x - 1, y}});
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) cin >> a[i][j], p[a[i][j]] = {i, j};
  cnt = -1;
  for (int i = (1); i <= (n - 2); i++) {
    for (int j = (1); j <= (m - 1); j++) transfer((i - 1) * m + j, i, j);
    if (a[i][m] == i * m) continue;
    transfer(i * m, i + 1, m - 1);
    move(a[i + 1][m - 1], 2);
    exchange1(i, m);
  }
  for (int j = (1); j <= (m - 2); j++) {
    transfer((n - 1) * m + j, n, j);
    if (a[n - 1][j] == (n - 2) * m + j) continue;
    transfer((n - 2) * m + j, n, j + 1);
    move(a[n][j], 2);
    exchange2(n, j);
  }
  while (a[n - 1][m - 1] != (n - 1) * m - 1) move(a[n][m], 2);
  if (a[n][m - 1] == (n - 1) * m)
    move(a[n][m], 2), exchange1(n, m), move(a[n][m], 0), move(a[n][m], 0);
  if (a[n][m] == (n - 1) * m)
    move(a[n][m], 0), exchange1(n, m), move(a[n][m], 2);
  if (a[n][m] == n * m - 1) exchange1(n, m);
  cout << cnt + 1 << endl;
  for (int i = (0); i <= (cnt); i++) {
    cout << ans[i].size() << " ";
    for (int j : ans[i]) cout << j << " ";
    cout << endl;
  }
  return 0;
}
