#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int sm = 1;
    int bg = n;
    for (int i = n; i >= 1; i--) {
      if (i % 2 == 0)
        cout << sm++ << ' ';
      else
        cout << bg-- << ' ';
    }
    cout << "\n";
  }
  return 0;
}
