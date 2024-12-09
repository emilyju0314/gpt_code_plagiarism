#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1][n + 1];
  int j = 1, k = 1;
  while (k <= n * n) {
    if (j % 2) {
      for (int l = 1; l <= n; l++) {
        a[l][j] = k;
        k++;
      }
    } else {
      for (int l = n; l > 0; l--) {
        a[l][j] = k;
        k++;
      }
    }
    j++;
  }
  for (int i = int(1); i <= int(n); i++) {
    for (int j = int(1); j <= int(n); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
