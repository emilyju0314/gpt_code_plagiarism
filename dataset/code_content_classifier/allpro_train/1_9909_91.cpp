#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 1000 * 1000 * 1000;
const double EPS = 1e-9;
string board[maxn];
int n, m, dirx[] = {1, 0, -1, 0}, diry[] = {0, 1, 0, -1};
bool flag[maxn][maxn];
inline bool inRange(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
int BFS(int x, int y) {
  queue<pair<pair<int, int>, int> > q;
  int dist = INF, r, k, u, v, ans;
  q.push(make_pair(make_pair(x, y), 0));
  flag[x][y] = true;
  ans = 0;
  while (!q.empty()) {
    r = q.front().second;
    x = q.front().first.first;
    y = q.front().first.second;
    q.pop();
    if (board[x][y] == 'S') dist = r;
    if (board[x][y] <= '9' && board[x][y] >= '0' && r <= dist)
      ans += board[x][y] - '0';
    for (k = 0; k < 4; k++) {
      u = x + dirx[k];
      v = y + diry[k];
      if (inRange(u, v) && board[u][v] != 'T' && !flag[u][v]) {
        q.push(make_pair(make_pair(u, v), r + 1));
        flag[u][v] = true;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, x, y;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> board[i];
    for (j = 0; j < m; j++)
      if (board[i][j] == 'E') {
        x = i;
        y = j;
      }
  }
  cout << BFS(x, y) << endl;
  return 0;
}
