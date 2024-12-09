#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1005, Maxh = 33, mod = 1000000009;
int n, h, ans = 0;
int f[2][Maxh][Maxh][Maxh][2];
inline void add(int &x, int y) { (x += y) >= mod ? x -= mod : 0; }
int main() {
  cin >> n >> h;
  f[1][1][1][1][1] = 4;
  int t = 1;
  for (int i = 1, now; i < n; ++i, t ^= 1) {
    for (int x = 1, X = min(h, 2); x <= h; X = min(h, (++x) + 1))
      for (int y = 1, Y = min(h, 2); y <= h; Y = min(h, (++y) + 1))
        for (int z = 1, Z = min(h, 2); z <= h; Z = min(h, (++z) + 1)) {
          if (now = f[t][x][y][z][0]) {
            add(f[t ^ 1][X][Y][Z][0], now);
            add(f[t ^ 1][h][Y][Z][x < h], now);
            add(f[t ^ 1][h][X][Z][y < h], now);
            add(f[t ^ 1][h][X][Y][z < h], now);
          }
          if (now = f[t][x][y][z][1]) {
            add(f[t ^ 1][X][Y][Z][1], now);
            add(f[t ^ 1][1][Y][Z][x < h], now);
            add(f[t ^ 1][1][X][Z][y < h], now);
            add(f[t ^ 1][1][X][Y][z < h], now);
          }
        }
    memset(f[t], 0, sizeof f[t]);
  }
  for (int x = 1; x <= h; ++x)
    for (int y = 1; y <= h; ++y)
      for (int z = 1; z <= h; ++z) {
        add(ans, f[t][x][y][z][1]);
        if (x + y + z < 3 * h) add(ans, f[t][x][y][z][0]);
      }
  cout << ans << endl;
  return 0;
}
