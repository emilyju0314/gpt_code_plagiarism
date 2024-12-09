#include <bits/stdc++.h>
using namespace std;
int n, m, k, dx, dy, x, y;
char c[5];
bool f;
long long ans;
struct blk {
  int x, y;
  blk(int xx = 0, int yy = 0) {
    x = xx;
    y = yy;
  }
  bool operator<(const blk& b) const {
    return x < b.x || (x == b.x && y < b.y);
  }
};
vector<blk> data[2];
void ins(int x, int y) {
  data[0].push_back(blk(x - y, x));
  data[1].push_back(blk(x + y, x));
}
void beam() {
  int ff = (dx != dy);
  blk p = ff ? blk(x + y, x) : blk(x - y, x);
  vector<blk>::iterator it = upper_bound(data[ff].begin(), data[ff].end(), p);
  for (; it->x != p.x; it--)
    ;
  if (dx < 0)
    for (; it->y >= x; it--)
      ;
  ans += abs(x - it->y) - 1;
  x = it->y, y = ff ? it->x - x : x - it->x;
  bool u =
      binary_search(data[0].begin(), data[0].end(), blk(x - y - dx, x - dx));
  bool v = binary_search(data[0].begin(), data[0].end(), blk(x - y + dy, x));
  if (u == v) {
    f = 1;
    dx *= -1;
    dy *= -1;
  } else if (u) {
    x -= dx;
    dy *= -1;
  } else if (v) {
    y -= dy;
    dx *= -1;
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    ins(0, i);
    ins(n + 1, i);
  }
  for (int i = 0; i <= n + 1; i++) {
    ins(i, 0);
    ins(i, m + 1);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    ins(x, y);
  }
  scanf("%d%d%s", &x, &y, c);
  dx = (c[0] == 'N') ? -1 : 1, dy = (c[1] == 'W') ? -1 : 1;
  sort(data[0].begin(), data[0].end());
  sort(data[1].begin(), data[1].end());
  beam();
  int sx = x, sy = y, sdx = dx, sdy = dy;
  ans = 0;
  do beam();
  while (!(x == sx && y == sy && dx == sdx && dy == sdy));
  cout << ((f) ? (ans / 2) : ans) << endl;
  return 0;
}
