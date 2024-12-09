#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, r;
  cin >> n >> r;
  double x = acos(-1) / n;
  double b = x / 2;
  double c = acos(-1) - x - b;
  double y = r * sin(b) / sin(c);
  double z = y * sin(x);
  double s = r * z * 0.5;
  cout << fixed << setprecision(24) << s * 2 * n;
  return 0;
}
