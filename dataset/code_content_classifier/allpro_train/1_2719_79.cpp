#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int p = (m * (m - 1)) / 2;
  cout << p << "\n";
  if (!k) {
    for (int i = 1; i <= m; i++) {
      for (int j = i + 1; j <= m; j++) {
        cout << i << " " << j << "\n";
      }
    }
  } else {
    for (int i = m; i >= 1; i--) {
      for (int j = i - 1; j >= 1; j--) {
        cout << i << " " << j << "\n";
      }
    }
  }
}
