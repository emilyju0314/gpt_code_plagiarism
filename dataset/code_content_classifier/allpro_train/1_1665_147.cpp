#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  if (n <= k) {
    cout << k - n << endl;
    return;
  }
  if (n % 2 != k % 2) {
    cout << 1 << endl;
    return;
  }
  cout << 0 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
