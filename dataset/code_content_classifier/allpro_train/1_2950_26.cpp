#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, count;
  cin >> n >> m;
  char a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'W') {
        if (a[i + 1][j] == 'P' || a[i - 1][j] == 'P' || a[i][j + 1] == 'P' ||
            a[i][j - 1] == 'P') {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
