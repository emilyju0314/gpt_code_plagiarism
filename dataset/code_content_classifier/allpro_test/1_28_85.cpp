#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (cin >> t; t--;) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c > 0)
      cout << 3 << endl;
    else if (a == 0 && b > 1 && c == 0)
      cout << 2 << endl;
    else {
      x = a + b * 2 + c * 3;
      cout << x % 2 << endl;
    }
  }
}
