#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, fi, fr, f[2][100200], qx[200200], qy[200200];
char s[2][100100];
int main() {
  cin >> n >> k;
  cin >> s[0];
  cin >> s[1];
  f[0][0] = 1;
  for (fr = 1; fi < fr;) {
    x = qx[fi];
    y = qy[fi++];
    if (y >= n - k) {
      cout << "YES";
      return 0;
    }
    if (y > 0 && s[x][y - 1] == '-' && f[x][y - 1] == 0 && y > f[x][y]) {
      f[x][y - 1] = f[x][y] + 1;
      qx[fr] = x;
      qy[fr++] = y - 1;
    }
    if (s[x][y + 1] == '-' && f[x][y + 1] == 0) {
      f[x][y + 1] = f[x][y] + 1;
      qx[fr] = x;
      qy[fr++] = y + 1;
    }
    if (s[1 - x][y + k] == '-' && f[1 - x][y + k] == 0) {
      f[1 - x][y + k] = f[x][y] + 1;
      qx[fr] = 1 - x;
      qy[fr++] = y + k;
    }
  }
  cout << "NO";
  return 0;
}
