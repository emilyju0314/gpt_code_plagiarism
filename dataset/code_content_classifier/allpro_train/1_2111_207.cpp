#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100000 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 1000 * 1000 * 1000;
const long long LINF = (1ll) << 60;
const double EPS = 1e-9, PI = 2. * acos(0.0);
int board[11][11];
int n, m, k;
int colCnt[11];
int all_colors;
int ans;
int banCol[11][11][11];
int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (a * 1ll * b) % MOD; }
void DFS(int x, int y) {
  int next_x = x;
  int next_y = y + 1;
  if (x == n) {
    int new_cols = -all_colors;
    for (int i = 0; i < k; i++) {
      if (colCnt[i] != 0) {
        new_cols++;
      }
    }
    int curAns = 1;
    for (int i = k - all_colors; i > k - all_colors - new_cols; i--) {
      curAns = mul(curAns, i);
    }
    ans = add(ans, curAns);
    return;
  }
  if (next_y == m) {
    next_x++;
    next_y = 0;
  }
  if (board[x][y] != 0) {
    DFS(next_x, next_y);
    return;
  }
  bool newOne = true;
  for (int i = 0; i < k; i++) {
    if (banCol[x][y][i] == 0) {
      if (colCnt[i] == 0) {
        if (newOne) {
          newOne = false;
        } else {
          continue;
        }
      }
      colCnt[i]++;
      for (int ii = x; ii < n; ii++) {
        for (int jj = y; jj < m; jj++) {
          banCol[ii][jj][i]++;
        }
      }
      DFS(next_x, next_y);
      colCnt[i]--;
      for (int ii = x; ii < n; ii++) {
        for (int jj = y; jj < m; jj++) {
          banCol[ii][jj][i]--;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) {
        if (banCol[i][j][board[i][j] - 1] != 0) {
          cout << 0 << "\n";
          return 0;
        }
        for (int ii = 0; ii < n; ii++) {
          for (int jj = 0; jj < m; jj++) {
            if (ii <= i && jj <= j || ii >= i && jj >= j) {
              banCol[ii][jj][board[i][j] - 1]++;
            }
          }
        }
        colCnt[board[i][j] - 1]++;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (colCnt[i] != 0) {
      all_colors++;
    }
  }
  DFS(0, 0);
  cout << ans << "\n";
  return 0;
}
