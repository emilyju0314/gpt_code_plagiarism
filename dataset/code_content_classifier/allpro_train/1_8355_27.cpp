#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    if (t * (t + 1) / 2 == n) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
