#include <bits/stdc++.h>
using namespace std;
char grid[50][50];
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool init = true, toggle;
  for (int i = 0; i < 50; i++) {
    if (a > 0 || c > 0 || d > 0) {
      if (i % 2 == 0) {
        for (int j = 0; j < 50; j++) {
          grid[i][j] = 'B';
        }
      } else {
        if (a > 0) {
          for (int j = 1; j < 50; j += 2) {
            grid[i][j] = 'B';
          }
          for (int j = 0; j < 50; j += 2) {
            if (a > 0) {
              grid[i][j] = 'A';
              a--;
            } else {
              grid[i][j] = 'B';
            }
          }
        } else if (c > 0) {
          for (int j = 1; j < 50; j += 2) {
            grid[i][j] = 'B';
          }
          for (int j = 0; j < 50; j += 2) {
            if (c > 0) {
              grid[i][j] = 'C';
              c--;
            } else {
              grid[i][j] = 'B';
            }
          }
        } else if (d > 0) {
          for (int j = 1; j < 50; j += 2) {
            grid[i][j] = 'B';
          }
          for (int j = 0; j < 50; j += 2) {
            if (d > 0) {
              grid[i][j] = 'D';
              d--;
            } else {
              grid[i][j] = 'B';
            }
          }
        }
      }
    } else if (b > 0) {
      if (init) {
        b--;
        int lastIdx = -1;
        for (int j = 0; j < 50; j++) {
          if (grid[i - 1][j] == 'D') lastIdx = j;
        }
        for (int j = lastIdx; j < 50; j++) {
          grid[i][j] = 'D';
        }
        for (int j = lastIdx - 1; j >= 0; j--) {
          grid[i][j] = 'B';
        }
        init = false;
        toggle = true;
      } else {
        if (toggle) {
          for (int j = 0; j < 50; j++) {
            grid[i][j] = 'D';
          }
        } else {
          for (int j = 0; j < 50; j += 2) {
            grid[i][j] = 'D';
          }
          for (int j = 1; j < 50; j += 2) {
            if (b > 0) {
              grid[i][j] = 'B';
              b--;
            } else {
              grid[i][j] = 'D';
            }
          }
        }
        toggle = !toggle;
      }
    } else {
      for (int j = 0; j < 50; j++) {
        grid[i][j] = 'D';
      }
    }
  }
  cout << "50 50" << endl;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}
