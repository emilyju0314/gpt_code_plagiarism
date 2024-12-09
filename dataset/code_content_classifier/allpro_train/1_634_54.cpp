#include <bits/stdc++.h>
using namespace std;
int r, c;
int f[3005 * 6005];
int gf(int x) { return x == f[x] ? x : f[x] = gf(f[x]); }
void un(int x, int y) {
  if (x && y) f[gf(x)] = gf(y);
}
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int vis[3005 * 6005] = {0};
int tmp = 0;
int main() {
  scanf("%d%d", &r, &c);
  if (c == 1) {
    printf("0\n");
    return 0;
  }
  int q;
  scanf("%d", &q);
  int ans = 0;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    tmp++;
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx == 0 || xx > r) continue;
      if (yy <= 0) yy += 2 * c;
      vis[gf(((yy)*r + (xx)))] = tmp;
    }
    int bo = 1;
    vis[0] = 0;
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i] + c;
      if (xx == 0 || xx > r) continue;
      if (yy <= 0) yy += 2 * c;
      if (yy > 2 * c) yy -= 2 * c;
      if (vis[gf(((yy)*r + (xx)))] == tmp) {
        bo = 0;
        break;
      }
    }
    if (bo) {
      ans++;
      f[((y)*r + (x))] = ((y)*r + (x));
      f[((y + c) * r + (x))] = ((y + c) * r + (x));
      for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx == 0 || xx > r) continue;
        if (yy <= 0) yy += 2 * c;
        un(gf(((y)*r + (x))), gf(((yy)*r + (xx))));
      }
      int bo = 1;
      for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i] + c;
        if (xx == 0 || xx > r) continue;
        if (yy <= 0) yy += 2 * c;
        if (yy > 2 * c) yy -= 2 * c;
        un(gf(((y + c) * r + (x))), gf(((yy)*r + (xx))));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
