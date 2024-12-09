#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, s;
  cin >> c >> s;
  int a, b;
  a = s / c;
  b = s % c;
  cout << a * a * c + 2 * a * b + b << '\n';
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
