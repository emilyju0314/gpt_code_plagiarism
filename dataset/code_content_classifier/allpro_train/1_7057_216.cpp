#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int mat[n][n];
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < k; ++j) mat[i][j] = cnt++;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = k - 1; j < n; ++j) mat[i][j] = cnt++;
  }
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += mat[i][k - 1];
  }
  cout << tot << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
