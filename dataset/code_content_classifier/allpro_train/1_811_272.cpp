#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace std::chrono;
const int SZ = 65;
int cur[SZ][SZ], NESDF[SZ][SZ];
int get(int x, int y) {
  if (x >= SZ or y >= SZ) return 0;
  return cur[x][y];
}
void inc(int x, int y, int cnt, int y_fr) {
  if (x < 0 or y < 0 or y > x) return;
  if (x == y) cnt *= 2;
  if (y == 0 and (x == 0 or y_fr != 0)) cnt *= 2;
  NESDF[x][y] += cnt;
}
void init(int n) {
  cur[0][0] = n;
  int iter = 0;
  bool change = true;
  while (change) {
    ++iter;
    change = false;
    memset(NESDF, 0, sizeof(NESDF));
    for (int i = 0; i < SZ; ++i)
      for (int j = 0; j < SZ; ++j) {
        auto p = make_pair(make_pair(i, j), cur[i][j]);
        if (p.second >= 4) {
          change = true;
          int cnt = p.second / 4;
          auto pos = p.first;
          NESDF[i][j] += p.second % 4;
          inc(pos.first - 1, pos.second, cnt, pos.second);
          inc(pos.first + 1, pos.second, cnt, pos.second);
          inc(pos.first, pos.second - 1, cnt, pos.second);
          inc(pos.first, pos.second + 1, cnt, pos.second);
        } else if (p.second > 0) {
          NESDF[i][j] += p.second;
        }
      }
    memcpy(cur, NESDF, sizeof(NESDF));
  };
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  init(n);
  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    if (y > x) swap(x, y);
    cout << get(x, y) << "\n";
  }
  return 0;
}
