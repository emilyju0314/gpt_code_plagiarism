#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  double n, x, y;
  double v;
  cin >> n >> x >> y;
  if (((y - n + 1) * (y - n + 1) + n - 1) >= x && (y - n + 1) > 0) {
    i = y - n + 1;
    cout << i << endl;
    for (i = 0; i < n - 1; i++) {
      cout << "1" << endl;
    }
  } else
    cout << "-1" << endl;
  return 0;
}
