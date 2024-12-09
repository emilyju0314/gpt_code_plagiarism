#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], ans;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == 'S') a[i][j] = 2;
      if (x == '.') a[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    bool t = 1;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 2) {
        t = 0;
        break;
      }
    }
    if (t == 1) {
      for (int j = 0; j < m; j++) {
        ans += a[i][j];
        a[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    bool t = 1;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 2) {
        t = 0;
        break;
      }
    }
    if (t == 1) {
      for (int j = 0; j < n; j++) {
        ans += a[j][i];
        a[j][i] = 0;
      }
    }
  }
  cout << ans;
}
