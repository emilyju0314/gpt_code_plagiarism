#include <bits/stdc++.h>
using namespace std;
int ans[222][222];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct P {
  int x, y;
};
int inque[222][222];
queue<P> que;
void bfs() {
  int i, j, k;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int t = ans[p.x][p.y] / 4;
    ans[p.x][p.y] -= t * 4;
    if (t <= 0) {
      inque[p.x][p.y] = 0;
      continue;
    }
    for (i = 0; i < 4; i++) {
      int x = p.x + dir[i][0];
      int y = p.y + dir[i][1];
      if (x < 0 || y < 0) continue;
      if ((x == 0 || y == 0) && (p.x != 0 && p.y != 0)) {
        if (x == 0) {
          ans[x][y] += 2 * t;
        }
        if (y == 0) {
          ans[x][y] += 2 * t;
        }
        if (x == 0 && y == 0) ans[x][y] -= 2 * t;
      } else if (x == 0 && y == 0) {
        ans[x][y] += 2 * t;
      } else
        ans[x][y] += t;
      if (!inque[x][y]) {
        P p1;
        p1.x = x;
        p1.y = y;
        que.push(p1);
        inque[x][y] = 1;
      }
    }
    inque[p.x][p.y] = 0;
  }
}
int main() {
  int n, t;
  cin >> n >> t;
  int i;
  P p1;
  p1.x = 0;
  p1.y = 0;
  ans[0][0] = n;
  inque[0][0] = 1;
  que.push(p1);
  bfs();
  for (i = 1; i <= t; i++) {
    long long x, y;
    cin >> x >> y;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x >= 222 || y >= 222) {
      cout << "0" << endl;
      continue;
    }
    cout << ans[x][y] << endl;
  }
  return 0;
}
