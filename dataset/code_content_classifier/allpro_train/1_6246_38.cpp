#include <bits/stdc++.h>
using namespace std;
const int n = 8;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> s(n);
  for (string& t : s) cin >> t;
  auto statues_move = [=](vector<string>& t) {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        if (t[i][j] == 'S') {
          t[i][j] = '.';
          if (i < n - 1) t[i + 1][j] = 'S';
        }
      }
    }
  };
  bool flag = false;
  queue<pair<int, vector<string>>> q;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  vector<int> dx = {-1, -1, 0, 1, 1, 0, -1};
  vector<int> dy = {-1, 1, 1, 1, -1, -1, -1};
  q.push({0, s});
  while (!q.empty()) {
    int id = q.front().first;
    vector<string> t = q.front().second;
    q.pop();
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
      if (t[i].find("M") != -1) {
        x = i;
        y = t[i].find("M");
        break;
      }
    }
    if (x == -1) continue;
    if (x == 0 && y == 7) {
      flag = true;
      break;
    }
    if (vis[x][y] > n || id != vis[x][y]) continue;
    vis[x][y] = id = id + 1;
    for (int i = 0; i < n - 1; i++) {
      bool check = true;
      check &= dx[i] < 0 ? x > 0 : !dx[i] ? true : x < n - 1;
      check &= dy[i] < 0 ? y > 0 : !dy[i] ? true : y < n - 1;
      if (!check) continue;
      if (!vis[x + dx[i]][y + dy[i]] && t[x + dx[i]][y + dy[i]] != 'S') {
        vector<string> a = t;
        a[x][y] = '.';
        a[x + dx[i]][y + dy[i]] = 'M';
        statues_move(a);
        q.push({0, a});
      }
    }
    statues_move(t);
    q.push({id, t});
  }
  cout << (flag ? "WIN" : "LOSE");
  return 0;
}
