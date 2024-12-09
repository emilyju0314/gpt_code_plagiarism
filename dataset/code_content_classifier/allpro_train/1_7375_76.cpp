#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char ch;
        cin >> ch;
        v[i][j] = ch - '0';
      }
    }
    bool check = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (v[i][j] == 0) continue;
        if (j == n - 1 && i + 1 < n && v[i + 1][j] == 0) {
          check = 0;
          break;
        } else if (j == n - 1) {
          continue;
        }
        if ((i + 1 < n && v[i + 1][j] == 0) &&
            (j + 1 < n && v[i][j + 1] == 0)) {
          check = 0;
          break;
        }
      }
      if (!check) {
        break;
      }
    }
    if (check)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
