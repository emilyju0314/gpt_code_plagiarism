#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (i % 2 != 0) {
        cout << "#";
      } else if ((i / 2) % 2 != 0 && j == m) {
        cout << "#";
      } else if ((i / 2) % 2 == 0 && j == 1) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
