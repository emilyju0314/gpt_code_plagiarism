#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0, x, y;
char a[101][101], s[201];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int ins[4], v[4] = {0};
bool func() {
  int tx = x, ty = y;
  for (int i = 0; i < strlen(s); i++) {
    if ((tx + xx[ins[s[i] - '0']] >= 1) && (tx + xx[ins[s[i] - '0']] <= n)) {
      if ((ty + yy[ins[s[i] - '0']] >= 1) && (ty + yy[ins[s[i] - '0']] <= m)) {
        if (a[tx + xx[ins[s[i] - '0']]][ty + yy[ins[s[i] - '0']]] != '#') {
          tx = tx + xx[ins[s[i] - '0']];
          ty = ty + yy[ins[s[i] - '0']];
          if (a[tx][ty] == 'E') {
            return true;
          }
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return false;
}
void search(int k) {
  if (k == 4) {
    if (func() == true) {
      ans++;
    }
    return;
  }
  for (int i = 0; i <= 3; i++) {
    if (v[i] == 0) {
      ins[k] = i;
      v[i] = 1;
      search(k + 1);
      v[i] = 0;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        x = i;
        y = j;
      }
    }
  }
  cin >> s;
  search(0);
  cout << ans << endl;
}
