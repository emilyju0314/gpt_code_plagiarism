#include <bits/stdc++.h>
using namespace std;
char sign[1000][1000], cpy[1000][1000];
int n, m;
void tryFill(int i, int j) {
  for (int ii = i - 1; ii <= i + 1; ii++) {
    for (int jj = j - 1; jj <= j + 1; jj++) {
      if (i == ii && j == jj) {
        continue;
      }
      if (sign[ii][jj] == '.') {
        return;
      }
    }
  }
  for (int ii = i - 1; ii <= i + 1; ii++) {
    for (int jj = j - 1; jj <= j + 1; jj++) {
      if (i == ii && j == jj) {
        continue;
      }
      cpy[ii][jj] = '#';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> sign[i][j];
      cpy[i][j] = '.';
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      tryFill(i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (sign[i][j] != cpy[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
