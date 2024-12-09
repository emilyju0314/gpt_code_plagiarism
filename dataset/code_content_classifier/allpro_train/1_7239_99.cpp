#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x, y;
  cin >> x >> y;
  if ((a - c) % x != 0 || (b - d) % y != 0) {
    cout << "NO";
  } else {
    if (abs((abs(a - c) / x) - (abs(b - d) / y)) % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
