#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, temp = 0, sol = 0;
  cin >> n >> m >> k;
  char mat[n + 1][m + 1];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == '.') {
        cnt++;
        temp++;
      } else {
        if (cnt >= k) sol += (cnt - k + 1);
        cnt = 0;
      }
      if (mat[i][j] == '.' && j == m - 1 && cnt >= k) sol += (cnt - k + 1);
    }
  }
  if (k == 1) {
    cout << temp << endl;
    return 0;
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '.') {
        cnt++;
      } else {
        if (cnt >= k) sol += (cnt - k + 1);
        cnt = 0;
      }
      if (mat[i][j] == '.' && i == n - 1 && cnt >= k) sol += (cnt - k + 1);
    }
  }
  cout << sol << endl;
  return 0;
}
