#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, max = 0, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    c += y - x;
    if (max < c) max = c;
  }
  cout << max << endl;
  return 0;
}
