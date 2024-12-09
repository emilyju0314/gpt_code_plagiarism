#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b, min = 1000000, t;
  int n;
  cin >> a >> b;
  cin >> n;
  cout.precision(8);
  for (int i = 0, x, y, v; i < n; i++) {
    cin >> x >> y >> v;
    t = sqrt((a - x) * (a - x) + (b - y) * (b - y)) / v;
    if (t < min) min = t;
  }
  cout << min;
  return 0;
}
