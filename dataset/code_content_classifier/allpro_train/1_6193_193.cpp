#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  char p;
  cin >> n >> m >> p;
  char c[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> c[i][j];
  }
  set<char> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (p == c[i][j]) {
        if (i == 0) {
          if (j == 0) {
            if (j + 1 < m) s.insert(c[i][j + 1]);
            if (i + 1 < n) s.insert(c[i + 1][j]);
          } else if (j == m - 1) {
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
            if (i + 1 < n) s.insert(c[i + 1][j]);
          } else {
            if (i + 1 < n) s.insert(c[i + 1][j]);
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
            if (j + 1 < m) s.insert(c[i][j + 1]);
          }
        } else if (i == n - 1) {
          if (j == 0) {
            if (j + 1 < m) s.insert(c[i][j + 1]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
          } else if (j == m - 1) {
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
          } else {
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
            if (j + 1 < m) s.insert(c[i][j + 1]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
          }
        } else {
          if (j == 0) {
            if (j + 1 < m) s.insert(c[i][j + 1]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
            if (i + 1 < n) s.insert(c[i + 1][j]);
          } else if (j == m - 1) {
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
            if (i + 1 < n) s.insert(c[i + 1][j]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
          } else {
            if (i + 1 < n) s.insert(c[i + 1][j]);
            if (i - 1 >= 0) s.insert(c[i - 1][j]);
            if (j + 1 < m) s.insert(c[i][j + 1]);
            if (j - 1 >= 0) s.insert(c[i][j - 1]);
          }
        }
      }
    }
  }
  s.erase('.');
  s.erase(p);
  cout << s.size();
  return 0;
}
