#include <bits/stdc++.h>
using namespace std;
int x[33], y[33];
int xb, yb, xe, ye;
int n, m, k;
char mp[111][111], s[1111];
int time(char c) {
  if ('0' <= c && c <= '9') {
    return c - '0';
  }
  return 1;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    getchar();
    for (int j = 1; j <= m; j++) {
      char c = getchar();
      if ('a' <= c && c <= 'z') {
        x[c - '0'] = i;
        y[c - '0'] = j;
      }
      mp[i][j] = c;
    }
  }
  scanf("%d %d %s %d %d", &xb, &yb, s, &xe, &ye);
  int t = 0, id = 0, len = strlen(s);
  while (t + time(mp[xb][yb]) <= k && id <= len) {
    int nx, ny;
    if (id == len) {
      nx = xe, ny = ye;
    } else {
      nx = x[s[id] - '0'], ny = y[s[id] - '0'];
    }
    if (nx == xb && ny == yb) {
      id++;
      continue;
    }
    t += time(mp[xb][yb]);
    if (nx == xb) {
      if (ny < yb) {
        yb--;
      } else {
        yb++;
      }
    } else {
      if (nx < xb) {
        xb--;
      } else {
        xb++;
      }
    }
  }
  printf("%d %d\n", xb, yb);
  return 0;
}
