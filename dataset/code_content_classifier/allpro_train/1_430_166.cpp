#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    long long x, y, k;
    cin >> x >> y >> k;
    long long mi = min(x, y), ma = max(x, y);
    if (ma > k) {
      cout << -1 << endl;
      continue;
    }
    if ((ma - mi) % 2 == 0) {
      int leftk = k - ma;
      cout << (leftk % 2 ? k - 2 : k) << endl;
    } else {
      cout << k - 1 << endl;
    }
  }
}
