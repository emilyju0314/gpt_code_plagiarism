#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x - y == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
