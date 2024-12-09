#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, i, j, flag = 1;
    cin >> n >> m;
    long long int a[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) cin >> a[i][j];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        int cnt = 0;
        if (i - 1 >= 0) {
          cnt++;
          if (!a[i - 1][j]) a[i - 1][j] = 1;
        }
        if (i + 1 < n) {
          cnt++;
          if (!a[i + 1][j]) a[i + 1][j] = 1;
        }
        if (j - 1 >= 0) {
          cnt++;
          if (!a[i][j - 1]) a[i][j - 1] = 1;
        }
        if (j + 1 < m) {
          cnt++;
          if (!a[i][j + 1]) a[i][j + 1] = 1;
        }
        if (a[i][j] > cnt) {
          flag = 0;
          break;
        }
        a[i][j] = cnt;
      }
      if (!flag) break;
    }
    if (flag) {
      cout << "YES\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << "\n";
      }
    } else
      cout << "NO\n";
  }
}
