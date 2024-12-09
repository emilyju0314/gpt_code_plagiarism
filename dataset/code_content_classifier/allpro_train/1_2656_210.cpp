#include <bits/stdc++.h>
using namespace std;
string arr[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 9; i++) {
    arr[i] = '000000000000000000000000000';
    for (int j = 0; j < 9; j++) {
      cin >> arr[i][j];
    }
  }
  int x, y;
  cin >> y >> x;
  x--;
  y--;
  int row = 3 * (y % 3);
  int col = (x % 3) * 3;
  bool fndok = false;
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      if (arr[i][j] == '.') {
        fndok = true;
        arr[i][j] = '!';
      }
    }
  }
  if (!fndok) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (arr[i][j] == '.') arr[i][j] = '!';
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << arr[i][j];
      if ((j + 1) % 3 == 0) cout << " ";
    }
    if ((i + 1) % 3 == 0) cout << endl;
    cout << endl;
  }
  return 0;
}
