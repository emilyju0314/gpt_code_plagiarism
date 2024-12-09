#include <bits/stdc++.h>
using namespace std;
long long dis(int x1, int x2, int y1, int y2) {
  double res = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
  return res;
}
int main() {
  int x1, x2, y1, y2, x3 = 0, x4 = 0, y3 = 0, y4 = 0, a = 0, b = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  a = abs(x1 - x2);
  b = abs(y1 - y2);
  int l = dis(x1, x2, y1, y2);
  if ((x1 != x2) && (y1 != y2) && a == b) {
    x3 = x1;
    y3 = y2;
    x4 = x2;
    y4 = y1;
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
  } else if (x1 == x2) {
    y3 = y1;
    y4 = y2;
    x3 = x1 + b;
    x4 = x1 + b;
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
  } else if (y1 == y2) {
    x3 = x1;
    x4 = x2;
    y3 = y1 + a;
    y4 = y1 + a;
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
  } else
    cout << "-1";
  return 0;
}
