#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int x, y;
int a[maxn];
int b[maxn];
int mp[maxn][maxn];
const int mv[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
void move(int tx, int ty) {
  int vx = tx == x ? 0 : (tx - x) / abs(tx - x);
  int vy = ty == y ? 0 : (ty - y) / abs(ty - y);
  if (vx == 0 && vy == 0) {
    vx = 1, vy = 1;
  }
  if (vx + x < 1) vx = -vx;
  if (vx + x > 999) vx = -vx;
  if (vy + y < 1) vy = -vy;
  if (vy + y > 999) vy = -vy;
  if (mp[vx + x][vy + y]) {
    for (int i = 0; i < 8; i++) {
      int sx = mv[i][0];
      int sy = mv[i][1];
      if (mp[x + sx][y + sy] == 0) {
        cout << x + sx << " " << y + sy << endl;
        x += sx;
        y += sy;
        break;
      }
    }
  } else {
    cout << vx + x << " " << vy + y << endl;
    x += vx;
    y += vy;
  }
}
bool judgemin(int a, int b, int c, int d) {
  if (a <= b && a <= c && a <= d) {
    return true;
  }
  return false;
}
void judge(int &tx, int &ty) {
  int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
  for (int i = 1; i <= 999; i++) {
    for (int j = 1; j <= 999; j++) {
      if (mp[i][j]) {
        if (i <= 500) {
          if (j <= 500) ++l1;
          if (j >= 500) {
            ++l2;
          }
        }
        if (i >= 500) {
          if (j <= 500) {
            ++l3;
          }
          if (j >= 500) {
            ++l4;
          }
        }
      }
    }
  }
  if (judgemin(l1, l2, l3, l4)) {
    tx = 999, ty = 999;
  } else if (judgemin(l2, l1, l3, l4)) {
    tx = 999, ty = 1;
  } else if (judgemin(l3, l1, l2, l4)) {
    tx = 1, ty = 999;
  } else {
    tx = 1, ty = 1;
  }
}
void solve() {
  int k, xx, yy, tx = 500, ty = 500;
  bool flag = false;
  if (x == 500 && y == 500)
    move(1, 1);
  else
    move(500, 500);
  while (cin >> k >> xx >> yy) {
    if (k == -1 && xx == -1 && yy == -1) {
      break;
    }
    if (k == 0 && xx == 0 && yy == 0) {
      break;
    }
    mp[a[k]][b[k]] = 0;
    a[k] = xx, b[k] = yy;
    mp[a[k]][b[k]] = 1;
    if (x == 500 && y == 500) {
      flag = true;
      judge(tx, ty);
    }
    if (!flag) {
      move(500, 500);
      if (x == 500 && y == 500) {
        flag = true;
        judge(tx, ty);
      }
    } else {
      move(tx, ty);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(mp, 0, sizeof(mp));
  cin >> x >> y;
  for (int i = 1; i <= 666; i++) {
    cin >> a[i] >> b[i];
    mp[a[i]][b[i]] = 1;
  }
  solve();
  return 0;
}
