#include <bits/stdc++.h>
using namespace std;
int x, y, m, n, a[111], s[111], k, sz1, sz2;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> m;
  s[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  cin >> x >> y;
  for (int i = 1; i <= m; i++) {
    sz1 = s[i - 1];
    sz2 = s[m] - s[i - 1];
    if (sz1 >= x && sz1 <= y && sz2 >= x && sz2 <= y) {
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
