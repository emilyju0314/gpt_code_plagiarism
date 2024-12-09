#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n, m;
  cin >> n >> m;
  if ((n * m) % 2 != 0) {
    char x = 'B';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << x;
        if (x == 'B')
          x = 'W';
        else
          x = 'B';
      }
      cout << endl;
    }
    return;
  } else {
    char x = 'B';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 1) {
          cout << "B";
          x = 'W';
          j++;
          if (j == m) break;
        }
        cout << x;
        if (x == 'B')
          x = 'W';
        else
          x = 'B';
      }
      if (m % 2 == 0)
        x = 'B';
      else {
        if (i == 1) x = 'B';
      }
      cout << endl;
    }
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
