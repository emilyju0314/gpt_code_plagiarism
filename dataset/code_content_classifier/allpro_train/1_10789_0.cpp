#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  int n, m;
  int t = 0;
  bool sch = 0;
  int minx = -1, miny, maxx = -1, maxy;
  cin >> n >> m;
  char** ma;
  ma = new char*[n];
  for (int i = 0; i < n; i++) ma[i] = new char[m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ma[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (ma[i][j] == 'X') {
        minx = i;
        miny = j;
        break;
      }
    if (minx >= 0) break;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--)
      if (ma[i][j] == 'X') {
        maxx = i;
        maxy = j;
        break;
      }
    if (maxx >= 0) break;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (ma[i][j] == 'X' && j < miny) miny = j;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (ma[i][j] == 'X' && j > maxy) maxy = j;
  }
  if ((maxx < minx) || (maxy < miny)) {
    cout << "NO";
  } else {
    for (int i = minx; i <= maxx; i++) {
      for (int j = miny; j <= maxy; j++)
        if (ma[i][j] == '.') {
          cout << "NO";
          t = 1;
          break;
        }
      if (t) break;
    }
    if (!t) cout << "YES";
  }
}
