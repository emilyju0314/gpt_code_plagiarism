#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c = 0;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i + j * j == m) {
        if (i * i + j == n) {
          c++;
        }
      }
    }
  }
  cout << c << endl;
}
