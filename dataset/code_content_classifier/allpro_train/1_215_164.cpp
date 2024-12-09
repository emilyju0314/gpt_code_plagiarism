#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[4][4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == 'x') {
        if (j < 2 && a[i][j + 1] == 'x' && a[i][j + 2] == '.') {
          cout << "YES";
          return 0;
        }
        if (j >= 2 && a[i][j - 1] == 'x' && a[i][j - 2] == '.') {
          cout << "YES";
          return 0;
        }
        if (i < 2 && a[i + 1][j] == 'x' && a[i + 2][j] == '.') {
          cout << "YES";
          return 0;
        }
        if (i >= 2 && a[i - 1][j] == 'x' && a[i - 2][j] == '.') {
          cout << "YES";
          return 0;
        }
        if (i >= 2) {
          if (j >= 2 && a[i - 1][j - 1] == 'x' && a[i - 2][j - 2] == '.') {
            cout << "YES";
            return 0;
          }
          if (j < 2 && a[i - 1][j + 1] == 'x' && a[i - 2][j + 2] == '.') {
            cout << "YES";
            return 0;
          }
        }
        if (i < 2) {
          if (j >= 2 && a[i + 1][j - 1] == 'x' && a[i + 2][j - 2] == '.') {
            cout << "YES";
            return 0;
          }
          if (j < 2 && a[i + 1][j + 1] == 'x' && a[i + 2][j + 2] == '.') {
            cout << "YES";
            return 0;
          }
        }
        if (j < 2 && a[i][j + 1] == '.' && a[i][j + 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (j >= 2 && a[i][j - 1] == '.' && a[i][j - 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i < 2 && a[i + 1][j] == '.' && a[i + 2][j] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i >= 2 && a[i - 1][j] == '.' && a[i - 2][j] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i >= 2) {
          if (j >= 2 && a[i - 1][j - 1] == '.' && a[i - 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (j < 2 && a[i - 1][j + 1] == '.' && a[i - 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i < 2) {
          if (j >= 2 && a[i + 1][j - 1] == '.' && a[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (j < 2 && a[i + 1][j + 1] == '.' && a[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO";
}
