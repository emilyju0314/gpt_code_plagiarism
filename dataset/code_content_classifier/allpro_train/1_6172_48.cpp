#include <bits/stdc++.h>
using namespace std;
int l[2001][2001], r[2001][2001];
int fnd(int arr[][2001], int x, int k) {
  return arr[x][k] == k ? k : arr[x][k] = fnd(arr, x, arr[x][k]);
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  bool flag = false;
  if (n > m) {
    swap(n, m);
    flag = true;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) l[i][j] = r[i][j] = j;
  for (int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (flag) swap(x, y);
    int minv = 1000000000, minx, miny;
    for (int j = 0; j * j <= i * 64 && (x - j > 0 || x + j <= n); ++j) {
      if (j > minv) break;
      for (int o = 0; o < 2; ++o)
        for (int p = 0; p < 2; ++p) {
          int px = (p ? x - j : x + j);
          if (px > 0 && px <= n) {
            int val = fnd(o ? r : l, px, y);
            if (val != 0 && val != m + 1) {
              int dist = abs(y - val) + j;
              if (dist < minv ||
                  (dist == minv &&
                   ((flag && make_pair(val, px) < make_pair(miny, minx)) ||
                    (!flag && make_pair(px, val) < make_pair(minx, miny))))) {
                minv = dist;
                miny = val;
                minx = px;
              }
            }
          }
        }
    }
    l[minx][miny] = miny - 1;
    r[minx][miny] = miny + 1;
    if (flag) swap(minx, miny);
    printf("%d %d\n", minx, miny);
  }
  return 0;
}
