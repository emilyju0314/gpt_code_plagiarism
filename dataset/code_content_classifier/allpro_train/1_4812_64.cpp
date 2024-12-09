#include <bits/stdc++.h>
using namespace std;
int dp[1 << 16][150];
struct pi {
  int ty;
  int r, b;
} pp[16];
int xx[1 << 16];
int yy[1 << 16];
int to[1 << 16];
int main() {
  int n;
  for (int i = 0; i < 16; i++) to[1 << i] = i;
  cin >> n;
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    char c[2];
    scanf("%s", c);
    if (c[0] == 'R')
      pp[i].ty = 0;
    else
      pp[i].ty = 1;
    scanf("%d%d", &pp[i].r, &pp[i].b);
    x += pp[i].r;
    y += pp[i].b;
  }
  for (int i = 1; i < (1 << n); i++) {
    int w = i & (i - 1);
    xx[i] = xx[w];
    yy[i] = yy[w];
    w = w ^ i;
    w = to[w];
    if (pp[w].ty == 0)
      xx[i]++;
    else
      yy[i]++;
  }
  int le = 0;
  int ri = 1000000000;
  while (le <= ri) {
    int mid = (le + ri) / 2;
    if (x <= mid && y <= mid) {
      ri = mid - 1;
      continue;
    }
    int x1 = max(x - mid, 0);
    int y1 = max(y - mid, 0);
    if (x1 >= 150 || y1 >= 150) {
      le = mid + 1;
      continue;
    }
    int p = 1 << n;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < 150; j++) {
        dp[i][j] = -1000000000;
      }
    }
    dp[0][x1] = 0;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j <= x1; j++) {
        if (dp[i][j] >= 0) {
          for (int q = 0; q < n; q++) {
            if (!(i & (1 << q))) {
              int x2 = xx[i];
              int y2 = yy[i];
              x2 = max(0, pp[q].r - x2);
              y2 = max(0, pp[q].b - y2);
              x2 = pp[q].r - x2;
              y2 = pp[q].b - y2;
              dp[i ^ (1 << q)][max(j - x2, 0)] =
                  max(dp[i ^ (1 << q)][max(j - x2, 0)], dp[i][j] + y2);
            }
          }
        }
      }
    }
    if (dp[p - 1][0] >= y1) {
      ri = mid - 1;
    } else
      le = mid + 1;
  }
  cout << le + n << endl;
}
