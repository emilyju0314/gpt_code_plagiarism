#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6][8] = {{3, 3, 0, 4, 4, 0, 3, 3}, {3, 3, 0, 4, 4, 0, 3, 3},
                 {2, 2, 0, 3, 3, 0, 2, 2}, {2, 2, 0, 3, 3, 0, 2, 2},
                 {1, 1, 0, 2, 2, 0, 1, 1}, {1, 1, 0, 2, 2, 0, 1, 1}};
  string s[6];
  for (int i = 0; i < 6; i++) {
    cin >> s[i];
  }
  int c = 0;
  pair<int, int> ans;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == '.' && a[i][j] > c) {
        ans = {i, j};
        c = a[i][j];
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      if (ans != make_pair(i, j)) {
        cout << s[i][j];
      } else {
        cout << 'P';
      }
    }
    cout << endl;
  }
  return 0;
}
