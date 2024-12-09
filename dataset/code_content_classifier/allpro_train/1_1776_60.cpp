#include <bits/stdc++.h>
using namespace std;
int t, c;
char grid[3][102];
bool vis[3][102];
bool BFS() {
  int curX, curY;
  curY = 0;
  if (grid[0][0] == 's')
    curX = 0;
  else if (grid[1][0] == 's')
    curX = 1;
  else
    curX = 2;
  queue<pair<long long, long long> > q;
  q.push(make_pair(curX, curY));
  while (!q.empty()) {
    curX = q.front().first;
    curY = q.front().second;
    q.pop();
    if (curY >= c - 1)
      return 1;
    else {
      if (vis[curX][curY]) continue;
      vis[curX][curY] = 1;
      if (grid[curX][curY + 1] != '.') continue;
      for (int i = curY + 1; i <= curY + 3; ++i) {
        if (i < c && grid[curX][i] != '.') break;
        if (i == curY + 3) q.push(make_pair(curX, curY + 3));
      }
      if (curX > 0) {
        for (int i = curY + 1; i <= curY + 3; ++i) {
          if (i < c && grid[curX - 1][i] != '.') break;
          if (i == curY + 3) q.push(make_pair(curX - 1, curY + 3));
        }
      }
      if (curX < 2) {
        for (int i = curY + 1; i <= curY + 3; ++i) {
          if (i < c && grid[curX + 1][i] != '.') break;
          if (i == curY + 3) q.push(make_pair(curX + 1, curY + 3));
        }
      }
    }
  }
  return 0;
}
int main() {
  int temp;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> c >> temp;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < c; ++k) {
        cin >> grid[j][k];
      }
    }
    memset(vis, 0, sizeof(vis));
    if (BFS())
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
