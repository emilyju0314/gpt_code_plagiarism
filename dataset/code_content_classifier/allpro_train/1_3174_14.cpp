#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[505][505];
const int N = 3e5 + 10, C = 26, inf = 1e7;
bool check(int i, int j) {
  if ((i - 1 > 0 || i - 1 == 0) && mat[i - 1][j] == 1) {
    return 1;
  }
  if ((j - 1 > 0 || j - 1 == 0) && mat[i][j - 1] == 1) {
    return 1;
  }
  if (mat[i + 1][j] == 1 && i < n) {
    return 1;
  }
  if (mat[i][j + 1] == 1 && j < m) {
    return 1;
  }
  return 0;
}
void FUSE() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char t;
      cin >> t;
      if (t == 'S')
        mat[i][j] = -1;
      else if (t == 'W')
        mat[i][j] = 1;
      else
        mat[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == -1 && check(i, j)) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == -1)
        cout << "S";
      else if (mat[i][j] == 1)
        cout << "W";
      else
        cout << "D";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) {
    FUSE();
  }
}
