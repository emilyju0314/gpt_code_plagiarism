#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k, x, y, res = 0;
    cin >> n >> k >> x >> y;
    if (y < x) swap(x, y);
    while (k--)
      if (x > 1)
        x--;
      else if (y < n)
        y++;
    cout << y - x << '\n';
  }
}
