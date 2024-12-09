#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n, min = INT_MAX;
    cin >> n >> m;
    char a[n][m];
    vector<int> b;
    vector<int> d;
    for (int i = 0; i < n; i++) {
      int row = 0;
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '*') row++;
      }
      b.push_back(row);
    }
    for (int i = 0; i < m; i++) {
      int col = 0;
      for (int j = 0; j < n; j++) {
        if (a[j][i] == '*') col++;
      }
      d.push_back(col);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int k = (m - b[i]) + (n - d[j]) - 1;
        if (a[i][j] == '*') k = k + 1;
        ;
        if (k < min) min = k;
      }
    }
    cout << min << endl;
  }
  return 0;
}
