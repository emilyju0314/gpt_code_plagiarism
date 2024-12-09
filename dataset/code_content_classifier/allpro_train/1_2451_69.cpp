#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        cout << 1;
      else if (abs(i - j) == 1)
        cout << 1;
      else
        cout << 0;
      if (j == n - 1)
        cout << endl;
      else
        cout << " ";
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
