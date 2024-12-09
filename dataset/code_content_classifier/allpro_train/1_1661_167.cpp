#include <bits/stdc++.h>
using namespace std;
const int MAX_H = 500;
const int MAX_W = 500;
char flds[MAX_H][MAX_W + 4];
int ds[MAX_H + 1][MAX_W + 1];
inline bool star(int x, int y, int w, int h) {
  return x > 0 && x < w - 1 && y > 0 && y < h - 1 && flds[y][x] == '1' &&
         flds[y - 1][x] == '1' && flds[y + 1][x] == '1' &&
         flds[y][x - 1] == '1' && flds[y][x + 1] == '1';
}
inline int dsum(int x0, int y0, int x1, int y1) {
  x0++, y0++, x1--, y1--;
  return ds[y1][x1] - ds[y1][x0] - ds[y0][x1] + ds[y0][x0];
}
int main() {
  int h, w, k;
  scanf("%d%d%d", &h, &w, &k);
  for (int y = 0; y < h; y++) scanf("%s", flds[y]);
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      int d = (star(x, y, w, h) ? 1 : 0);
      ds[y + 1][x + 1] = d + ds[y + 1][x] + ds[y][x + 1] - ds[y][x];
    }
  long long sum = 0;
  for (int y0 = 0; y0 < h; y0++)
    for (int y1 = y0 + 3; y1 <= h; y1++)
      for (int x0 = 0, x1 = 3; x1 <= w; x0++) {
        while (x1 <= w && dsum(x0, y0, x1, y1) < k) x1++;
        if (x1 <= w) sum += w + 1 - x1;
      }
  printf("%lld\n", sum);
  return 0;
}
