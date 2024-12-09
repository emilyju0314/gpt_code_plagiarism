#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  int f = 0;
  int x = 0;
  int y = 0;
  for (int i = 0; i < 4; i++) {
    if (a[i][0] == a[i][2]) {
      x++;
      if (a[i][1] != a[i][3])
        continue;
      else {
        f = 1;
        break;
      }
    }
    if (a[i][1] == a[i][3]) {
      y++;
      if (a[i][0] != a[i][2])
        continue;
      else {
        f = 1;
        break;
      }
    }
  }
  if (f) {
    cout << "NO" << endl;
    return 0;
  }
  if (!(x == 2 && y == 2)) {
    cout << "NO" << endl;
    return 0;
  }
  map<pair<int, int>, int> dp;
  for (int i = 0; i < 4; i++) {
    dp[{a[i][0], a[i][1]}]++;
    dp[{a[i][2], a[i][3]}]++;
  }
  f = 0;
  for (auto x : dp) {
    if (x.second != 2) {
      f = 1;
      break;
    }
  }
  if (f) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
