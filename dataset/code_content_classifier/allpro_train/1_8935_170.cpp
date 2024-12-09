#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, x, i, value;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> a;
    int odd = 0;
    for (i = 0; i < n; i++) {
      cin >> value;
      a.push_back(value);
    }
    for (i = 0; i < a.size(); i++) {
      if (a[i] % 2 == 1) odd++;
    }
    if (x == n) {
      if (odd % 2 == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (x % 2 == 0) {
        if (odd >= 1 && odd != n)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
      if (x % 2 == 1) {
        if (odd >= 1)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
  return 0;
}
