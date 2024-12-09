#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  bool tr = true;
  if (a < x) {
    tr = false;
  }
  if (a + b < x + y) {
    tr = false;
  }
  if (a + b + c < x + y + z) {
    tr = false;
  }
  if (tr == true) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
