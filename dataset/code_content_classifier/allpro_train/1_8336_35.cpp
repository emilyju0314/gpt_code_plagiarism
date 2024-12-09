#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b, c, d;
int main() {
  cin >> t;
  for (int h = 1; h <= t; h++) {
    cin >> n >> m;
    bool kt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a >> b >> c >> d;
      if (b == c) kt = 1;
    }
    if (m % 2 != 0)
      cout << "NO"
           << "\n";
    else {
      if (kt == 1)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
}
