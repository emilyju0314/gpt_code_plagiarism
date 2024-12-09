#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005];
int t = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int ii = 0; ii < 4; ++ii) {
        for (int jj = 0; jj < 4; ++jj) {
          a[i + ii][j + jj] = t++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
