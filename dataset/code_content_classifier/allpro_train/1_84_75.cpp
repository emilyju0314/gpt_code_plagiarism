#include <bits/stdc++.h>
using namespace std;
long long int x2, y2, x3, y3;
bool check(long long int x, long long int y) {
  long long int xx = x3 * x3 + y3 * y3, tx = x2 + x, ty = y2 + y;
  if (xx == 0) return x == x2 && y == y2;
  long long int ret1 = tx * x3 + ty * y3, ret2 = tx * y3 - ty * x3;
  if (ret1 % xx != 0 || ret2 % xx != 0) return false;
  return true;
}
int main() {
  long long int x1, y1;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (check(x1, y1) || check(-x1, -y1) || check(-y1, x1) || check(y1, -x1))
    cout << "YES\n";
  else
    cout << "NO\n";
}
