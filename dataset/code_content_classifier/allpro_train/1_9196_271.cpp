#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    if (n % 4 != 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i < n - 2; i += 2) cout << i << " ";
    cout << n + n / 2 - 1 << '\n';
  }
  return 0;
}
