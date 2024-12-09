#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  if (x > y && x - y > z) {
    cout << "+";
    return 0;
  }
  if (x < y && y - x > z) {
    cout << "-";
    return 0;
  }
  if (x == y && z == 0) {
    cout << "0";
    return 0;
  }
  cout << "?";
  return 0;
}
