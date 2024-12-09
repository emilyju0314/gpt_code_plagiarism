#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int x, y, z, t1, t2, t3, a, b;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  a = abs(x - y) * t1;
  b = (abs(z - x) + abs(x - y)) * t2 + t3 * 3;
  if (a < b)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
