#include <bits/stdc++.h>
using namespace std;
int a[3][3], b[3][3], i, j;
int main() {
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  b[0][0] = a[0][0] + a[0][1] + a[1][0];
  b[0][1] = a[0][0] + a[0][1] + a[0][2] + a[1][1];
  b[0][2] = a[0][1] + a[0][2] + a[1][2];
  b[1][0] = a[1][0] + a[0][0] + a[2][0] + a[1][1];
  b[1][1] = a[1][0] + a[1][1] + a[1][2] + a[0][1] + a[2][1];
  b[1][2] = a[1][1] + a[1][2] + a[0][2] + a[2][2];
  b[2][0] = a[2][0] + a[2][1] + a[1][0];
  b[2][1] = a[2][0] + a[2][1] + a[1][1] + a[2][2];
  b[2][2] = a[2][1] + a[2][2] + a[1][2];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) cout << (b[i][j] % 2 ? 0 : 1);
    cout << endl;
  }
  return 0;
}