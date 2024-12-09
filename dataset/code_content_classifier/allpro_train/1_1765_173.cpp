#include <bits/stdc++.h>
using namespace std;
int n;
int a[200][200];
int main() {
  cin >> n;
  if (n % 2) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i)
    if ((i / 2) % 2)
      a[0][i] = 1;
    else
      a[0][i] = 0;
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < n; ++j) a[i][j] = a[i - 1][j] ^ 1;
  for (int k = 0; k < n / 2; ++k) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) a[i][j] ^= 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << ((a[i][j] == 1) ? "b" : "w");
      cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << ((a[i][j] == 1) ? "b" : "w");
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
