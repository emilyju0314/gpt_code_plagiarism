#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  if (r * c == 1) {
    cout << 0;
    exit(0);
  }
  if (r == 1) {
    for (int i = 0; i < c; i++) cout << i + 2 << ' ';
    cout << endl;
    exit(0);
  }
  if (c == 1) {
    for (int i = 0; i < r; i++) cout << i + 2 << ' ';
    cout << endl;
    exit(0);
  }
  for (int i = 1; i <= r; i++) {
    for (int j = r + 1; j <= r + c; j++) {
      cout << i * j << " ";
    }
    cout << endl;
  }
  return 0;
}
