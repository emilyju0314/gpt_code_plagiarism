#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, co;
  cin >> n;
  int arr[n + 2][n + 2];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      arr[i][j] = 1;
    }
  }
  co = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (arr[i][j] == 1) {
        arr[i - 1][j] = 2;
        arr[i + 1][j] = 2;
        arr[i][j + 1] = 2;
        arr[i][j - 1] = 2;
        co++;
      }
    }
  }
  cout << co << endl;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (arr[i][j] == 1) {
        cout << 'C';
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }
}
