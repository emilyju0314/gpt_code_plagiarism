#include <bits/stdc++.h>
using namespace std;
int d, s, pre[505][5005][3];
bool vis[505][5005];
queue<int> Qx, Qy;
void bfs() {
  vis[0][0] = 1;
  Qx.push(0);
  Qy.push(0);
  while (!Qx.empty()) {
    int x = Qx.front();
    Qx.pop();
    int y = Qy.front();
    Qy.pop();
    for (int i = 0; i <= 9; i++) {
      int xx = (10 * x + i) % d, yy = y + i;
      if (vis[xx][yy] || yy > s) continue;
      vis[xx][yy] = 1;
      pre[xx][yy][0] = x;
      pre[xx][yy][1] = y;
      pre[xx][yy][2] = i;
      Qx.push(xx), Qy.push(yy);
    }
  }
}
void out(int x, int y) {
  if (x == 0 && y == 0) return;
  out(pre[x][y][0], pre[x][y][1]);
  cout << pre[x][y][2];
}
int main() {
  ios::sync_with_stdio(0);
  cin >> d >> s;
  bfs();
  if (vis[0][s] == 0)
    cout << "-1\n";
  else
    out(0, s);
  return 0;
}
