#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> mat;
bool good(int i, int j) {
  if (i < 1 || i >= n - 1 || j < 1 || j >= m - 1) {
    return true;
  }
  return !((mat[i - 1][j] == '#' && mat[i + 1][j] == '#') ||
           (mat[i][j - 1] == '#' && mat[i][j + 1] == '#'));
}
vector<int> xx = {-1, 0, 1, 0};
vector<int> yy = {0, -1, 0, 1};
void dfs(int x, int y, vector<vector<bool>>& visited) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    if (0 <= x + xx[i] && x + xx[i] < n && 0 <= y + yy[i] && y + yy[i] < m &&
        mat[x + xx[i]][y + yy[i]] == '#' && !visited[x + xx[i]][y + yy[i]]) {
      dfs(x + xx[i], y + yy[i], visited);
    }
  }
}
void solve() {
  cin >> n >> m;
  mat.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  bool ok = true;
  bool no_black = true;
  int cnt_row = 0;
  for (int i = 0; i < n; i++) {
    int b = 0;
    int cnt_b = 0;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') {
        b++;
        no_black = false;
      } else {
        if (b) {
          cnt_b++;
        }
        b = 0;
      }
    }
    if (b) {
      cnt_b++;
    }
    if (cnt_b > 1) {
      ok = false;
      break;
    }
    if (cnt_b == 0) {
      cnt_row++;
    }
  }
  int cnt_col = 0;
  for (int j = 0; j < m; j++) {
    int b = 0;
    int cnt_b = 0;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '#') {
        b++;
      } else {
        if (b) {
          cnt_b++;
        }
        b = 0;
      }
    }
    if (b) {
      cnt_b++;
    }
    if (cnt_b > 1) {
      ok = false;
      break;
    }
    if (cnt_b == 0) {
      cnt_col++;
    }
  }
  if (no_black) {
    cout << 0 << '\n';
    return;
  }
  if (n == 1) {
    int c = 0;
    for (int i = 0; i < m; i++) {
      if (mat[0][i] == '#') {
        c++;
      }
    }
    if (c == m) {
      cout << c << '\n';
    } else {
      cout << -1 << '\n';
    }
    return;
  } else if (m == 1) {
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (mat[i][0] == '#') {
        c++;
      }
    }
    if (c == n) {
      cout << c << '\n';
    } else {
      cout << -1 << '\n';
    }
    return;
  }
  if (!ok || (min(cnt_row, cnt_col) == 0) && max(cnt_row, cnt_col) > 0) {
    cout << -1 << '\n';
  } else {
    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == '#' && !visited[i][j]) {
          dfs(i, j, visited);
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  solve();
  return 0;
}
