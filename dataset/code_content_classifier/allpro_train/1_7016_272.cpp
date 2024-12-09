#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int y, b, r;
  cin >> y >> b >> r;
  if (b >= y + 1 && r >= y + 2)
    cout << 3 * y + 3 << endl;
  else if (y >= b - 1 && r >= b + 1)
    cout << 3 * b << endl;
  else if (b >= r - 1 && y >= r - 2)
    cout << 3 * r - 3 << endl;
  return 0;
}
