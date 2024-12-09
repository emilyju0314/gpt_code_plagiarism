#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool f = false;
  cin >> s;
  vector<vector<int>> v(4, vector<int>(4, 0));
  for (int i = 0; i < s.length(); i++) {
    f = false;
    if (s[i] == '0') {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 3; k++) {
          if (v[k][j] == 0 && v[k + 1][j] == 0) {
            v[k][j] = 1;
            v[k + 1][j] = 1;
            cout << k + 1 << " " << j + 1 << endl;
            if (v[0][j] == 1 && v[1][j] == 1 && v[2][j] == 1 && v[3][j] == 1) {
              v[0][j] = 0;
              v[1][j] = 0;
              v[2][j] = 0;
              v[3][j] = 0;
            }
            if (v[k][0] == 1 && v[k][1] == 1 && v[k][2] == 1 && v[k][3] == 1) {
              v[k][0] = 0;
              v[k][1] = 0;
              v[k][2] = 0;
              v[k][3] = 0;
            }
            if (v[k + 1][0] == 1 && v[k + 1][1] == 1 && v[k + 1][2] == 1 &&
                v[k + 1][3] == 1) {
              v[k + 1][0] = 0;
              v[k + 1][1] = 0;
              v[k + 1][2] = 0;
              v[k + 1][3] = 0;
            }
            f = true;
            break;
          }
        }
        if (f) break;
      }
    }
    if (s[i] == '1') {
      for (int k = 0; k < 4; k++) {
        for (int j = 0; j < 3; j++) {
          if (v[k][j] == 0 && v[k][j + 1] == 0) {
            v[k][j] = 1;
            v[k][j + 1] = 1;
            cout << k + 1 << " " << j + 1 << endl;
            if (v[k][0] == 1 && v[k][1] == 1 && v[k][2] == 1 && v[k][3] == 1) {
              v[k][0] = 0;
              v[k][1] = 0;
              v[k][2] = 0;
              v[k][3] = 0;
            }
            if (v[0][j] == 1 && v[1][j] == 1 && v[2][j] == 1 && v[3][j] == 1) {
              v[0][j] = 0;
              v[1][j] = 0;
              v[2][j] = 0;
              v[3][j] = 0;
            }
            if (v[0][j + 1] == 1 && v[1][j + 1] == 1 && v[2][j + 1] == 1 &&
                v[3][j + 1] == 1) {
              v[0][j + 1] = 0;
              v[1][j + 1] = 0;
              v[2][j + 1] = 0;
              v[3][j + 1] = 0;
            }
            f = true;
            break;
          }
        }
        if (f) break;
      }
    }
  }
  return 0;
}
