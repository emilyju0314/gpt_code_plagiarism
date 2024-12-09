#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const long long MOD = 1e9 + 7;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  if (a > b) {
    if ((a - b) % 2 == 0) {
      cout << 1 << "\n";
      return;
    } else {
      cout << 2 << "\n";
      return;
    }
  }
  if (a < b) {
    if ((b - a) % 2 == 1) {
      cout << 1 << "\n";
      return;
    } else {
      cout << 2 << "\n";
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
