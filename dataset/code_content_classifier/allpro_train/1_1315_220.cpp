#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, y = 0, z;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> z;
    if (z == 1) {
      x++;
    } else {
      y++;
    }
  }
  if (y != 0) {
    cout << "2 ";
    y--;
  }
  if (x != 0) {
    cout << "1 ";
    x--;
  }
  for (int i = 0; i < y; i++) {
    cout << "2 ";
  }
  for (int i = 0; i < x; i++) {
    cout << "1 ";
  }
  return 0;
}
