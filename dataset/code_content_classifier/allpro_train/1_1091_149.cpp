#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], cate, s, n, m;
int sCol[1005], sLin[1005];
char c;
bool solve(int x, int y) {
  if (a[x][y]) {
    if (sCol[y] + sLin[x] - 1 == cate) return true;
  } else {
    if (sCol[y] + sLin[x] == cate) return true;
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c;
      if (c == '*') a[i][j] = 1, cate++;
    }
  for (int i = 1; i <= n; i++) {
    s = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) s++;
    }
    sLin[i] = s;
  }
  for (int j = 1; j <= m; j++) {
    s = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j]) s++;
    }
    sCol[j] = s;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (solve(i, j)) {
        cout << "YES\n";
        cout << i << " " << j;
        exit(0);
      }
  cout << "NO";
}
