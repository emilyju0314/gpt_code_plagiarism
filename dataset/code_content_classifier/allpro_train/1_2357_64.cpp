#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010][1010];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = (i + j) % n + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i][n] = a[n][i] = a[i][i];
    a[i][i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
