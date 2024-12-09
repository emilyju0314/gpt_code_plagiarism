#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
const int M = 10010;
const int mod = 1e9 + 7;
int n, m;
int a[2][N];
bool flag;
void dfs(int x, int y, int dir) {
  if (x == 1 && y == n && dir == 1) {
    flag = 1;
    return;
  }
  if (x > 1 || y >= n || x < 0 || y < 0) return;
  if (a[x][y] == 1 || a[x][y] == 2) {
    if (dir == 1) {
      dfs(x, y + 1, 1);
    }
  } else {
    if (dir == 1) {
      int d;
      if (x == 0)
        d = 2;
      else
        d = 0;
      dfs(x ^ 1, y, d);
    } else if (dir == 2) {
      if (x == 1) {
        dfs(x, y + 1, 1);
      }
    } else {
      if (x == 0) {
        dfs(x, y + 1, 1);
      }
    }
  }
}
int main() {
  int i, j, k, t, ct = 1;
  scanf("%d", &t);
  while (t--) {
    flag = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%1d", a[0] + i);
    }
    for (i = 0; i < n; i++) {
      scanf("%1d", a[1] + i);
    }
    dfs(0, 0, 1);
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
