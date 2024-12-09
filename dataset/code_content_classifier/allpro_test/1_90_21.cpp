#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x == y)
      cout << x << endl;
    else if (x > y)
      cout << x + y << endl;
    else
      cout << y - y % x / 2 << endl;
  }
}
